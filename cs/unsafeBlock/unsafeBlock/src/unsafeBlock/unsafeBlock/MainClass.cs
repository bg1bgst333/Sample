// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // int�^n��i23�ŏ�����.
        int n = 123;

        // n���o��.
        System.Console.WriteLine("n = " + n);

        // unsafe�u���b�N�̒��Ń|�C���^���g��.
        unsafe
        {

            // int�^�|�C���^p��n�̃A�h���X�ŏ�����.
            int* p = &n;

            // p�̎Q�Ɛ��456����.
            *p = 456;

        }

        // n���o��.
        System.Console.WriteLine("n = " + n);

    }

}