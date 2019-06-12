// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)

// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // int型変数のToString().
        int i = 10; // int型のiに10を代入.
        string str1 = i.ToString(); // str1にi.ToString()の戻り値を格納.
        Console.WriteLine("str1 = " + str1);  // str1の内容を出力.
        str1 = ((Object)i).ToString();  // ObjectにキャストしてToString()でstr1に格納.
        Console.WriteLine("str1 = " + str1);  // str1の内容を出力.

        // 配列のToString().
        int[] array = new int[3];   // int型配列array(要素数3.)
        array[0] = 0;   // 0番目は0.
        array[1] = 1;   // 1番目は1.
        array[2] = 2;   // 2番目は2.
        string str2 = array.ToString(); // str2にarray.ToString()の戻り値を格納.
        Console.WriteLine("str2 = " + str2);  // str2の内容を出力.
        str2 = ((Object)array).ToString();  // ObjectにキャストしてToString()でstr2に格納.
        Console.WriteLine("str2 = " + str2);  // str2の内容を出力2

        // BaseClassオブジェクトのToString().
        BaseClass obj = new BaseClass();    // newでBaseClassオブジェクトを生成し, objに格納.
        string str3 = obj.ToString();    // str3にobj.ToString()の戻り値を格納.
        Console.WriteLine("str3 = " + str3);  // str3の内容を出力.
        str3 = ((Object)obj).ToString();    // ObjectにキャストしてToString()でstr3に格納.
        Console.WriteLine("str3 = " + str3);  // str3の内容を出力.

    }

}