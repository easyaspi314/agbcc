dnl Process this file with autoconf to produce a configure script.
dnl
dnl   Copyright (C) 2012-2018 Free Software Foundation, Inc.
dnl
dnl This file is free software; you can redistribute it and/or modify
dnl it under the terms of the GNU General Public License as published by
dnl the Free Software Foundation; either version 3 of the License, or
dnl (at your option) any later version.
dnl
dnl This program is distributed in the hope that it will be useful,
dnl but WITHOUT ANY WARRANTY; without even the implied warranty of
dnl MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
dnl GNU General Public License for more details.
dnl
dnl You should have received a copy of the GNU General Public License
dnl along with this program; see the file COPYING3.  If not see
dnl <http://www.gnu.org/licenses/>.
dnl

m4_include([bfd/version.m4])
AC_INIT([binutils], BFD_VERSION)
AC_CONFIG_AUX_DIR([config])
m4_include([config/lean.m4])

AC_CONFIG_SRCDIR(install.sh)

AC_CANONICAL_TARGET


AC_CANONICAL_BUILD
AM_INIT_AUTOMAKE([no-dependencies foreign])
AM_MAINTAINER_MODE([disable])
AC_PROG_CC
AC_PROG_SED

AC_USE_SYSTEM_EXTENSIONS

AC_SYS_LARGEFILE

AC_CONFIG_HEADERS(include/config.h:include/config.in)

AC_EXEEXT

HDEFINES=

. ${srcdir}/bfd/configure.host

AC_SUBST(HDEFINES)
AC_PROG_INSTALL

BFD_CC_FOR_BUILD

AC_CHECK_SIZEOF([long])
AC_CHECK_SIZEOF([size_t])
AC_CHECK_HEADERS_ONCE([sys/file.h fcntl.h stdio_ext.h malloc.h strings.h sys/param.h sys/time.h unistd.h utime.h memory.h strings.h sys/types.h sys/stat.h])

ACX_HEADER_STRING
AC_CHECK_FUNCS_ONCE([getpagesize mkdir rmdir stpcpy utime])

AC_CHECK_FUNC([mkstemp],
	      AC_DEFINE([HAVE_MKSTEMP], 1,
	      [Define to 1 if you have the `mkstemp' function.]))
AC_CHECK_FUNC([mkdtemp],
              AC_DEFINE([HAVE_MKDTEMP], 1,
              [Define to 1 if you have the `mkdtemp' function.]))

if test $ac_cv_header_utime_h = yes; then
  AC_DEFINE(HAVE_GOOD_UTIME_H, 1, [Does <utime.h> define struct utimbuf?])
fi

AC_CHECK_DECLS([stpcpy])


all_targets=false
OBJDUMP_DEFS=
OBJDUMP_PRIVATE_VECTORS=
OBJDUMP_PRIVATE_OFILES=
od_vectors=

# Uniq objdump private vector, build objdump target ofiles.
od_files=
f=""
for i in $od_vectors ; do
    case " $f " in
    *" $i "*) ;;
    *)
	f="$f $i"
	OBJDUMP_PRIVATE_VECTORS="$OBJDUMP_PRIVATE_VECTORS &$i,"

	AC_MSG_ERROR(*** unknown private vector $i)
	;;
    esac
done

# Uniq objdump target ofiles
f=""
for i in $od_files ; do
    case " $f " in
    *" $i "*) ;;
    *)
	f="$f $i"
	OBJDUMP_PRIVATE_OFILES="$OBJDUMP_PRIVATE_OFILES $i.$objext"
	;;
    esac
done


OBJDUMP_DEFS="${OBJDUMP_DEFS} -DOBJDUMP_PRIVATE_VECTORS=\"${OBJDUMP_PRIVATE_VECTORS}\""

AC_SUBST(BUILD_INSTALL_MISC)
AC_SUBST(OBJDUMP_DEFS)
AC_SUBST(OBJDUMP_PRIVATE_OFILES)

AC_DEFINE_UNQUOTED(TARGET, "${target}", [Configured target name.])

targ=armv4tl-none-eabi
. $srcdir/bfd/config.bfd

. ${srcdir}/binutils/configure.tgt
EMULATION=$targ_emul
EMULATION_VECTOR=$targ_emul_vector

