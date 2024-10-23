// Šî’êƒNƒ‰ƒX
public class BaseClass
{

    public int pubInt = 100;
    private int priInt = 200;
    protected int proInt = 300;

    public void PubMethod()
    {
        System.Console.WriteLine("PubMethod");
    }

    private void PriMethod()
    {
        System.Console.WriteLine("PriMethod");
    }

    protected void ProMethod()
    {
        System.Console.WriteLine("ProMethod");
    }

    public void AccessMember()
    {
        System.Console.WriteLine("pubInt = " + pubInt);
        PubMethod();
        System.Console.WriteLine("priInt = " + priInt);
        PriMethod();
        System.Console.WriteLine("proInt = " + proInt);
        ProMethod();
    }

}