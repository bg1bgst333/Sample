// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)
using System.Text;  // テキスト(System.Text名前空間)

// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // StringBuilder同士の比較とそれぞれをobjectに入れた時の比較.
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

        // string同士の比較とそれぞれをobjectに入れた時の比較.
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

        // int同士の比較とそれぞれをobjectに入れた時の比較.
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

        // CustomClass同士の比較とそれぞれをobjectに入れた時の比較.
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