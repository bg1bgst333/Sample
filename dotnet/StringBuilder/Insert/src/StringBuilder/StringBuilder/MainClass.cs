// ���O��Ԃ̓o�^
using System;   // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)
using System.Text;  // �e�L�X�g(System.Text���O���)

// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // StringBuilder�I�u�W�F�N�g�쐬.
        StringBuilder sb = new StringBuilder("����������"); // StringBuilder�I�u�W�F�N�g��sb�Ɋi�[.(�R���X�g���N�^��"����������"���w��.)

        // StringBuilder�̏o��.
        System.Console.WriteLine(sb.ToString());    // StringBuilder.ToString�Ŏ擾������������o��.

        // "ABC"��}��.
        sb.Insert(2, "ABC");    // StringBuilder.Insert��2�����ڂ̌���"ABC"��}��.

        // StringBuilder�̏o��.
        System.Console.WriteLine(sb.ToString());    // StringBuilder.ToString�Ŏ擾������������o��.

    }

}