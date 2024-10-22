// Šî’êƒNƒ‰ƒX
public class BaseClass
{

    public int pubInt = 100;
    private int priInt = 200;

    public void PubMethod()
    {
        System.Console.WriteLine("PubMethod");
    }

    private void PriMethod()
    {
        System.Console.WriteLine("PriMethod");
    }

    public void AccessMember()
    {
        System.Console.WriteLine("pubInt = " + pubInt);
        PubMethod();
        System.Console.WriteLine("priInt = " + priInt);
        PriMethod();
    }

}