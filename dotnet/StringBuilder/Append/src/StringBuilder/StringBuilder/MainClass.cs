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

        // "ABC"��ǉ�.
        sb.Append("ABC");   // StringBuilder.Append��"ABC"��ǉ�.

        // "123"��ǉ�.
        sb.Append("123");   // StringBuilder.Append��"123"��ǉ�.

        // StringBuilder�̏o��.
        System.Console.WriteLine(sb.ToString());    // StringBuilder.ToString�Ŏ擾������������o��.

    }

}