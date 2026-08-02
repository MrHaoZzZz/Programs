fun shift( date: str, n: int ) -> ans: str
!require: validate( date ) = "valid date"
    convert_to_int( date, year, month, day )
    day := day + n

    while day > get_days_in_month( year, month ) do
        day := day - get_days_in_month( year, month )
        month := month + 1
        if month > 12 then
            month := 1
            year := year + 1
    
    while day <= 0 do
        month := month - 1
        if month < 1 then
            month := 12 
            year := year - 1
        day := get_days_in_month( year, month )
    
    convert_to_string( year, month, day, ans )
!ensure: shift( date, k ) is the date that shifted

fun convert_to_int( s: str, year, month, day: int ) -> null
!require: validate( ) ... 
    year := s[0] - '0' * 1000 ...
    ...
!ensure: year

fun get_days_in_month( year, month: int ) -> days_in_month[leap_year][month-1]: int
    days_in_month[0] := [31, 28, ....]
    days_in_month[1] := [31, 29, ....]
    leap_year := ( year%400 = 0 ) or ( year%4 = 0 and year%400 = 0 )

fun convert_to_string(year, month, day: int, ans: str) -> null
    ans := sprintf("%04d-%02d-%02d", year, month, day)


real bool arr(int) str