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

        // �l�̃Z�b�g.
        intArray.SetValue(1, 0);    // intArray.SetValue��0�Ԗڂ�1.
        intArray.SetValue(2, 1);    // intArray.SetValue��1�Ԗڂ�2.
        intArray.SetValue(3, 2);    // intArray.SetValue��2�Ԗڂ�3.
        intArray.SetValue(4, 3);    // intArray.SetValue��3�Ԗڂ�4.
        intArray.SetValue(5, 4);    // intArray.SetValue��4�Ԗڂ�5.

        // �l�̎擾.
        for (int i = 0; i < intArray.Length; i++)
        {
            Console.WriteLine("intArray.GetValue({0}) = {1}", i, intArray.GetValue(i)); // intArray.GetValue(i)���o��.
        }

    }

}