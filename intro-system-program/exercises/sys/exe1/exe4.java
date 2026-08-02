public class exe4
{
    public static void main( String[] args )
    {
        ///*
        Fraction oneHalf = new Fraction(3, 6);
        System.out.println(oneHalf.numerator()); // Prints 1
        System.out.println(oneHalf.denominator()); // Prints 2
        System.out.println(oneHalf); // Prints 1/2
        Fraction twoHalves = oneHalf.add(oneHalf);
        System.out.println(twoHalves); // Prints 1/1
        Fraction one = new Fraction(1, 1);
        System.out.println(twoHalves.equals(one)); // Prints true
        //*/
    }
}



class Fraction
{
    //Fields
    private int numerator ;
    private int denominator ;

    //Methods
    //Transformation
    public void simplification()
    {
        int a = this.numerator > this.denominator ? this.numerator : this.denominator ;
        int b = this.numerator < this.denominator ? this.numerator : this.denominator ;
        int mod = 1 ;
        while ( mod != 0 )
        {
            mod = a % b ;
            a = b ;
            b = mod ;
        }
        this.numerator = this.numerator / a ;
        this.denominator = this.denominator / a ;
    }
    public void reduction( Fraction otherFraction )
    {
        this.numerator = this.numerator * otherFraction.denominator() ;
        this.denominator = this.denominator * otherFraction.denominator() ;
    }

    //Constructor
    @SuppressWarnings("OverridableMethodCallInConstructor")
    public Fraction( int numerator , int denominator )
    {
        this.numerator = numerator ;
        this.denominator = denominator ;
        this.simplification() ;
    }

    //Getters
    public int numerator()
    {
        return this.numerator ;
    }
    public int denominator()
    {
        return this.denominator ;
    }

    //Arithmetic
    public Fraction add( Fraction otherFraction )
    {
        Fraction result = new Fraction( this.numerator , this.denominator ) ;
        result.reduction(otherFraction) ;
        result.numerator = result.numerator + otherFraction.numerator() * this.denominator ;
        result.simplification() ;
        return result ;
    }
    public Fraction subtract( Fraction otherFraction )
    {
        Fraction result = new Fraction( this.numerator , this.denominator ) ;
        result.reduction(otherFraction) ;
        result.numerator = result.numerator - otherFraction.numerator() * this.denominator ;
        result.simplification() ;
        return result ;
    }
    public Fraction multiply( Fraction otherFraction )
    {
        Fraction result = new Fraction( this.numerator , this.denominator ) ;
        result.numerator = result.numerator * otherFraction.numerator() ;
        result.denominator = result.denominator * otherFraction.denominator() ;
        result.simplification() ;
        return result ;
    }
    public Fraction divide( Fraction otherFraction )
    {
        Fraction result = new Fraction( this.numerator , this.denominator ) ;
        result.numerator = result.numerator * otherFraction.denominator() ;
        result.denominator = result.denominator * otherFraction.numerator() ;
        result.simplification() ;
        return result ;
    }
    public boolean equals( Fraction otherFraction )
    {
        return this.numerator == otherFraction.numerator() && this.denominator == otherFraction.denominator() ;
    }

    //toString
    @SuppressWarnings("override")
    public String toString()
    {
        return this.numerator + "/" + this.denominator ;
    }
}