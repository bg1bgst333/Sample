// ���C���N���X
class MainClass
{

    // ���C�����\�b�h
    static void Main()
    {

        // ���N���X
        BaseClass baseClass = new BaseClass();
        // public(�C���X�^���X)
        baseClass.pubInt = 10;
        // public static
        BaseClass.pubStaInt = 100;

        // public(�C���X�^���X)�ւ̃A�N�Z�X.
        System.Console.WriteLine(baseClass.pubInt);
        baseClass.PubMethod();
        // public static�ւ̃A�N�Z�X
        System.Console.WriteLine(BaseClass.pubStaInt);
        BaseClass.PubStaMethod();

    }

}