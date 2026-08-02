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

int iadd(int n, int m);
// require: n, m are natural numbers
//  ensure: iadd(n,m) = n+m

int imul(int n, int m);
// require: n, m are natural numbers
//  ensure: imul(n,m) = n*m

int ipow(int n, int m);
// require: n, m are natural numbers
//  ensure: ipow(n,m) = n^m

int ipred(int n);
// require: n is a natural number
//  ensure: ipred(n) = max(0,n-1)

int isub(int n, int m);
// require: n, m are natural numbers
//  ensure: isub(n,m) = n-m

int idiv(int n, int d);
// require: n, m are natural numbers, d != 0
//  ensure: n = idiv(n,m) * d + r, and r in [0:d)

int irem(int n, int d);
// require: n, m are natural numbers, d != 0
//  ensure: there is q such that n = q * d + irem(n,m), and irem(n,m) in [0:d)

int is_prime(int n);
// require: n is a natural number
//  ensure: is_prime(n) iff n is prime

int iroot(int n, int m);
// require: m has an n root in the natural numbers
//  ensure: iroot(int n, int m)^n = m

int ilog2(int n);
// require: n is a natural number
//  ensure: ilog2(n) is the logarithm of n
