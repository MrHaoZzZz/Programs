public class exe3
{
    public static void main( String[] args )
    {
        Ingredient rice = new Ingredient("rice", 1.4);
        Ingredient chicken = new Ingredient("chicken", 1.9);
        Ingredient oliveOil = new Ingredient("olive oil", 9);
        Ingredient onion = new Ingredient("onion", 0.4);
        Ingredient water = new Ingredient("water", 0.4);
        //Here the kilocalories of water might should be 0 but not 0.4
        //If it is 0.4 then the total kilocalories of the recipe will be 1581 kCal instea of 1181 kCal.
        System.out.println(rice.kilocaloriesPerGram());

        Recipe chickenAndRiceSoup = new Recipe("chicken and rice soup");
        chickenAndRiceSoup.addIngredient(rice, 100);
        chickenAndRiceSoup.addIngredient(chicken, 450);
        chickenAndRiceSoup.addIngredient(oliveOil, 14);
        chickenAndRiceSoup.addIngredient(onion, 150);
        chickenAndRiceSoup.addIngredient(water, 1000);
        System.out.println(chickenAndRiceSoup.totalGrams());
        System.out.println(chickenAndRiceSoup.totalKilocalories());
    }
}

class Ingredient
{
    //Methods
    //Constructor
    public Ingredient( String name , double kilocalories )
    {
        this.name = name ;
        this.kilocalories = kilocalories ;
    }

    //Getters
    public String name()
    {
        return this.name ;
    }
    public double kilocaloriesPerGram()
    {
        return this.kilocalories ;
    }
    public double getGrams()
    {
        return this.grams ;
    }

    //Setters
    public void setGrams( double grams )
    {
        this.grams = grams ;
    }

    //Fields
    @SuppressWarnings({"unused", "FieldMayBeFinal"})
    private String name ;
    @SuppressWarnings("FieldMayBeFinal")
    private double kilocalories ;
    private double grams ;
}

class Recipe
{
    //Fields
    @SuppressWarnings({"unused", "FieldMayBeFinal"})
    private String name ;
    @SuppressWarnings("FieldMayBeFinal")
    private Ingredient[] ingredients ;
    public int cnt = 0 ;

    //Methods
    //Constructor
    public Recipe( String name )
    {
        this.name = name ;
        this.ingredients = new Ingredient[100] ;
    }

    //Adder
    public void addIngredient( Ingredient ingredient , double grams )
    {
        this.ingredients[cnt] = ingredient ;
        this.ingredients[cnt].setGrams(grams) ;
        this.cnt ++ ;
    }

    //Getters
    public double totalGrams()
    {
        double res = 0 ;
        for ( int i = 0 ; i < cnt ; i ++ ) res += this.ingredients[i].getGrams() ;
        return res ;
    }
    public double totalKilocalories()
    {
        double res = 0 ;
        for ( int i = 0 ; i < cnt ; i ++ ) res += this.ingredients[i].kilocaloriesPerGram() * this.ingredients[i].getGrams() ;
        return res ;
    }
}