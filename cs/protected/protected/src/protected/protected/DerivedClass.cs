// îhê∂ÉNÉâÉX
public class DerivedClass : BaseClass
{

    public void DerivedAccess()
    {
        System.Console.WriteLine("pubInt = " + pubInt);
        PubMethod();
        //System.Console.WriteLine("priInt = " + priInt);
        //PriMethod();
        System.Console.WriteLine("proInt = " + proInt);
        ProMethod();
    }

}
