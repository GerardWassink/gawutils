/* ------------------------------------------------------------------------- *
 * Name   : cat
 * Author : Gerard Wassink
 * Date   : December 2022
 * Purpose: 
 * 			cat is a concatenation utility
 * 			- looks at commandline arguments, assumes they are filenames
 * 			- when arguments present, files are read and copied to stdout
 * 			- when no arguments present, stdin is read and copied to stdout
 * Versions:
 *   0.1  : Initial code base
 *   0.2  : Introduced stderr for error message
 *   
 * ------------------------------------------------------------------------- */
#define VERSION "0.2"
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
#include <stdlib.h>

/* ------------------------------------------------------------------------- *
 *                                                              Main routine
 * ------------------------------------------------------------------------- */
int main(int argc , char *argv[])
{
	FILE *fp, *fopen();
	void fileCopy();
	
	if (argc == 1) {			// No arguments, so
		fileCopy(stdin);		//   only stdin to stdout
	} else {
		while (--argc > 0) 		// arguments found, treat as filenames
		{
								// can we open the file?
			if ((fp = fopen(*++argv, "r")) == NULL)
			{
								// We can't, give message
				fprintf(stderr, "cat: can't open %s\n", *argv);
				exit(1);
			}
								// We can, copy it to stdout
			fileCopy(fp);
			fclose(fp);
		}
	}
}


/* ------------------------------------------------------------------------- *
 *                                               Copy file (by fp) to stdout
 * ------------------------------------------------------------------------- */
void fileCopy(fp) 
FILE *fp;
{
	int c;
	while ((c = getc(fp)) != EOF)
		putc(c, stdout);
}