AC_SUBST(EMULATION)
AC_SUBST(EMULATION_VECTOR)

AC_CONFIG_MACRO_DIRS([config])

#We need this for the host.
AC_C_BIGENDIAN

te_file=generic

# Makefile target for installing gas in $(tooldir)/bin.
install_tooldir=install-exec-tooldir

all_targets=no

targ=armv4tl-none-eabi

cpu=armv4tl
cpu_type=arm
em=armeabi
endian=little
fmt=elf
generic_target=arm-none-eabi
os=eabi
vendor=none
obj_format=elf
te_file=armeabi

# Getting this done right is going to be a bitch.  Each configuration specified
# with --enable-targets=... should be checked for environment, format, cpu
# setting.
#
# For each configuration, the necessary object file support code must be linked
# in.  This might be only one, it might be up to four.  The necessary emulation
# code needs to be provided, too.
#
# And then there's "--enable-targets=all"....
#
# For now, just always do it for MIPS ELF configurations.  Sigh.

formats="${obj_format}"
emfiles=""
EMULATIONS=""
GAS_UNIQ(emulations)
for em in . $emulations ; do
  fmt=elf
  file=$em
  formats="$formats $fmt"
  emfiles="$emfiles gas/config/e-$file.o"
  EMULATIONS="$EMULATIONS &$em,"
done
GAS_UNIQ(formats)
GAS_UNIQ(emfiles)
if test `set . $formats ; shift ; echo $#` -gt 1 ; then
  for fmt in $formats ; do
    case $fmt in
      elf)	AC_DEFINE(OBJ_MAYBE_ELF, 1,     [ELF support?])     ;;
      generic)	AC_DEFINE(OBJ_MAYBE_GENERIC, 1, [generic support?]) ;;
    esac
    extra_objects="$extra_objects config/obj-$fmt.o"
  done
  obj_format=multi
fi
if test `set . $emfiles ; shift ; echo $#` -gt 0 ; then
  DEFAULT_EMULATION=`set . $emulations ; echo $2`
fi
AC_SUBST(extra_objects)
AC_DEFINE_UNQUOTED(EMULATIONS, $EMULATIONS, [Supported emulations.])

AC_SUBST(te_file)
AC_SUBST(install_tooldir)

AC_DEFINE_UNQUOTED(TARGET_CPU,		"${target_cpu}",   [Target CPU.])
AC_DEFINE_UNQUOTED(TARGET_VENDOR,	"${target_vendor}", [Target vendor.])
AC_DEFINE_UNQUOTED(TARGET_OS,		"${target_os}",    [Target OS.])

# VMS doesn't have unlink.
AC_CHECK_FUNCS(unlink remove, break)

# On some systems, the system header files may not declare malloc, realloc,
# and free.  There are places where gas needs these functions to have been
# declared -- such as when taking their addresses.
gas_test_headers="
#ifdef HAVE_MEMORY_H
#include <memory.h>
#endif
#include <string.h>
#endif
#include <stdlib.h>
#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif
"

dnl This must come last.

dnl We used to make symlinks to files in the source directory, but now
dnl we just use the right name for .c files, and create .h files in
dnl the build directory which include the right .h file.  Make sure
dnl the old symlinks don't exist, so that a reconfigure in an existing
dnl directory behaves reasonably.



# This works around the fact that libtool configuration may change LD
# for this particular configuration, but some shells, instead of
# keeping the changes in LD private, export them just because LD is
# exported.  We don't use libtool yet, but some day we might, so...
ORIGINAL_LD_FOR_MULTILIBS=$LD

libiberty_topdir="${srcdir}"
with_target_subdir=
AC_SUBST(libiberty_topdir)


dnl## These must be called before libtool because it may want
dnl## to call AC_ CHECK_PROG.
AC_CHECK_TOOL(AR, ar)
AC_CHECK_TOOL(RANLIB, ranlib, :)

# Don't build the shared library for build.
enable_shared=no

frag=
case "${host}" in
  *-*-freebsd2.1.*)	frag=mh-fbsd21 ;;
  *-*-freebsd2.2.[[012]])	frag=mh-fbsd21 ;;
  i370-*-opened*)       frag=mh-openedition ;;
  i[[34567]]86-*-windows*)	frag=mh-windows ;;
