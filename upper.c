/* ------------------------------------------------------------------------- *
 * Name   : upper
 * Author : Gerard Wassink
 * Date   : December 2022
 * Purpose: read input stream and make it upper case
 * Versions:
 *   0.1  : Initial code base
 *   
 * ------------------------------------------------------------------------- */
#define VERSION "0.1"
/* ------------------------------------------------------------------------- *
 *             GNU LICENSE CONDITIONS
 * ------------------------------------------------------------------------- *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * ------------------------------------------------------------------------- *
 *       Copyright (C) December 2022 Gerard Wassink
 * ------------------------------------------------------------------------- */

#include <stdio.h>

/* ------------------------------------------------------------------------- *
 *                                                              Main routine
 * ------------------------------------------------------------------------- */
int main(int argc , char *argv[])
{
	int c;
	while ( (c = getc(stdin)) != EOF)
		(c>96 && c<123) ? putc((c-32), stdout) : putc(c, stdout);
}
