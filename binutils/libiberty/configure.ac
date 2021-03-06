dnl Process this file with autoconf to produce a configure script

m4_include([../config/warnings.m4])
AC_INIT
AC_CONFIG_SRCDIR([vprintf-support.c])
m4_include([../config/lean.m4])

# This works around the fact that libtool configuration may change LD
# for this particular configuration, but some shells, instead of
# keeping the changes in LD private, export them just because LD is
# exported.  We don't use libtool yet, but some day we might, so...
ORIGINAL_LD_FOR_MULTILIBS=$LD

dnl We use these options to decide which functions to include.
dnl#AC_ARG_WITH(target-subdir,
dnl#[  --with-target-subdir=SUBDIR      Configuring in a subdirectory for target])
dnl#AC_ARG_WITH(build-subdir,
dnl[  --with-build-subdir=SUBDIR       Configuring in a subdirectory for build])

if test "${srcdir}" = "."; then
  if test -n "${with_build_subdir}"; then
    libiberty_topdir="${srcdir}/../.."
    with_target_subdir=
  elif test -z "${with_target_subdir}"; then
    libiberty_topdir="${srcdir}/.."
  else
    if test "${with_target_subdir}" != "."; then
      libiberty_topdir="${srcdir}/${with_multisrctop}../.."
    else
      libiberty_topdir="${srcdir}/${with_multisrctop}.."
    fi
  fi
else
  libiberty_topdir="${srcdir}/.."
fi
AC_SUBST(libiberty_topdir)
dnl AC_CONFIG_AUX_DIR($libiberty_topdir)

MAINT='#'
NOTMAINT=''
AC_SUBST(MAINT)dnl
AC_SUBST(NOTMAINT)dnl

HAVE_PERL='#'
AC_SUBST(HAVE_PERL)

AC_CANONICAL_HOST

dnl When we start using automake:
dnl AM_INIT_AUTOMAKE(libiberty, 1.0)

## dnl These must be called before libtool because it may want
dnl to call AC_CHECK_PROG.
AC_CHECK_TOOL(AR, ar)
AC_CHECK_TOOL(RANLIB, ranlib, :)

dnl GCC_NO_EXECUTABLES
AC_PROG_CC
AC_USE_SYSTEM_EXTENSIONS
AC_SYS_LARGEFILE
AC_PROG_CPP_WERROR

ACX_PROG_CC_WARNING_OPTS([-W -Wall], [ac_libiberty_warn_cflags])

AC_PROG_CC_C_O
# autoconf is lame and doesn't give us any substitution variable for this.
if eval "test \"`echo '$ac_cv_prog_cc_'${ac_cc}_c_o`\" = no"; then
  NO_MINUS_C_MINUS_O=yes
else
  OUTPUT_OPTION='-o $@'
fi
AC_SUBST(NO_MINUS_C_MINUS_O)
AC_SUBST(OUTPUT_OPTION)
AC_C_BIGENDIAN


dnl When we start using automake:
AC_CONFIG_HEADER(config.h:config.in)

dnl AC_EXEEXT

dnl When we start using automake:
AC_PROG_INSTALL

# Don't build the shared library for build.
if [[ -n "${with_build_subdir}" ]]; then
  enable_shared=no
fi

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

  PICFLAG=
AC_SUBST(PICFLAG)

echo "# Warning: this fragment is automatically generated" > temp-frag

if [[ -n "${frag}" ]] && [[ -f "${frag}" ]]; then
  echo "Appending ${frag} to xhost-mkfrag"
  echo "# Following fragment copied from ${frag}" >> temp-frag
  cat ${frag} >> temp-frag
fi

echo enable_shared = no >> temp-frag

frag=xhost-mkfrag
${CONFIG_SHELL-/bin/sh} ${libiberty_topdir}/move-if-change temp-frag xhost-mkfrag

host_makefile_frag=${frag}
AC_SUBST_FILE(host_makefile_frag)

# It's OK to check for header files.  Although the compiler may not be
# able to link anything, it had better be able to at least compile
# something.
AC_CHECK_HEADERS_ONCE(sys/file.h sys/param.h malloc.h unistd.h strings.h sys/time.h sys/resource.h sys/stat.h sys/mman.h fcntl.h alloca.h sys/pstat.h sys/sysmp.h sys/sysinfo.h machine/hal_sysinfo.h sys/table.h sys/sysctl.h sys/systemcfg.h stdio_ext.h process.h sys/prctl.h)
AC_HEADER_SYS_WAIT
AC_HEADER_TIME

## libiberty_AC_DECLARE_ERRNO

# Determine sizes of some types.
AC_CHECK_SIZEOF([long])
AC_CHECK_SIZEOF([size_t])

# This is the list of functions which libiberty will provide if they
# are not available on the host.

