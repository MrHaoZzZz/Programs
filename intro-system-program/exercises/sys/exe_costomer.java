public class exe_costomer
{
    public static void main( String[] args )
    {
        Costomer bank_account_owner = new Costomer( "Mr.Haozi" , 1 ) ;
        Currency currency = new Currency( "RMB" , "¥" ) ;
        BankAccount bank_account = new BankAccount( bank_account_owner , currency , 1000 ) ;

        System.out.println( bank_account ) ;
    }
}

class Costomer
{
    //Fields
    private String name ;
    private int id ;

    //Methods
    public Costomer( String customer_name , int customer_id )
    {
        this.name = customer_name ;
        this.id = customer_id ;
    }
    public String getName()
    {
        return this.name ;
    }
}

class Currency
{
    //Fields
    private String name ;
    private String symbol ;

    //Methods
    public Currency( String currency_name , String currency_symbol )
    {
        this.name = currency_name ;
        this.symbol = currency_symbol ;
    }
    public String getName()
    {
        return this.name ;
    }
    public String getSymbol()
    {
        return this.symbol ;
    }
}

class BankAccount
{
    //Fields
    private Costomer owner ;
    private Currency currency ;
    private int balance ;

    //Methods
    public BankAccount( Costomer owner , Currency currency , int balance )
    {
        this.owner = owner ;
        this.currency = currency ;
        this.balance = balance ;
    }
    public int getBalance()
    {
        return this.balance ;
    }
    public String getCurrency()
    {
        return this.currency.getName() ;
    }
    public void deposit( int amount )
    {
        this.balance += amount ;
    }
    public void withdraw( int amount )
    {
        this.balance -= amount ;
    }
    //IMPORTANT!!! A TEMPLATE THAT HOW TO OVERRIDE THE toString() METHOD IN JAVA
    public String toString()
    {
        return "Owner: " + this.owner.getName() + "\nBalance: " + this.balance + " " + this.currency.getName() + this.currency.getSymbol() ;
    }
}