esac

if [[ -n "${frag}" ]]; then
  frag=${libiberty_topdir}/libiberty/config/$frag
fi

echo "# Warning: this fragment is automatically generated" > temp-frag

if [[ -n "${frag}" ]] && [[ -f "${frag}" ]]; then
  echo "Appending ${frag} to xhost-mkfrag"
  echo "# Following fragment copied from ${frag}" >> temp-frag
  cat ${frag} >> temp-frag
fi

echo enable_shared = no >> temp-frag

frag=xhost-mkfrag
${CONFIG_SHELL-/bin/sh} ${libiberty_topdir}/config/move-if-change temp-frag libiberty/xhost-mkfrag

host_makefile_frag=${frag}
AC_SUBST_FILE(host_makefile_frag)

# It's OK to check for header files.  Although the compiler may not be
# able to link anything, it had better be able to at least compile
# something.
AC_HEADER_SYS_WAIT
AC_HEADER_TIME

# This is the list of functions which libiberty will provide if they
# are not available on the host.

funcs="asprintf atexit basename bzero getcwd getpagesize \
gettimeofday index mkstemps random rename  \
sigsetmask stpcpy strdup  \
vasprintf"
AC_CHECK_FUNCS_ONCE([atexit bzero getcwd getpagesize gettimeofday mempcpy pathconf pstat_getdynamic realpath stpcpy strdup strerror psignal strsignal])

# Also in the old function.def file: alloca, vfork, getopt.

vars="sys_errlist sys_nerr sys_siglist"

# These are neither executed nor required, but they help keep
# autoheader happy without adding a bunch of text to acconfig.h.
if test "x" = "y"; then
  AC_CHECK_DECLS([basename(char *), asprintf, vasprintf, ntf])
  AC_DEFINE(HAVE_SYS_ERRLIST, 1, [Define if you have the sys_errlist variable.])
  AC_DEFINE(HAVE_SYS_NERR,    1, [Define if you have the sys_nerr variable.])
  AC_DEFINE(HAVE_SYS_SIGLIST, 1, [Define if you have the sys_siglist variable.])
fi

# For each of these functions, if the host does not provide the
# function we want to put FN.o in LIBOBJS, and if the host does
# provide the function, we want to define HAVE_FN in config.h.

setobjs=
CHECK=
if test -n "${with_target_subdir}"; then

  # If we are being configured for Mingw, we know which functions
  # Mingw provides and which ones we will be expected to provide.

  case "${host}" in
  *-*-mingw*)
    AC_LIBOBJ([asprintf])
    AC_LIBOBJ([basename])
    AC_LIBOBJ([bzero])
    AC_LIBOBJ([getpagesize])
    AC_LIBOBJ([index])
    AC_LIBOBJ([mkstemps])
    AC_LIBOBJ([random])
    AC_LIBOBJ([sigsetmask])
    AC_LIBOBJ([stpcpy])
    AC_LIBOBJ([vasprintf])

    for f in $funcs; do
      case "$f" in
	asprintf | basename | bzero | getpagesize | index | mkstemps | random | sigsetmask | stpcpy | strdup | vasprintf)
	  ;;
	*)
	  n=HAVE_`echo $f | tr 'abcdefghijklmnopqrstuvwxyz' 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'`
	  AC_DEFINE_UNQUOTED($n)
	  ;;
      esac
    done

    # Mingw doesnt provide any of the variables in $vars, so we
    # dont have to check them here.

    setobjs=yes
    ;;

  esac

else

   # Not a target library, so we set things up to run the test suite.
   CHECK=really-check

fi

AC_SUBST(CHECK)
AC_SUBST(target_header_dir)

case "${host}" in
  *-*-cygwin* | *-*-mingw*)
    AC_DEFINE(HAVE_SYS_ERRLIST)
    AC_DEFINE(HAVE_SYS_NERR)
    ;;
esac

