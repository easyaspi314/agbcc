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

dnl Get a default for CC_FOR_BUILD to put into Makefile.
AC_DEFUN([BFD_CC_FOR_BUILD],
[# Put a plausible default for CC_FOR_BUILD in Makefile.
if test -z "$CC_FOR_BUILD"; then
  if test "x$cross_compiling" = "xno"; then
    CC_FOR_BUILD='$(CC)'
  else
    CC_FOR_BUILD=gcc
  fi
fi
AC_SUBST(CC_FOR_BUILD)
# Also set EXEEXT_FOR_BUILD.
if test "x$cross_compiling" = "xno"; then
  EXEEXT_FOR_BUILD='$(EXEEXT)'
else
  AC_CACHE_CHECK([for build system executable suffix], bfd_cv_build_exeext,
    [rm -f conftest*
     echo 'int main () { return 0; }' > conftest.c
     bfd_cv_build_exeext=
     ${CC_FOR_BUILD} -o conftest conftest.c 1>&5 2>&5
     for file in conftest.*; do
       case $file in
       *.c | *.o | *.obj | *.ilk | *.pdb) ;;
       *) bfd_cv_build_exeext=`echo $file | sed -e s/conftest//` ;;
       esac
     done
     rm -f conftest*
     test x"${bfd_cv_build_exeext}" = x && bfd_cv_build_exeext=no])
  EXEEXT_FOR_BUILD=""
  test x"${bfd_cv_build_exeext}" != xno && EXEEXT_FOR_BUILD=${bfd_cv_build_exeext}
fi
AC_SUBST(EXEEXT_FOR_BUILD)])dnl
dnl GAS_CHECK_DECL_NEEDED(name, typedefname, typedef, headers)
AC_DEFUN([GAS_CHECK_DECL_NEEDED],[
AC_MSG_CHECKING(whether declaration is required for $1)
AC_CACHE_VAL(gas_cv_decl_needed_$1,
AC_LINK_IFELSE([AC_LANG_PROGRAM([[$4]], [[
typedef $3;
$2 x;
x = ($2) $1;
]])],[gas_cv_decl_needed_$1=no],[gas_cv_decl_needed_$1=yes]))dnl
AC_MSG_RESULT($gas_cv_decl_needed_$1)
if test $gas_cv_decl_needed_$1 = yes; then
 AC_DEFINE([NEED_DECLARATION_]translit($1, [a-z], [A-Z]), 1,
	   [Define if $1 is not declared in system header files.])
fi
])dnl

dnl
dnl Since many Bourne shell implementations lack subroutines, use this
dnl hack to simplify the code in configure.ac.
dnl GAS_UNIQ(listvar)
AC_DEFUN([GAS_UNIQ],
[_gas_uniq_list="[$]$1"
_gas_uniq_newlist=""
dnl Protect against empty input list.
for _gas_uniq_i in _gas_uniq_dummy [$]_gas_uniq_list ; do
  case [$]_gas_uniq_i in
  _gas_uniq_dummy) ;;
  *) case " [$]_gas_uniq_newlist " in
       *" [$]_gas_uniq_i "*) ;;
       *) _gas_uniq_newlist="[$]_gas_uniq_newlist [$]_gas_uniq_i" ;;
     esac ;;
  esac
done
$1=[$]_gas_uniq_newlist
])dnl
dnl
dnl Check for existence of member $2 in type $1 in time.h
dnl
AC_DEFUN([GAS_HAVE_TIME_TYPE_MEMBER],
[AC_MSG_CHECKING([for $1.$2 in time.h])
 AC_CACHE_VAL(gas_cv_have_time_type_member_$2,
   [AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#define _BSD_SOURCE 1
#include <time.h>]], [[$1 avar; void* aref = (void*) &avar.$2]])],[gas_cv_have_time_type_member_$2=yes],[gas_cv_have_time_type_member_$2=no
   ])])
 if test $gas_cv_have_time_type_member_$2 = yes; then
   AC_DEFINE([HAVE_]translit($2, [a-z], [A-Z]), 1,
	     [Define if <time.h> has $1.$2.])
 fi
 AC_MSG_RESULT($gas_cv_have_time_type_member_$2)
])dnl
