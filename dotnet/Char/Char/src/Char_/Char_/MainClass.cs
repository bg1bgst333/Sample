// ���O��Ԃ̓o�^
using System;       // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)

// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // char�^��Char�\���̂̃I�u�W�F�N�g�̐錾.
        char charType;      // char�^�ϐ�charType.
        Char charStruct;   // Char�^�\���̕ϐ�charStruct.

        // �l�̑��.
        charType = 'A';     // charType��'A'����.
        charStruct = 'B';   // charStruct��'B'����.

        // �^(�\����)�����o��.
        Console.WriteLine("charType: " + charType.GetType().ToString());  // charType.GetType().ToString()�Ŏ擾�ł���^�����o��.
        Console.WriteLine("charStruct: " + charStruct.GetType().ToString());    // charStruct.GetType().ToString()�Ŏ擾�ł���\���̖����o��.

    }

}