funcs="asprintf"
funcs="$funcs atexit"
funcs="$funcs basename"
funcs="$funcs bzero"
funcs="$funcs ffs"
funcs="$funcs getcwd"
funcs="$funcs getpagesize"
funcs="$funcs gettimeofday"
funcs="$funcs index"
funcs="$funcs insque"
funcs="$funcs mkstemps"
funcs="$funcs random"
funcs="$funcs rename"
funcs="$funcs rindex"
funcs="$funcs sigsetmask"
funcs="$funcs stpcpy"
funcs="$funcs stpncpy"
funcs="$funcs strdup"
funcs="$funcs strndup"
funcs="$funcs strverscmp"
funcs="$funcs tmpnam"
funcs="$funcs vasprintf"
funcs="$funcs waitpid"
funcs="$funcs setproctitle"

# Also in the old function.def file: alloca, vfork, getopt.

vars="sys_errlist sys_nerr sys_siglist"

checkfuncs="__fsetlocking canonicalize_file_name getrlimit getrusage \
 getsysinfo gettimeofday on_exit psignal pstat_getdynamic pstat_getstatic \
 realpath setrlimit strsignal sysconf sysctl \
 sysmp table times"

# These are neither executed nor required, but they help keep
# autoheader happy without adding a bunch of text to acconfig.h.
if test "x" = "y"; then
  AC_CHECK_FUNCS(asprintf atexit \
    basename bzero \
    canonicalize_file_name \
    ffs __fsetlocking \
    getcwd getpagesize getrlimit getrusage getsysinfo gettimeofday \
    index insque \
     mkstemps \
    on_exit \
    psignal pstat_getdynamic pstat_getstatic \
    random realpath rename rindex \
    setproctitle setrlimit sigsetmask \
     stpcpy stpncpy strdup \
       strndup strsignal \
    strverscmp sysconf sysctl sysmp \
    table times tmpnam \
    vasprintf  \
    waitpid)
  AC_CHECK_DECLS([basename(char *), ffs, asprintf, vasprintf, ntf])
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
    AC_LIBOBJ([ffs])
    AC_LIBOBJ([getpagesize])
    AC_LIBOBJ([index])
    AC_LIBOBJ([insque])
    AC_LIBOBJ([mkstemps])
    AC_LIBOBJ([random])
    AC_LIBOBJ([rindex])
    AC_LIBOBJ([sigsetmask])
    AC_LIBOBJ([stpcpy])
    AC_LIBOBJ([stpncpy])
    AC_LIBOBJ([strndup])
    AC_LIBOBJ([strverscmp])
    AC_LIBOBJ([vasprintf])
    AC_LIBOBJ([waitpid])

    for f in $funcs; do
      case "$f" in
	asprintf | basename | bzero | ffs | getpagesize | index | insque |  mkstemps | random | rindex | sigsetmask | stpcpy | stpncpy | strdup | strndup | strverscmp | vasprintf | waitpid)
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
    # On android, getpagesize is defined in unistd.h as a static inline
    # function, which AC_CHECK_FUNCS does not handle properly.
    ac_cv_func_getpagesize=yes
    ;;

  *-*-mingw32*)
    # Under mingw32, sys_nerr and sys_errlist exist, but they are
    # macros, so the test below won't find them.
    libiberty_cv_var_sys_nerr=yes
    libiberty_cv_var_sys_errlist=yes
    ;;
  esac

  # We haven't set the list of objects yet.  Use the standard autoconf
  # tests.  This will only work if the compiler works.
  AC_SEARCH_LIBS([strerror],[cposix])
  AC_REPLACE_FUNCS($funcs)

    AC_CHECK_FUNCS(_doprnt)

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

  # special check for _system_configuration because AIX <4.3.2 do not
  # contain the `physmem' member.
  AC_MSG_CHECKING([for external symbol _system_configuration])
  AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[#include <sys/systemcfg.h>]],
			[[double x = _system_configuration.physmem;]])],
    [AC_MSG_RESULT([yes])
    AC_DEFINE(HAVE__SYSTEM_CONFIGURATION, 1,
	      [Define if you have the _system_configuration variable.])],
    [AC_MSG_RESULT([no])])

  AC_CHECK_FUNCS($checkfuncs)
  AC_CHECK_DECLS([basename(char *), ffs, asprintf, vasprintf, getopt, strverscmp canonicalize_file_name])
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

dnl Required by html and install-html
AC_SUBST(datarootdir)
AC_SUBST(docdir)
AC_SUBST(htmldir)

# We need multilib support, but only if configuring for the target.
AC_CONFIG_FILES([Makefile])
AC_CONFIG_COMMANDS([default],
  [[test -z "$CONFIG_HEADERS" || echo timestamp > stamp-h
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
