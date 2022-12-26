/* ------------------------------------------------------------------------- *
 * Name   : wc
 * Author : Gerard Wassink
 * Date   : December 2022
 * Purpose: read input stream and count (groups of) characters
 * Versions:
 *   0.1  : Initial code base
 *   0.2  : count one word for multiple consecutive whitespace caharacters
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

/* ------------------------------------------------------------------------- *
 *                                                              Main routine
 * ------------------------------------------------------------------------- */
int main(int argc , char *argv[])
{
	int c, words, lines, bytes, inWS, prevWS;
	lines = words = bytes = inWS = prevWS = 0;
	
	while ((c = getchar()) !=EOF)
	{
		bytes++;					// Count every byte
		
		if (c == '\n') lines++;		// Count every line
		
		prevWS = inWS;				// Are we in whitepsace?
		inWS = (c == '\n' || c == ' ' || c == '\t') ? 1 : 0;

									// We where not in whitespace
									//  but now we are: bump word counter
		if (prevWS == 0 && inWS == 1) 
			words++;

	}
									// Print results
	printf("%7d %7d %7d\n", lines, words, bytes);
}
