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
        intArray.SetValue(3, 0);    // intArray.SetValue��0�Ԗڂ�3.
        intArray.SetValue(4, 1);    // intArray.SetValue��1�Ԗڂ�4.
        intArray.SetValue(1, 2);    // intArray.SetValue��2�Ԗڂ�1.
        intArray.SetValue(5, 3);    // intArray.SetValue��3�Ԗڂ�5.
        intArray.SetValue(2, 4);    // intArray.SetValue��4�Ԗڂ�2.

        // �l�̏o��.
        for (int i = 0; i < intArray.Length; i++)
        {
            Console.WriteLine("intArray.GetValue({0}) = {1}", i, intArray.GetValue(i));
        }

        // ��؂���̏o��.
        Console.WriteLine("-----");

        // �\�[�g.
        Array.Sort(intArray);   // Array.Sort�Ŋ���̃\�[�g.

        // �l�̏o��.
        for (int i = 0; i < intArray.Length; i++)
        {
            Console.WriteLine("intArray.GetValue({0}) = {1}", i, intArray.GetValue(i));
        }

    }

}