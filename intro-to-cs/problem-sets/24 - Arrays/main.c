/*
 * This file is part of the Winter 2025 edition of the
 * Introduction to Computer Science course taught at the
 * Guangdong Technion Israel Institute of Technology, Shantou, China
 * 
 * copyright (C) 2025 Valentin Cassano & Santiago Figueira

 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <stdlib.h>
#include <strlib.h>
#include <array.h>
#include <leetcode.h>

int main(int argc, arr(str) argv)
{
    int      size = argc - 1; 
    arr(int) a    = new(int,size);

    // build the array from the command-line arguments
    for (int i = 0; i < size; i++)
    {
        a[i] = atoi(argv[i+1]);
    };

    printf("%d\n", threeodds(a, size));

    free(a);

    return 0;
}


// int main(int argc, char *argv[]) {
//     char *move;
//     move = argv[1];
//     printf("%d\n",robot(move));
//     return 0;
// }