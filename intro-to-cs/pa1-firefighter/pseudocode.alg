fun is_in_radius(distance, x, y: num) -> bool
    return distance*distance >= x*x + y*y

fun is_arrive(x0, x1, y0, y1: num) -> bool
    return x0 == x1 and y0 == y1

fun get_length(string: str) -> num
    length := 0
    while string[length] != '\0' do
        length := length + 1
    return length

fun reverse( path: str ) -> str
    len := get_length( path )
    reversed := new( char , len+1 )
    //Make a memory space with len+1 size
    for i in [0, len-1) do
        origin := path[len-i-1]
        //Reverse the path
        if origin := 'L' then
            reversed[i] := 'R'
        elif origin := 'R' then
            reversed[i] := 'L'
        else 
            reversed[i] := origin
    reversed[len] := '\0'
    return reversed

fun firefighter( base, target:arr(num), battery, distance: num, plan: str ) -> str
    //To get the length of plan
    len := get_length( plan ) 
    //Cliam a variable of the direction , and is initially towards North
    //For the convinient of processing, we define :
    //0 -> N ; 1 -> E ; 2 -> S ; 3 -> W
    direction := 0
    //Cliam a variable of the position
    position: = { base[0] , base[1] }
    //To record the battery used
    battery_used := 0
    //To record if mission success
    reach := 0 , success := 0
    //To store the prefix
    prefix := new( str , len+1 )
    prefix_len := 0
    pre_direction := direction , pre_position := { position[0] , position[1] }
    for every i in [0, len) do
        //To save the previous state so that is convinient to return backwards
        pre_direction := direction , pre_position := { position[0] , position[1] }
        //To execute the command
        if plan[i] == 'L' then
            direction := ( direction + 3 ) % 4
        if plan[i] == 'R' then
            direction := ( direction + 1 ) % 4
        if plan[i] == 'S' then
            row := new( num , 4 )
            col := new( num , 4 )
            row := { 0 , 1 , 0 , -1 }
            col := { 1 , 0 , -1 , 0 }
            position[0] := position[0] + row[direction]
            position[1] := position[1] + col[direction]
        battery_used ++ 

        //Judge if the drone is beyond the raduis
        if !is_in_radius( distance , position[0] , position[1] ) then
            //Go back
            direction := pre_direction
            position := pre_direction
            battery_used := battery_used - 1
            i := len
        //Judge if there is enough battery to return the base
        elif battery_used*2 + 2 > battery then
            //Go back
            direction := pre_direction
            position := pre_direction
            battery_used := battery_used - 1
            i := len
        else
            //Store the prefix
            prefix[prefix_len] := plan[i]
            prefix_len ++
            prefix[prefix_len] := '\0'
    

    //To judge if the mission success
    if  is_arrive( position[0] , position[1] , target[0] , target[1] ) then
        if battery_used*2 + 2 <= battery and is_in_radius( distance , position[0] , position[1] ) then
            //Mission success
            success := true
        

    //Cliam the variable of result
    char first 
    str second 
    str third 

    //Build the parts of answer
    if success then
        //0
        first := '0' 
        //plan
        second := plan 
        //return
        third := reverse( plan ) 
    else
        //1
        first := '1' 
        //prefix
        prefix[prefix_len] := '\0' 
        second := prefix 
        //return
        third := reverse( prefix ) 

    //To get the string length of the different parts of the final answer
    len2 := get_length( second ) , len3 := get_length( third )
    //To get the total length of answer
    len_tot := 1 + 1 + len2 + 1 + 2 + len3 + 1
    //Allocate memory for the variable result
    result := new( char , len_tot )
    //Writing the final answer
    result[0] := first 
    result[1] := '.' 
    for i in [1,len2) do
        result[i+2] := second[i]
    result[len2+2] := '.' 
    //Turn around
    result[len2+3] := 'R' 
    result[len2+4] := 'R' 
    for i in [0, len3) do
        result[i+len2+5] := third[i]
    result[len_tot-1] := '\0'

    //All has done
    return result 