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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#include "php.h"
#include "php_idna.h"

#include <stringprep.h>
#include <idna.h>

static zend_function_entry idna_functions[] = {
    PHP_FE(idna_toascii, NULL)
    PHP_FE(idna_tounicode, NULL)
    {NULL, NULL, NULL}
};

zend_module_entry idna_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
    STANDARD_MODULE_HEADER,
#endif
    PHP_IDNA_EXTNAME,
    idna_functions,
    PHP_MINIT(idna),
    NULL,
    NULL,
    NULL,
    PHP_MINFO(idna),
#if ZEND_MODULE_API_NO >= 20010901
    PHP_IDNA_VERSION,
#endif
    STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_IDNA
ZEND_GET_MODULE(idna)
#endif

PHP_MINFO_FUNCTION(idna)
{
	php_info_print_table_start();
	php_info_print_table_row(2, "idna support", "enabled");
	php_info_print_table_row(2, "idna version", PHP_IDNA_VERSION);
	php_info_print_table_row(2, "GNU libidn version", STRINGPREP_VERSION);
	php_info_print_table_end();
}

PHP_MINIT_FUNCTION(idna)
{
	if(NULL == stringprep_check_version(STRINGPREP_VERSION)) {
		return FAILURE;
	}

	return SUCCESS;
}

PHP_FUNCTION(idna_toascii)
{
	char *domain, *ret;
	int rc, len;

	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &domain, &len) == FAILURE) {
		RETURN_NULL();
	}

	if(IDNA_SUCCESS != (rc = idna_to_ascii_8z(domain, &ret, 0))) {
		php_error(E_WARNING, "idna: domain-convert failed: %s", idna_strerror(rc));
		free(ret);
		RETURN_FALSE;
	}

	RETVAL_STRING(ret, 1);
	free(ret);
	return;
}

PHP_FUNCTION(idna_tounicode)
{
	char *domain, *ret;
	int rc, len;

	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &domain, &len) == FAILURE) {
		RETURN_NULL();
	}

	if(IDNA_SUCCESS != (rc = idna_to_unicode_8z8z(domain, &ret, 0))) {
		php_error(E_WARNING, "idna: domain-convert failed: %s", idna_strerror(rc));
		free(ret);
		RETURN_FALSE;		
	}

	RETVAL_STRING(ret, 1);
	free(ret);
	return;
}

