/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.0 of the PHP license,       |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_0.txt.                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author: Robert Eisele <robert@xarg.org>                              |
  | Site: http://www.xarg.org/project/php-idna/                          |
  +----------------------------------------------------------------------+
*/

#ifndef PHP_IDNA_H
#define PHP_IDNA_H

#define PHP_IDNA_VERSION "1.0.0"
#define PHP_IDNA_EXTNAME "idna"

#ifdef ZTS
# include "TSRM.h"
#endif

PHP_MINFO_FUNCTION(idna);
PHP_MINIT_FUNCTION(idna);

PHP_FUNCTION(idna_toascii);
PHP_FUNCTION(idna_tounicode);

extern zend_module_entry idna_module_entry;
#define phpext_idna_ptr &idna_module_entry

#endif
