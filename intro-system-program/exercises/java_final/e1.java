import java.util.ArrayList ;

abstract class Order
{
    abstract void accept( OrderVisitor visitor ) ;
}

class Product extends Order
{
    private String description ;
    private int price ;
    void accept( OrderVisitor visitor )
    {
        visitor.visitProduct( this.description, this.price ) ;
    }
}

class Bag extends Order
{
    private ArrayList<Order> orders = new ArrayList<>() ;
    void accept( OrderVisitor visitor )
    {
        for ( Order order : orders )
            order.accept( visitor ) ;
    }
}

class TotalPriceClaculator implements OrderVisitor
{
    public void visitProduct( String description, int price )
    {
        this.totalPrice += price ;
    }
    int getTotalPrice()
    {
        return this.totalPrice ;
    }
    // Fields
    private int totalPrice = 0 ;
    
}

interface OrderVisitor
{
    void visitProduct( String description, int price ) ;
}