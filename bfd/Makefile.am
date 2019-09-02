## Process this file with automake to generate Makefile.in
#
#   Copyright (C) 2012-2018 Free Software Foundation, Inc.
#
# This file is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; see the file COPYING3.  If not see
# <http://www.gnu.org/licenses/>.
#

AUTOMAKE_OPTIONS := no-dependencies no-dist foreign
ACLOCAL_AMFLAGS := -I . -I .. -I ../config

INCDIR = $(srcdir)/../include
CSEARCH = -I. -I$(srcdir) -I$(INCDIR)

noinst_LIBRARIES = libbfd.a

bfddocdir =

BFD_H = bfd.h

# Empty these so that the respective installation directories will not be created.
bfdlibdir =
bfdincludedir =
bfdinclude_HEADERS =
rpath_bfdlibdir = @bfdlibdir@

WARN_CFLAGS = -Wall
NO_WERROR =
AM_CFLAGS = $(WARN_CFLAGS)
AM_CPPFLAGS = -DBINDIR='"$(bindir)"'
COMPILE = $(CC) $(CFLAGS) $(AM_CPPFLAGS) $(AM_CFLAGS)

# Jim Kingdon notes:
# Writing S-records should be included in all (or at least most)
# *-*-coff, *-*-aout, etc., configurations, because people will want to
# be able to use objcopy to create S-records.  (S-records are not useful
# for the debugger, so if you are downloading things as S-records you
# need two copies of the executable, one to download and one for the
# debugger).
BFD32_LIBS = \
	arm-dis.o archive.o archures.o bfd.o bfdio.o bfdwin.o \
	cache.o compress.o corefile.o disassemble.o \
	dis-buf.o dis-init.o format.o hash.o \
	init.o libbfd.o linker.o merge.o opncls.o reloc.o \
	section.o simple.o syms.o targets.o \
	binary.o

BFD32_LIBS_CFILES = \
	arm-dis.c archive.c archures.c bfd.c bfdio.c bfdwin.c \
	cache.c  compress.c corefile.c disassemble.c \
	dis-buf.c dis-init.c format.c hash.c \
	init.c libbfd.c linker.c merge.c opncls.c reloc.c \
	section.c simple.c syms.c targets.c \
	binary.c

# This list is alphabetized to make it easier to keep in sync
# with the decls and initializer in archures.c.
ALL_MACHINES = \
	cpu-arm.o
ALL_MACHINES_CFILES = \
	cpu-arm.c

# The .o files needed by all of the 32 bit vectors that are configured into
# target_vector in targets.c if configured with --enable-targets=all.
BFD32_BACKENDS = \
	dwarf1.o \
	dwarf2.o \
	elf-attrs.o \
	elf-eh-frame.o \
	elf-properties.o \
	elf-strtab.o \
	elf.o \
	elf32-arm.o \
	elf32.o \
	elflink.o \
	reloc16.o

BFD32_BACKENDS_CFILES = \
	arm-dis.c \
	dwarf1.c \
	dwarf2.c \
	elf-attrs.c \
	elf-eh-frame.c \
	elf-properties.c \
	elf-strtab.c \
	elf.c \
	elf32-arm.c \
	elf32.c \
	elflink.c \
	reloc16.c

# The .o files needed by all of the 64 bit vectors that are configured into
# target_vector in targets.c if configured with --enable-targets=all
# and --enable-64-bit-bfd.
# elf32-ia64.c requires a 64-bit bfd_vma, and hence can not be put in
# BFD32_BACKENDS.

OPTIONAL_BACKENDS =
OPTIONAL_BACKENDS_CFILES =

# Reconfigure if config.bfd or configure.host changes.
# development.sh is used to determine -Werror default.
CONFIG_STATUS_DEPENDENCIES = \
	$(srcdir)/config.bfd \
	$(srcdir)/configure.host \
	$(srcdir)/development.sh

# These are no longer defined by configure:
ALL_BACKENDS = $(BFD32_BACKENDS)
BFD_BACKENDS =  elf32-arm.o elf32.o elf.o elflink.o elf-attrs.o elf-strtab.o elf-properties.o elf-eh-frame.o dwarf1.o dwarf2.o elf32-gen.o
BFD_MACHINES =  cpu-arm.o
TDEFAULTS =  -DDEFAULT_VECTOR=arm_elf32_le_vec -DSELECT_VECS='&arm_elf32_le_vec,&arm_elf32_fdpic_le_vec,&elf32_le_vec' -DSELECT_ARCHITECTURES='&bfd_arm_arch'
HAVEVECS = -DHAVE_arm_elf32_le_vec -DHAVE_arm_elf32_fdpic_le_vec -DHAVE_elf32_le_vec

