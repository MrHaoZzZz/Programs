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

#ifndef STRLIB_H
#define STRLIB_H

typedef char* str;

int len(str);
// ensure: ln(str) = the number of symbols in the string

int search(str,char);
// ensure: search(str,char) iff char occurs in str

int count(str,char);
// ensure: count(str,char) = no. of times char occurs in str

int abecedarian(str);
// ensure: abecedarian(str) iff str is abecedarian

int firstof(str,char);
// ensure: firstof(str,char) = index at which char appears first in str
//         firstof(str,char) = -1 iff char does not appear in str

int lastof(str,char);
// ensure: lastof(str,char) = index at which char appears last in str
//         lastof(str,char) = len(str) iff char does not appear in str

int equals(str);
// ensure: equals(str) iff all char in str are equal to each other

int palindrome(str);
// ensure: palindrime(str) iff str is a palindrome

int count_uppercase(str);
// ensure: count_uppercase(str) = nmber of uppercase characters in str

int is_number(str);
// ensure: is_number9(str) iff all characters in str are numbers

int to_number(str);
// require: is_number(str)
// ensure: to_number(str) = the integer number represented by str

int string_equals(str,str);
// ensure: string_equals(str1, str2) iff str1 and str2 are equals

 
#endif
