/*
 * This file is part of the Winter 2025 edition of the
 * Introduction to Computer Science course taught at the
 * Guangdong Technion Israel Institute of Technology, Shantou, China
 * 
 * copyright (C) 2025 Valentin Cassano, Santiago Figueira, & Agustin Borda

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

 #include <strlib.h>

 int len(str sentence) 
{
    int i = 0;

    while (sentence[i] != '\0')
    {
        i++;
    };

    return i;
}

int search(str s, int i, char c)
{
    int n = len(s);
    int r = i;

    while (r < n && s[r] != c)
    {
        r++;
    };

    return r;
}

int c2i(char c)
{
    int r = 0;

    if (c == '1')
    {
        r = 1;
    }
    else if (c == '2')
    {
        r = 2;
    }
    else if (c == '3')
    {
        r = 3;
    }
    else if (c == '4')
    {
        r = 4;
    }
    else if (c == '5')
    {
        r = 5;
    }
    else if (c == '6')
    {
        r = 6;
    }
    else if (c == '7')
    {
        r = 7;
    }
    else if (c == '8')
    {
        r = 8;
    }
    else if (c == '9')
    {
        r = 9;
    };

    return r;
}

int str2nat(str s, int i, int j)
{
    int r = 0;
    int k = i;

    while (k < j)
    {
        r = 10*r + c2i(s[k]);
        k++;
    };

    return r;
}