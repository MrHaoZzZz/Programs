import java.io.* ;

public class buffer
{
    static void main( String[] args ) throws IOException
    {
        String fileName = "e.txt" ;
        System.out.println( add_all_bytes( fileName ) ) ;
    }

    int add_all_bytes(String filename) throws IOException {
        FileInputStream fis = new FileInputStream(filename);
        byte[] buffer = new byte[BUFFER_SIZE];
        int sum = 0;
        int n;
        while ((n = fis.read(buffer)) != -1) {
            for (int i = 0; i < n; i++) {
                sum += buffer[i];
            }
        }
        fis.close();
        return sum;
    }
}