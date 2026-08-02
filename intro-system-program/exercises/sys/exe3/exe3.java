import java.util.ArrayList ;

public class exe3
{
    static void main( String[] args )
    {
        //
    }
}

class TemperatureReport
{
    ArrayList<Double> a = new ArrayList<>() ;

    TemperatureReport()
    {
        a.add( 25.3 ) ;
    }

    void recordTemperature( double t )
    {
        a.add( t ) ;
    }

    double maxLast( int hours )
    {
        double maxx = a.get( a.size() - hours ) ;
        for ( int i = a.size() - hours ; i < a.size() ; i ++ )
        {
            if ( maxx < a.get( i ) ) maxx = a.get( i ) ;
        }
        return maxx ;
    }

    double minLast( int hours )
    {
        double minn = a.get( a.size() - hours ) ;
        for ( int i = a.size() - hours ; i < a.size() ; i ++ )
        {
            if ( minn > a.get( i ) ) minn = a.get( i ) ;
        }
        return minn ;
    }

    double avgLast( int hours )
    {
        double sum = 0 ;
        double avg ;
        for ( int i = a.size() - hours ; i < a.size() ; i ++ )
        {
            sum += a.get( i ) ;
        }
        avg = sum / hours ;
        return avg ;
    }
}