// ���O��Ԃ̓o�^
using System;       // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)

// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // long�^��Int64�\���̂̃I�u�W�F�N�g�̐錾.
        long longType;      // long�^�ϐ�longType.
        Int64 longStruct;   // Int64�^�\���̕ϐ�longStruct.

        // �l�̑��.(������longType��longStruct�ɒl��ݒ肵���C���X�^���X���R�s�[�����̂�, ����ȑO�ł̓��\�b�h���ĂׂȂ�.)
        longType = 10;       // longType��10����.
        longStruct = 100;    // longStruct��100����.

        // �^(�\����)�����o��.
        Console.WriteLine("longType: " + longType.GetType().ToString());  // longType.GetType().ToString()�Ŏ擾�ł���^�����o��.
        Console.WriteLine("longStruct: " + longStruct.GetType().ToString());    // longStruct.GetType().ToString()�Ŏ擾�ł���\���̖����o��.

    }

}