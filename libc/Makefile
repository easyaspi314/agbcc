# Prefer the faster mksh over Bash, we just need pipefail
ifneq (,$(shell command -v mksh || true))
SHELL := mksh -o pipefail
# Android's /system/bin/sh is also mksh
else ifneq (,$(wildcard /system/bin/sh))
SHELL := /system/bin/sh -o pipefail
# otherwise, use Bash.
else ifneq (,$(shell command -v bash || true))
SHELL := bash -o pipefail
endif

ASFLAGS := -mcpu=arm7tdmi

CC1    := ../old_agbcc
CFLAGS := -O2 -fno-builtin -std=gnu99
AR     := ../binutils/ar
AS     := ../gas/as-new
CPP    := $(CC) -E

CPPFLAGS := -I ../ginclude -I include -nostdinc -undef \
    -DABORT_PROVIDED -DHAVE_GETTIMEOFDAY -D__thumb__ -DARM_RDI_MONITOR \
    -D__GNUC__ -DINTERNAL_NEWLIB -D__USER_LABEL_PREFIX__=


# Clear the default suffixes.
.SUFFIXES:

# Secondary expansion is required for dependency variables in object rules.
.SECONDEXPANSION:

.PHONY: all clean

C_SRCS := $(shell find . -iname "*.c" -a ! -iname "mallocr.c")
C_OBJS := $(C_SRCS:%.c=%.o)
C_ASMS := $(C_SRCS:%.c=%.s)

MALLOC_OBJS := stdlib/mallocr.o stdlib/freer.o stdlib/reallocr.o stdlib/callocr.o \
stdlib/cfreer.o stdlib/malignr.o stdlib/vallocr.o stdlib/pvallocr.o \
stdlib/mallinfor.o stdlib/mallstatsr.o stdlib/msizer.o stdlib/malloptr.o \
stdio/vfiprintf.o
MALLOC_ASMS := $(MALLOC_OBJS:%.o=%.s)

S_SRCS := arm/setjmp.s arm/trap.s
S_OBJS := $(S_SRCS:%.s=%.o)

OBJS := $(C_OBJS) $(MALLOC_OBJS) $(S_OBJS)
BUILD_ASMS := $(MALLOC_ASMS) $(C_ASMS)
all: libc.a
	@:

clean:
	rm -f $(OBJS)
	rm -f $(BUILD_ASMS)
	rm -f $(S_OBJS:%.o=%.i)
	rm -f libc.a

PREPROCESS := $(CPP) $(CPPFLAGS)

stdlib/mallocr.s: PREPROCESS += -DDEFINE_MALLOC
stdlib/freer.s: PREPROCESS += -DDEFINE_FREE
stdlib/reallocr.s: PREPROCESS += -DDEFINE_REALLOC
stdlib/callocr.s: PREPROCESS += -DDEFINE_CALLOC
stdlib/cfreer.s:  PREPROCESS += -DDEFINE_CFREE
stdlib/malignr.s: PREPROCESS += -DDEFINE_MEMALIGN
stdlib/vallocr.s: PREPROCESS += -DDEFINE_VALLOC
stdlib/pvallocr.s: PREPROCESS += -DDEFINE_PVALLOC
stdlib/mallinfor.s: PREPROCESS += -DDEFINE_MALLINFO
stdlib/mallstatsr.s: PREPROCESS += -DDEFINE_MALLOC_STATS
stdlib/msizer.s: PREPROCESS += -DDEFINE_MALLOC_USABLE_SIZE
stdlib/malloptr.s: PREPROCESS += -DDEFINE_MALLOPT
stdio/vfiprintf.s: PREPROCESS += -DINTEGER_ONLY

stdlib/mbtowc_r.s: CFLAGS := $(CFLAGS) -fshort-enums

$(MALLOC_ASMS): stdlib/mallocr.c
	$(PREPROCESS) $< | $(CC1) $(CFLAGS) -o $@

$(C_OBJS) $(MALLOC_OBJS): %.o : %.s
	$(AS) $(ASFLAGS) $< -o $@

$(C_ASMS): %.s: %.c
	$(PREPROCESS) $< | $(CC1) $(CFLAGS) -o $@

$(S_OBJS): %.o: %.s
	@$(CPP) $(CPPFLAGS) -x c -P $< -o $*.i
	@printf ".text\n\t.align\t2, 0\n" >> $*.i
	$(AS) $(ASFLAGS) -o $@ $*.i

libc.a: $(OBJS)
	$(AR) -rc libc.a $(OBJS)

# A partial build step that builds .s files and doesn't need gas.
asms: $(BUILD_ASMS)

# A partial build step that builds .o files and doesn't need ar.
objs: $(OBJS)
