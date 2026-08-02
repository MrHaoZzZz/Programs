

public class exe2
{
    static void main( String[] args )
    {
        Time t = new Time() ;
        t.increment() ;
        System.out.println( t ) ;

        Time t1 = new Time( 23 , 59 , 59 ) ;
        System.out.println( t1 ) ;
        t1.increment() ;
        System.out.println( t1 ) ;
    }
}

class Time
{
    // Method
    Time()
    {
        this.hour = 0 ;
        this.minute = 0 ;
        this.second = 0 ;
    }

    Time( int hour , int minute , int second )
    {
        this.hour = hour ;
        this.minute = minute ;
        this.second = second ;
    }

    public int getHour()
    {
        return this.hour ;
    }

    public int getMinute()
    {
        return this.minute ;
    }

    public int getSecond()
    {
        return this.second ;
    }

    public void increment()
    {
        this.second ++ ;
        if ( this.second >= 60 )
        {
            this.minute ++ ;
            this.second = 0 ;
            if ( this.minute >= 60 )
            {
                this.hour ++ ;
                this.minute = 0 ;
                if ( this.hour >= 24 )
                {
                    this.hour = 0 ;
                }
            }
        }
    }

    @Override
    public String toString()
    {
        String str ;
        String h , m , s ;
        if ( this.hour < 10 )
        {
            h = "0" + this.hour ;
        }
        else
        {
            h = this.hour + "" ;
        }
        if ( this.minute < 10 )
        {
            m = "0" + this.minute ;
        }
        else
        {
            m = this.minute + "" ;
        }
        if ( this.second < 10 )
        {
            s = "0" + this.second ;
        }
        else
        {
            s = this.second + "" ;
        }

        str = h + ":" + m + ":" + s ;
        return str ;
    }

    // Fields
    private int hour , minute , second ;
}