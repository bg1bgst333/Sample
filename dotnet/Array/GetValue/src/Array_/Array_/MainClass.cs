// ���O��Ԃ̓o�^
using System;   // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)

// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // Array.CreateInstance�Ŕz��쐬.
        Array intArray = Array.CreateInstance(typeof(int), 5);  // int�^�ŗv�f��5.

        // �������o��.
        Console.WriteLine("intArray.Length = " + intArray.Length);  // Array.Length�Œ������擾.

        // 2�Ԗڂ��擾.
        int iVal2 = (int)intArray.GetValue(2);   // Array.GetValue��2�Ԗڂ��擾.
        Console.WriteLine("iVal2 = " + iVal2);  // iVal2���o��.

    }

}