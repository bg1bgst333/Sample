// Šî’êƒNƒ‰ƒX
public class BaseClass
{

    public int pubInt = 100;

    public void PubMethod()
    {
        System.Console.WriteLine("PubMethod");
    }

    public void AccessMember()
    {
        System.Console.WriteLine("pubInt = " + pubInt);
        PubMethod();
    }

}