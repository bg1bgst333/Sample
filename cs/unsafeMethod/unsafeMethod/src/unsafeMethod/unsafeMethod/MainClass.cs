// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // UnsafeMethod���Ă�.
        UnsafeMethod();

    }

    // �A���Z�[�t���\�b�h
    unsafe void UnsafeMethod()
    {

        // int�^n��i23�ŏ�����.
        int n = 123;

        // int�^�|�C���^p��n�̃A�h���X�ŏ�����.
        int* p = &n;

        // p�̎Q�Ɛ��456����.
        *p = 456;

        // n���o��.
        System.Console.WriteLine("n = " + n);

    }

}