for ( int i = 0 ; i < n ; i ++ ) // ---> O(n)

for ( int i = 0 ; i < n ; i ++ ) // --->O(n^2)
{
    for ( int j = 0 ; j < n ; j ++ )
}

/*
log --> base is 2

start = 0 , end = 10
1 2 3 4 5 6 7 8 9 10
O(log n)
*/

/*
// recursion
fun max( a: arr(int) ) -> res: int
    length := len(a) // get the length of array `a`
    if length = 1 then
        return a[0]
    
    b := new arr(int) // create new array to store 0 to length-2 elements in array `a`
    // for ( int i = 0 ; i < length - 1 ; i ++ )
    for every i in [0, length - 1) do
        b[i] := a[i]
    
    maxx := max(b)
    if maxx > a[length-1] then
        res := maxx
    else
        res := a[length-1]

*/

/*
2^4 = 2 * 2^3
2^3 = 2 * 2^2
2^2 = 2 * 2^1
2^1 = 2        // which is base

n^0 = 1
*/

/*
fun powerof( base, exponent: int ) -> res: int
!require: exponent >= 0, 
    if exponent = 1 then
        res := base
        return res
    
    if exponent = 0 then
        res := 1
        return res

    res := 2 * powerof( base, exponent - 1 )
!ensure: res = base^exponent
*/

// start = 0, end = len(a)

/*
fun minof( sequence: arr(nat), start, end: nat ) -> res: nat
!require: sequence != NULL, start <= end
    if end - start = 1 then         // base case
        res := sequence[start]
        return res
    
    min = minof( sequence, start, end-1 )

    // res := min < a[end-1] ? min : a[end-1]
    if min < a[end-1] then
        res := min
    else
        res := a[end-1]
!ensure: res is the smallest ...
*/

// a = _condition ? var1 : var2

/*
consider the string "Hello". We want to slice the substring "llo".
res[0] = 'l' but text[0] = 'H'.
*/
/*
i = 2 , j = 5
res[0] = 'l' , text[2 -> i] = 'l'
res[2] = 'o' , text[4->i+2->i+k] = 'o'

for k \in [ , ) , res[k] = text[i+k]
*/