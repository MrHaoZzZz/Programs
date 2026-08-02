import java.io.FileInputStream ;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException ;
import java.io.InputStreamReader ;
import java.io.OutputStreamWriter;
import java.util.ArrayList ;

public class fileIO
{
    public static void main( String[] args ) throws IOException 
    {
        
        FileInputStream fis = new FileInputStream( "a.txt" ) ;
        InputStreamReader isr = new InputStreamReader( fis , "UTF-8" ) ;
        FileOutputStream fos = new FileOutputStream( "b.txt" ) ;
        OutputStreamWriter osw = new OutputStreamWriter( fos , "UTF-8" ) ;
        // read( fis , isr ) ;
        // write( fos , osw ) ;
        byte input = (byte) fis.read(); // input == 97
        fos.write(input); // b.txt change to "97"

        fis.close();
        fos.close();
        

        /*
        FileInputStream fisInt = new FileInputStream( "c.txt" ) ;
        FileOutputStream fosInt = new FileOutputStream( "d.txt" ) ;
        System.out.println( readInt( fisInt ) ) ;
        writeInt( fosInt , 676767 ) ;
        */
        /*
        FileInputStream fis = new FileInputStream("a.txt");
        System.out.println(fis.read());
        fis.close();
        */
    }

    static void writeInt( FileOutputStream fos , int n ) throws IOException
    {
        int p = 1 ;
        while ( 10 * p <= n ) p *= 10 ;

        while ( p >= 1 )
        {
            fos.write( '0' + n / p ) ;
            n %= p ;
            p /= 10 ;
        }

        fos.write( ';' ) ;
    }

    static int readInt( FileInputStream fis ) throws IOException
    {
        int n = 0 ;
        int next = fis.read() ;
        while ( next != ';' ) 
        {
            int digit = next - '0' ;
            n = 10 * n + digit ;
            next = fis.read() ;
        }
        return n ;
    }

    static void write( FileOutputStream fos , OutputStreamWriter osw ) throws FileNotFoundException, IOException
    {
        try
        {
            fos.write( 102 ) ;
            fos.write( 117 ) ;
            fos.write( 99 ) ;
            fos.write( 107 ) ;
            fos.write( 10 ) ;
            osw.write( "fuck by OuputStearmWrite\n我操你妈" ) ;
        }
        catch ( IOException e )
        {
            System.out.println("err") ;
        }
    }

    static void read( FileInputStream fis , InputStreamReader isr )
    {
        ArrayList<Byte> bytes = new ArrayList<>() ;
        try
        {
            int next = isr.read() ;
            while ( next != -1 )
            {
                System.out.print( ( char ) next ) ;
                bytes.add( ( byte ) next ) ;
                next = isr.read() ;
            }
            fis.close() ;
            System.out.println( "" ) ;
            System.out.println( bytes ) ;
        }
        catch ( IOException e )
        {
            System.out.println( "Can not read the file." ) ;
        }
    }
}