if test -z "${setobjs}"; then

  case "${host}" in

  *-*-android*)
    ## On android, getpagesize is defined in unistd.h as a static inline
    ## function, which AC_CHECK_FUNCS does not handle properly.
    ac_cv_func_getpagesize=yes
    ;;

  *-*-mingw32*)
    ## Under mingw32, sys_nerr and sys_errlist exist, but they are
    ## macros, so the test below won't find them.
    libiberty_cv_var_sys_nerr=yes
    libiberty_cv_var_sys_errlist=yes
    ;;
  esac

  # We haven't set the list of objects yet.  Use the standard autoconf
  # tests.  This will only work if the compiler works.
  AC_REPLACE_FUNCS($funcs)

  for v in $vars; do
    AC_MSG_CHECKING([for $v])
    AC_CACHE_VAL(libiberty_cv_var_$v,
      [AC_LINK_IFELSE([AC_LANG_PROGRAM([[int *p;]],[[extern int $v []; p = $v;]])],
		      [eval "libiberty_cv_var_$v=yes"],
		      [eval "libiberty_cv_var_$v=no"])])
    if eval "test \"`echo '$libiberty_cv_var_'$v`\" = yes"; then
      AC_MSG_RESULT(yes)
      n=HAVE_`echo $v | tr 'abcdefghijklmnopqrstuvwxyz' 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'`
      AC_DEFINE_UNQUOTED($n)
    else
      AC_MSG_RESULT(no)
    fi
  done

  AC_CHECK_DECLS([basename(char *), asprintf, vasprintf, getopt, canonicalize_file_name])
fi

  INSTALL_DEST=libdir
AC_SUBST(INSTALL_DEST)

m4_pattern_allow(LIBOBJS)
L=""
for l in x $LIBOBJS; do
  case $l in
    x) ;;
    *) L="$L ./$l" ;;
  esac
done
LIBOBJS="$L"

# Decide if -z relro should be enabled in ELF linker by default.
ac_default_ld_z_relro=unset
# Provide a configure time option to override our default.
AC_ARG_ENABLE(relro,
	      AS_HELP_STRING([--enable-relro],
	      [enable -z relro in ELF linker by default]),
[case "${enableval}" in
  yes)  ac_default_ld_z_relro=1 ;;
  no)  ac_default_ld_z_relro=0 ;;
esac])dnl

# Decide if -z separate-code should be enabled in ELF linker by default.
ac_default_ld_z_separate_code=unset
AC_ARG_ENABLE(separate-code,
	      AS_HELP_STRING([--enable-separate-code],
	      [enable -z separate-code in ELF linker by default]),
[case "${enableval}" in
  yes) ac_default_ld_z_separate_code=1 ;;
  no) ac_default_ld_z_separate_code=0 ;;
esac])

# host-specific stuff:
. ${srcdir}/ld/configure.host

AC_SUBST(NATIVE_LIB_DIRS)

AC_CHECK_FUNCS_ONCE([mmap strcasecmp])

# target-specific stuff:

all_targets=
EMUL=
all_emuls=
all_emul_extras=
all_libpath=

elf_list_options=FALSE
elf_shlib_list_options=FALSE
elf_plt_unwind_list_options=FALSE
for targ_alias in `echo $target_alias | sed 's/,/ /g'`
do
    # Canonicalize the secondary target names.
    result=`$ac_config_sub $targ_alias 2>/dev/null`
    if test -n "$result"; then
	targ=$result
    else
	targ=$targ_alias
    fi

    targ_emul=armelf

    if test "$targ" = "armv4tl-none-eabi"; then
      EMUL=$targ_emul
    fi

      . ${srcdir}/bfd/config.bfd

    for i in $targ_emul $targ_extra_emuls $targ_extra_libpath; do
	case " $all_emuls " in
	*" e${i}.o "*) ;;
	*)
	  all_emuls="$all_emuls e${i}.o"
	  test -z "$result" && result=$targ_alias
	  case "${i}" in
	  *elf*)
	    elf_list_options=TRUE
	    ;;
	  *)
	    if grep "TEMPLATE_NAME=elf32" ${srcdir}/ld/emulparams/${i}.sh >/dev/null 2>/dev/null; then
	      elf_list_options=TRUE
	    fi
	    ;;
	  esac
	  if test "$elf_list_options" = "TRUE"; then
	    . ${srcdir}/ld/emulparams/${i}.sh
	    if test x${GENERATE_SHLIB_SCRIPT} = xyes; then
	      elf_shlib_list_options=TRUE
	    fi
	    if test x${PLT_UNWIND} = xyes; then
	      elf_plt_unwind_list_options=TRUE
	    fi
	  fi
	  ;;
	esac
    done

    for i in $targ_emul $targ_extra_libpath; do
	case " $all_libpath " in
	*" ${i} "*) ;;
	*)
	  if test -z "$all_libpath"; then
	    all_libpath=${i}
	  else
	    all_libpath="$all_libpath ${i}"
	  fi
	  ;;
	esac
    done

    for i in $targ_extra_ofiles; do
	case " $all_emul_extras " in
	*" ${i} "*) ;;
	*)
	  all_emul_extras="$all_emul_extras ${i}"
	  ;;
	esac
    done
