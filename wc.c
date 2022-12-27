/* ------------------------------------------------------------------------- *
 * Name   : wc
 * Author : Gerard Wassink
 * Date   : December 2022
 * Purpose: read input stream and count (groups of) characters
 * Versions:
 *   0.1  : Initial code base
 *   0.2  : count one word for multiple consecutive whitespace caharacters
 *   0.3  : added \0, \a, \b, \f, \r, \t and \v to whitespace characters
 *   0.4  : introduced the isprintable() function
 *          made it possible to count multiple files OR stdin
 *   
 * ------------------------------------------------------------------------- */
#define VERSION "0.4"
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
#include <ctype.h>


/* ------------------------------------------------------------------------- *
 *                                                            Count per file
 * ------------------------------------------------------------------------- */
int total_bytes = 0, total_words = 0, total_lines = 0;


/* ------------------------------------------------------------------------- *
 *                                                   function: isprintable()
 * everything NOT tested for is supposed to be printable 
 * and thus can be part of a 'word'
 * ------------------------------------------------------------------------- */
int isprintable(int c)
{
  	return (   c == ' '  \
			|| c == 0x01 \
			|| c == '\0' \
			|| c == '\a' \
			|| c == '\b' \
			|| c == '\n' \
			|| c == '\r' \
			|| c == '\t' \
			|| c == '\f' \
			|| c == '\v' ) ? 0 : 1;
}


/* ------------------------------------------------------------------------- *
 *                                                            Count per file
 * ------------------------------------------------------------------------- */
void countFile(FILE *file, char *filename)
{
	int c, words, lines, bytes, inWS, prevWS;
	lines = words = bytes = inWS = prevWS = 0;
	
	while ((c = getc(file)) !=EOF)
	{
		bytes++;					// Count every byte
		
		if (c == '\n') lines++;		// Count every line
		
		prevWS = inWS;				// Are we in whitepsace?
		inWS = isprintable(c);

									// We where not in whitespace
									//  but now we are: bump word counter
		if (prevWS == 0 && inWS == 1) 
			words++;

	}

									// Print results
	printf("%5d %5d %5d %s\n", lines, words, bytes, filename);
	
									// Add counts to totals
	total_bytes += bytes;
	total_words += words;
	total_lines += lines;
}


/* ------------------------------------------------------------------------- *
 *                                                              Main routine
 * ------------------------------------------------------------------------- */
int main(int argc , char *argv[])
{
	int args;
	FILE *fp;
	char std_in[5] = "stdin";
	
	if (argc < 2)					// No filename specified, read from stdin
	{
		countFile(stdin, std_in);
	} else {						// At least one argument, treat as filenames
		for (args = 1; args < argc; args++) {
			fp = fopen(argv[args], "r");	// Open this file for reading
			if (!fp) 						// No luck? error and exit
			{
				fprintf(stderr, "cannot open file %s\n", argv[args]);
				return 1;
			}
			countFile(fp, argv[args]);		// Count in this file
			fclose(fp);						// Close the file again
		}
	}
	
	if (argc > 2)					// Print total results when needed
		printf("%5d %5d %5d total\n", total_lines, total_words, total_bytes);
		
	return 0;
}
