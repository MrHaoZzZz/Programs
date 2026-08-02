fun slice( sentence : str , i : int , j : int ) -> result : str
!require : 0 <= i <= j <= len( sentence )
    length := len( sentence )
    result := new ( str , j - i + 1 )
    for every k in [ i , j ) do
        result[k - i] := sentence[k]
    result[j - i] := '\0'
!ensure : result = the substring from sentence[i] to sentence[j - 1]

fun split( sentence : str ) -> result : arr( str )
!require : sentence != NULL
    length := len( sentence )
    count := 1
    for every i in [ 0 , length ) do
        if sentence[i] = ' ' then
            count := count + 1
    result := new( str , count )
    l := 0
    r := -1
    for every i in [ 0 , count ) do
        l := r + 1
        r := search( sentence , l , ' ' )
        result[i] := slice( sentence , l , r )
!ensure : len( result ) = no. of white space in sentence + 1

fun input( a : arr( arr( double ) ) , f : file , n : int )
!require : n > 0
    line = "\0"
    for every i in [ 0 , n ) do
        a[i] := new( double , n+1 )
        line := get_next_line( f )
        tokens := split( line )
        for every j in [ 0 , n ] do
            a[i][j] := atof( tokens[j] )
!ensure : a is an n*(n+1) augmented  matrix filled with the value from file f

fun interchange( a : arr( arr( double ) ) , n : int )
!require : a is an n*(n+1) augmented matrix ; n > 0
    for every i in [ 0 , n-1 ) do
        found := 0
        if a[i][i] = 0 then
            for every j in [ i+1 , n ) do
                if not a[j][i] = 0 then
                    temp := a[i]
                    a[i] := a[j]
                    a[j] := temp
                found := 1
                break
        if found then
            continue
!ensure : for every i in [ 0 , n-1 ) , if exists j > i with a[j][i] != 0 then a[i][i] != 0

fun rank( a : arr( arr( double ) ) , n : int ) -> rank : int
!require : a is an n*(n+1) augmented matrix ; n > 0
    rank := n
    for every i in [ 0 , n ) do
        all_zero := true
        for every j in [ 0 , n ) do
            if not a[i][j] = 0 then
                all_zero := false
        if all_zero then
            rank := rank - 1
!ensure : 0 <= rank <= n

fun has_unique_solution( a : arr( arr( double ) ) , n : int ) -> result : bool
!require : a is an n*(n+1) augmented matrix ; n > 0
    r := rank( a , n )
    if r < n then
        result := false
    else
        result := true
!ensure : has_unique_solution( a , n ) iff the augmented matrix has unique solution

fun REF( a : arr( arr( double ) ) , n : int )
!require : a is an n*(n+1) augmented matrix ; n > 0
    for every i in [ 0 , n ) do 
        pivot := a[i][i]
        if not pivot = 0 then
            for every j in [ i , n ] do
                a[i][j] = a[i][j] / pivot
            for every j in [ i + 1 , n ) do
                factor = a[j][i]
                for every k in [ i , n ] do
                    a[j][k] = a[j][k] - factor * a[i][k]
!ensure : a is in row echelon form

fun RREF ( a : arr( arr( double ) ) , n : int )
!require : a is an n*(n+1) augmented matrix ; n > 0
    REF( a , n )
    for every i in [ n - 1 , 0 ] with i reduced do
        for every j in [ i - 1 , 0 ] with i reduced do
            factor := a[j][i]
            for every k in [ n , i ] with i reduced do
                a[j][k] := a[j][k] - factor * a[i][k]
!ensure : a is an n*(n+1) augmented matrix in reduced row echelon form