AM_CPPFLAGS += @HDEFINES@ @TDEFINES@ $(CSEARCH) $(CSWITCHES) \
	$(HAVEVECS)

# C source files that correspond to .o's.
SOURCE_CFILES = \
	$(BFD32_LIBS_CFILES) \
	$(ALL_MACHINES_CFILES) \
	$(BFD32_BACKENDS_CFILES) \
	$(OPTIONAL_BACKENDS_CFILES)

BUILD_CFILES =
CFILES = $(SOURCE_CFILES) $(BUILD_CFILES)

## This is a list of all .h files which are in the source tree.
SOURCE_HFILES = \
	bfd.h \
	bfdver.h \
	elf-bfd.h  \
	elfcode.h elfcore.h \
	genlink.h \
	libbfd.h \
	opintl.h \
	version.h
	targmatch.h

BUILD_HFILES =

# Ensure they are built early:
BUILT_SOURCES = $(BUILD_HFILES)

HFILES = $(SOURCE_HFILES) $(BUILD_HFILES)


# Various kinds of .o files to put in libbfd.a:
# BFD_BACKENDS	Routines the configured targets need.
# BFD_MACHINES	Architecture-specific routines the configured targets need.
OFILES = $(BFD_BACKENDS) $(BFD_MACHINES)

stamp-ofiles: Makefile
	rm -f tofiles
	f=""; \
	for i in $(OFILES) ; do \
	  case " $$f " in \
	    *" $$i "*) ;; \
	    *) f="$$f $$i" ;; \
	  esac ; \
	done ; \
	echo $$f > tofiles
	$(SHELL) $(srcdir)/../config/move-if-change tofiles ofiles
	touch stamp-ofiles

ofiles: stamp-ofiles ; @true

# Since BFD64_LIBS is optional and we can't have substitution in
# libbfd_la_SOURCES, we put BFD64_LIBS in OFILES instead.
# However, list all sources in EXTRA_libbfd_la_SOURCES so the
# dependency tracking fragments are picked up in the Makefile.
libbfd_a_SOURCES = $(BFD32_LIBS_CFILES)
EXTRA_libbfd_a_SOURCES = $(CFILES)
libbfd_a_DEPENDENCIES = $(OFILES) ofiles
libbfd_a_LIBADD = `cat ofiles` $(LIBDL)

# When compiling archures.c and targets.c, supply the default target
# info from configure.

targets.o: targets.c Makefile
	$(COMPILE) -c -o $@ $(TDEFAULTS) $(srcdir)/targets.c

archures.o: archures.c Makefile
	$(COMPILE) -c -o $@ $(TDEFAULTS) $(srcdir)/archures.c

$(ofiles): %.o: %.c Makefile
dwarf2.o: dwarf2.c Makefile
	$(COMPILE) -c -o $@ -DDEBUGDIR=\"$(libdir)/debug\" $(srcdir)/dwarf2.c

BFD_H_DEPS= $(INCDIR)/ansidecl.h $(INCDIR)/symcat.h
LOCAL_H_DEPS= libbfd.h sysdep.h ../include/config.h
$(BFD32_LIBS) \
 $(ALL_MACHINES) \
 $(BFD32_BACKENDS) \
 $(OPTIONAL_BACKENDS): $(BFD_H) $(BFD_H_DEPS) $(LOCAL_H_DEPS)

host-aout.o: Makefile

# The following program can be used to generate a simple config file
# which can be folded into an h-XXX file for a new host, with some editing.
aout-params.h: gen-aout
	./gen-aout host > aout-params.h
gen-aout: $(srcdir)/gen-aout.c Makefile
	$(CC) -o gen-aout $(CFLAGS) $(LFLAGS) $(srcdir)/gen-aout.c

BFD_H_FILES = bfd-in.h init.c opncls.c libbfd.c \
	bfdio.c bfdwin.c section.c archures.c reloc.c \
	bfd.c archive.c corefile.c targets.c format.c \
	linker.c simple.c syms.c compress.c

LIBBFD_H_FILES = libbfd-in.h libbfd.c bfdio.c bfdwin.c \
	cache.c reloc.c archures.c linker.c

MOSTLYCLEANFILES = ofiles stamp-ofiles

CLEANFILES = dep.sed DEP DEPA DEP1 DEP2 libbfd.a stamp-lib \
	stmp-bin2-h stmp-lbfd-h

DISTCLEANFILES = $(BUILD_CFILES) $(BUILD_HFILES)

# A helper that only builds the object files, without linking.
objs: $(OFILES) ofiles $(libbfd_a_OBJECTS)
.PHONY: objs
