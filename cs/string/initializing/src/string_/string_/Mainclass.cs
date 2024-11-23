// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)

// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // stringの宣言.
        //string str1;    // 初期化しない.

        // null.
        string str2 = null; // nullで初期化.

        // String.Empty.
        string str3 = String.Empty; // String.Empty("")で初期化.

        // 通常文字列リテラル.
        string str4 = "C:\\Path\\To\\File.txt";    // "C:\\Path\\To\\File.txt"で初期化.

        // 逐語的文字列リテラル.
        string str5 = @"C:\Path\To\File.txt";    // @"C:\Path\To\File.txt"で初期化.

        // const.
        const string STR6 = "XYZ";  // constで"XYZ"で初期化.

        // オブジェクト.
        string baseStr = "abcde";   // baseStrを"abcde"で初期化.
        string str7 = baseStr;  // str7をbaseStrで初期化.

        // char配列.
        char[] chArray = new char[] { 'a', 'b', 'c' };  // chArrayを{ 'a', 'b', 'c' }で初期化.
        string str8 = new string(chArray);  // コンストラクタにchArrayを渡して初期化.

        // コンストラクタに文字列は指定できない.
        //string str9 = new string("zzz");    // 文字列(string)を渡すコンストラクタは無い.

        // 値の出力.
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