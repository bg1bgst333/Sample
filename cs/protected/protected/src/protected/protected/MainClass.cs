// ���C���N���X
class MainClass
{

    // ���C�����\�b�h
    static void Main()
    {

        // ���N���X
        BaseClass baseClass = new BaseClass();

        // public
        System.Console.WriteLine(baseClass.pubInt);
        baseClass.PubMethod();

        // private
        //System.Console.WriteLine(baseClass.priInt);
        //baseClass.PriMethod();

        // protected
        //System.Console.WriteLine(baseClass.proInt);
        //baseClass.ProMethod();

        // �����o����̃A�N�Z�X�͉�.
        baseClass.AccessMember();

        // �h���N���X
        DerivedClass derivedClass = new DerivedClass();
        derivedClass.DerivedAccess();

    }

}