// ���O��Ԃ̓o�^
using System;       // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)

// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // char�^�z��̏�����.
        char[] chArray = new char[] { 'A', 'B', 'C', 'D', 'E' };    // chArray��{'A', 'B', 'C', 'D', 'E'}�ŏ�����.
        
        // String�̃R���X�g���N�^��char�^�z���n��.
        String str = new String(chArray);   // �R���X�g���N�^��chArray��n��.

        // str���o��.
        Console.WriteLine(str); // Console.WriteLine��str���o��.

    }

}