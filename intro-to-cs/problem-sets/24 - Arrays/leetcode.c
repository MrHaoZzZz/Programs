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

#include <array.h>
#include <strlib.h>
#include <leetcode.h>

int threeodds(arr(int) a, int size)
{
    int found = 0;
    int i = 0;
    int count = 0;

    while (i<size && !found)
    {
        if (a[i] % 2 != 0)
        {
            count++;
        }
        else {
            count = 0;
        };

        found = (count == 3);

        i++;
    }

    return found;
}

int count(arr(int) a, int size, int elem) 
{
// require: n = size(a)
    int result = 0;

    for (int i=0; i<size; i++) {
        result += (a[i] == elem);
    }

    return result;
//ensure: result = number of occurrences of elem in a
}

int majorityelement(arr(int) a, int size)
{
// require: n = size(arr)
    int found = 0;
    int i = 0;

    while (i<size && !found) {
        // inv: 1 <= i <= n and
        //      for all j in [0:i), count(a,n,a[j]) <= n/2 (treated part)
        //      if i < n then found iff count(a,n,a[i]) > n/2  
        found = found || (count(a,size,a[i]) > size/2);
        i++;
    }

    return found;
// ensure: found iff there is an element which appears 
//                   more than n/2 times in arr
}

int robot(str moves)
{



    return 0;
}
