// ���O��Ԃ̓o�^
using System;       // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)

// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // string�̐錾.
        //string str1;    // ���������Ȃ�.

        // null.
        string str2 = null; // null�ŏ�����.

        // String.Empty.
        string str3 = String.Empty; // String.Empty("")�ŏ�����.

        // �ʏ핶���񃊃e����.
        string str4 = "C:\\Path\\To\\File.txt";    // "C:\\Path\\To\\File.txt"�ŏ�����.

        // ����I�����񃊃e����.
        string str5 = @"C:\Path\To\File.txt";    // @"C:\Path\To\File.txt"�ŏ�����.

        // const.
        const string STR6 = "XYZ";  // const��"XYZ"�ŏ�����.

        // �I�u�W�F�N�g.
        string baseStr = "abcde";   // baseStr��"abcde"�ŏ�����.
        string str7 = baseStr;  // str7��baseStr�ŏ�����.

        // char�z��.
        char[] chArray = new char[] { 'a', 'b', 'c' };  // chArray��{ 'a', 'b', 'c' }�ŏ�����.
        string str8 = new string(chArray);  // �R���X�g���N�^��chArray��n���ď�����.

        // �R���X�g���N�^�ɕ�����͎w��ł��Ȃ�.
        //string str9 = new string("zzz");    // ������(string)��n���R���X�g���N�^�͖���.

        // �l�̏o��.
        //System.Console.WriteLine("str1 = " + str1);
        System.Console.WriteLine("str2 = " + str2);
        System.Console.WriteLine("str3 = " + str3);
        System.Console.WriteLine("str4 = " + str4);
        System.Console.WriteLine("str5 = " + str5);
        System.Console.WriteLine("STR6 = " + STR6);
        System.Console.WriteLine("str7 = " + str7);
        System.Console.WriteLine("str8 = " + str8);
        //System.Console.WriteLine("str8 = " + str9);

    }

}