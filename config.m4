PHP_ARG_WITH(idn, for IDNA support, [  --with-idna     Enable IDNA support])

if test "$PHP_IDNA" != "no"; then
  SEARCH_PATH="/usr/local /usr"
  SEARCH_FOR="/include/idna.h"

  if test -r $PHP_IDNA/$SEARCH_FOR; then
    IDNA_DIR=$PHP_IDNA
  else
    AC_MSG_CHECKING([for IDNA in default path])
    for i in $SEARCH_PATH ; do
      if test -r $i/$SEARCH_FOR; then
        IDNA_DIR=$i
        AC_MSG_RESULT(found in $i)
        break
      fi
    done
  fi

  if test -z "$IDNA_DIR"; then
    AC_MSG_RESULT([not found])
    AC_MSG_ERROR([Please reinstall the GNU libidn distribution])
  fi

  PHP_ADD_INCLUDE($IDNA_DIR/include)

  PHP_CHECK_LIBRARY(idn, stringprep_check_version,
  [
    PHP_ADD_LIBRARY_WITH_PATH(idn, $IDNA_DIR/lib, IDNA_SHARED_LIBADD)
    AC_DEFINE(HAVE_IDNA, 1, [ ])
  ],[
    AC_MSG_ERROR([wrong IDN lib version or lib not found])
  ],[
  ])

  PHP_SUBST(IDNA_SHARED_LIBADD)
  AC_DEFINE(HAVE_IDNA, 1, [ ])
  PHP_NEW_EXTENSION(idna, idna.c, $ext_shared)
fi