done



if test "${ac_default_ld_z_relro}" = unset; then
  ac_default_ld_z_relro=0
fi
AC_DEFINE_UNQUOTED(DEFAULT_LD_Z_RELRO,
  $ac_default_ld_z_relro,
  [Define to 1 if you want to enable -z relro in ELF linker by default.])

if test "${ac_default_ld_z_separate_code}" = unset; then
  ac_default_ld_z_separate_code=0
fi
AC_DEFINE_UNQUOTED(DEFAULT_LD_Z_SEPARATE_CODE,
  $ac_default_ld_z_separate_code,
  [Define to 1 if you want to enable -z separate-code in ELF linker by default.])

AC_SUBST(elf_list_options)
AC_SUBST(elf_shlib_list_options)
AC_SUBST(elf_plt_unwind_list_options)
AC_SUBST(EMUL)

  EMULATION_OFILES=$all_emuls
  EMUL_EXTRA_OFILES=$all_emul_extras
AC_SUBST(EMULATION_OFILES)
AC_SUBST(EMUL_EXTRA_OFILES)

EMULATION_LIBPATH=$all_libpath
AC_SUBST(EMULATION_LIBPATH)

target=armv4tl-none-eabi
target_alias=armv4tl-none-eabi
ac_cv_target=armv4tl-none-eabi
ac_cv_target_alias=armv4tl-none-eabi
enable_targets=

AC_ARG_WITH(mmap,
[  --with-mmap             try using mmap for BFD input files if available],
[case "${withval}" in
  yes)  want_mmap=true ;;
  no)   want_mmap=false ;;
  *)    AC_MSG_ERROR(bad value ${withval} for BFD with-mmap option) ;;
esac],[want_mmap=false])dnl

ACX_PKGVERSION([GNU Binutils])
ACX_BUGURL([http://www.sourceware.org/bugzilla/])

host64=false
target64=false
bfd_default_target_size=32

# host stuff:

BFD_HOST_64_BIT_DEFINED=0
BFD_HOST_64_BIT=
BFD_HOST_U_64_BIT=
BFD_HOSTPTR_T="unsigned long"

AC_TYPE_LONG_DOUBLE
#AC_CHECK_SIZEOF(void *)

#if test "x${ac_cv_sizeof_void_p}" = "x8"; then
#  host64=true
#  BFD_HOST_64_BIT_DEFINED=1
#  BFD_HOSTPTR_T="unsigned long long"
#fi

test -n "${HOST_64BIT_TYPE}" || HOST_64BIT_TYPE="long long"
test -n "${HOST_U_64BIT_TYPE}" || HOST_U_64BIT_TYPE="unsigned long long"

AC_SUBST(BFD_HOST_64_BIT_DEFINED)
AC_SUBST(BFD_HOST_64_BIT)
AC_SUBST(BFD_HOST_U_64_BIT)
AC_SUBST(BFD_HOSTPTR_T)

AC_CHECK_FUNCS_ONCE([getpagesize mmap munmap strcasecmp strncasecmp ])
AC_FUNC_FSEEKO

AC_CHECK_DECLS(ftello)
AC_CHECK_DECLS(ftello64)

AC_CHECK_DECLS(asprintf)

# When building a shared libbfd, link against the pic version of libiberty
# so that apps that use libbfd won't need libiberty just to satisfy any
# libbfd references.
# We can't do that if a pic libiberty is unavailable since including non-pic
# code would insert text relocations into libbfd.

all_targets=false
defvec=
selvecs=
assocvecs=
TDEFINES=
for targ in armv4tl-none-eabi $canon_targets
do
	. $srcdir/bfd/config.bfd
	if test "x$targ" = "xarmv4tl-none-eabi"; then
	    defvec=$targ_defvec
	fi
	selvecs="$selvecs $targ_defvec $targ_selvecs"
	TDEFINES="$TDEFINES $targ_cflags"
done
AC_SUBST(TDEFINES)

# This processing still needs to be done if we're to decide properly whether
# 64-bit support needs to be compiled in.  Currently, it will be included if
# the default or any other explicitly requested target requires it; it
# will not be included on a 32-bit host if no 64-bit target is requested, and
# no "--with-64-bit-bfd" option is given, even if "--enable-targets=all" is
# used.

# uniq the default and selected vectors in all the configured targets.
f=""
for i in $selvecs ; do
    case " $f " in
    *" $i "*) ;;
    *) f="$f $i" ;;
    esac
