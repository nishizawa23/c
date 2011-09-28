/*************************************************************************
 * Author: huangxinghua
 * Email: <nishizawa23@gmail.com>
 * Web: http://www.nishizawa23.com
 * File: variable_argument.c
 * Create Date: 2011-09-28 10:58:14
 *************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int demo( char *, ... );

void main( void )
{
	demo("DEMO", "This", "is", "a", "demo!", "\0");
}

int demo( char *msg, ... )
{
	va_list argp;
	int argno = 0;
	char *para;

	va_start(argp, msg);

	while (1) {

		para = va_arg(argp, char*);

		if ( strcmp( para, "\0") == 0 )
			break;
		printf("Parameter #%d is: %s\n", argno, para);
		argno++;
	}
	va_end(argp);
	return 0;
}
