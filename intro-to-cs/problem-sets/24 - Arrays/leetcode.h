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

#ifndef LEETCODE_H
#define LEETCODE_H

#include <array.h>
#include <strlib.h>

int threeodds(arr(int) a, int size);
// require: len({a}) = {size}
//  ensure: threeodds({a},{size}) iff there are three consecutive odd numbers in {a}

int majorityelement(arr(int) a, int size);
// require: len({a}) = {size}
//  ensure: majorityelement({a},{size}) iff there is a majority element in {a}

int robot(str moves);
// require: {moves} is a valid sequence of moves of the robot
//  ensure: robot({moves}) iff {moves} brings the robot back to [0,0]

#endif