done
selvecs="$f"


# uniq the associated vectors in all the configured targets.
f=""
for i in $assocvecs ; do
    case " $f " in
    *" $i "*) ;;
    *) f="$f $i" ;;
    esac
done
assocvecs="$f"

elf="elf.o elflink.o elf-attrs.o elf-strtab.o elf-properties.o
     elf-eh-frame.o dwarf1.o dwarf2.o"


# Target architecture .o files.
# A couple of CPUs use shorter file names to avoid problems on DOS
# filesystems.

  # Only set these if they will be nonempty, for the clever echo.

AC_SUBST(bfd_default_target_size)

# Determine the host dependent file_ptr a.k.a. off_t type.  In order
# prefer: off64_t - if ftello64 and fseeko64, off_t - if ftello and
# fseeko, long.  This assumes that sizeof off_t is .ge. sizeof long.
# Hopefully a reasonable assumption since fseeko et.al. should be
# upward compatible.
if test x"$ac_cv_func_ftello" = xyes -a x"$ac_cv_func_fseeko" = xyes; then
    AC_CHECK_SIZEOF(off_t)
fi
AC_MSG_CHECKING([file_ptr type])
bfd_file_ptr="long"
bfd_ufile_ptr="unsigned long"
if test x"$ac_cv_func_ftello64" = xyes -a x"$ac_cv_func_fseeko64" = xyes \
	-o x"${ac_cv_sizeof_off_t}" = x8; then
    bfd_file_ptr=BFD_HOST_64_BIT
    bfd_ufile_ptr=BFD_HOST_U_64_BIT
fi
AC_MSG_RESULT($bfd_file_ptr)
AC_SUBST(bfd_file_ptr)
AC_SUBST(bfd_ufile_ptr)

if test x"$ac_cv_func_mmap" = xyes; then
  AC_DEFINE(USE_MMAP, 1, [Use mmap if it's available?])
fi

AC_CONFIG_FILES([bfd/Makefile bfd/bfd-in3.h:bfd/bfd-in2.h gas/Makefile ld/Makefile libiberty/Makefile binutils/Makefile])

# We need multilib support, but only if configuring for the target.
AC_CONFIG_COMMANDS([default],
  [rm -f targ-cpu.c targ-cpu.h obj-format.h obj-format.c targ-env.h atof-targ.c
[test -z "$CONFIG_HEADERS" || echo timestamp > ${libiberty_topdir}/libiberty/stamp-h
if test -n "$CONFIG_FILES"; then
  if test -n "${with_target_subdir}"; then
    # FIXME: We shouldn't need to set ac_file
    ac_file=Makefile
    LD="${ORIGINAL_LD_FOR_MULTILIBS}"
    . ${libiberty_topdir}/config-ml.in
  fi
fi]],
[[srcdir=${srcdir}
host=${host}
target=${target}
with_target_subdir=${with_target_subdir}
with_multisubdir=${with_multisubdir}
ac_configure_args="--enable-multilib ${ac_configure_args}"
CONFIG_SHELL=${CONFIG_SHELL-/bin/sh}
ORIGINAL_LD_FOR_MULTILIBS="${ORIGINAL_LD_FOR_MULTILIBS}"
libiberty_topdir=${libiberty_topdir}
]])
AC_OUTPUT
