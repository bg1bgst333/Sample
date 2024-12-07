// ���O��Ԃ̓o�^
using System;       // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)
using System.Text;  // �e�L�X�g(System.Text���O���)

// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // StringBuilder���m�̔�r�Ƃ��ꂼ���object�ɓ��ꂽ���̔�r.
        StringBuilder sb1 = new StringBuilder("ABC");
        StringBuilder sb2 = new StringBuilder("ABC");
        StringBuilder sb3 = sb1;
        object object1 = sb1;
        object object2 = sb2;
        object object3 = sb3;
        Console.WriteLine(sb1.Equals(sb2));
        Console.WriteLine(sb1.Equals(sb3));
        Console.WriteLine(object1.Equals(object2));
        Console.WriteLine(object1.Equals(object3));
        Console.WriteLine(object.ReferenceEquals(object1, object2));
        Console.WriteLine(object.ReferenceEquals(object1, object3));

        // string���m�̔�r�Ƃ��ꂼ���object�ɓ��ꂽ���̔�r.
        Console.WriteLine("-----");
        string str1 = "ABC";
        string str2 = "ABC";
        str1 = str1 + "D";
        str2 = "ABCD";
        string str3 = str1;
        object object4 = str1;
        object object5 = str2;
        object object6 = str3;
        Console.WriteLine(str1.Equals(str2));
        Console.WriteLine(str1.Equals(str3));
        Console.WriteLine(object4.Equals(object5));
        Console.WriteLine(object4.Equals(object6));
        Console.WriteLine(object.ReferenceEquals(object4, object5));
        Console.WriteLine(object.ReferenceEquals(object4, object6));

        // int���m�̔�r�Ƃ��ꂼ���object�ɓ��ꂽ���̔�r.
        Console.WriteLine("-----");
        int int1 = 10;
        int int2 = 20;
        int1 = int1 + 20;
        int2 = int2 + 10;
        int int3 = int1;
        object object7 = int1;
        object object8 = int2;
        object object9 = int3;
        Console.WriteLine(int1.Equals(int2));
        Console.WriteLine(int1.Equals(int3));
        Console.WriteLine(object7.Equals(object8));
        Console.WriteLine(object7.Equals(object9));
        Console.WriteLine(object.ReferenceEquals(object7, object8));
        Console.WriteLine(object.ReferenceEquals(object7, object9));

        // CustomClass���m�̔�r�Ƃ��ꂼ���object�ɓ��ꂽ���̔�r.
        Console.WriteLine("-----");
        CustomClass cc1 = new CustomClass();
        cc1.num = 10;
        CustomClass cc2 = new CustomClass();
        cc2.num = 10;
        CustomClass cc3 = cc1;
        object object10 = cc1;
        object object11 = cc2;
        object object12 = cc3;
        Console.WriteLine(cc1.Equals(cc2));
        Console.WriteLine(cc1.Equals(cc3));
        Console.WriteLine(object10.Equals(object11));
        Console.WriteLine(object10.Equals(object12));
        Console.WriteLine(object.ReferenceEquals(object10, object11));
        Console.WriteLine(object.ReferenceEquals(object10, object12));

    }

}