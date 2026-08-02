public class exe_circle
{
    public static void main( String[] args )
    {
        // ...
    }
    
}

@SuppressWarnings("unused")
class Circle
{
    //Fields
    private double radius = 0.0 ;
    @SuppressWarnings("FieldMayBeFinal")
    private double PI = 3.1415926f ;
    //Methods
    public Circle( double radius )
    {
        this.radius = radius ;
    }
    public double getRadius()
    {
        return this.radius ;
    }
    public double getDiameter()
    {
        return 2 * this.radius ;
    }
    public double getArea()
    {
        return this.PI * this.radius * this.radius ;
    }
    public double getPerimeter()
    {
        return 2 * this.PI * this.radius ;
    }
}