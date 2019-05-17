// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)
using System.IO;    // ファイル入出力とデータストリーム(System.IO名前空間)

// メインクラス
class MainClass // MainClassの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // ファイルチェックデリゲートを定義済みデリゲートPredicate<T>で生成.(処理内容をラムダ式で定義.)
        Predicate<string> fcd = (filename) =>
        {

            // ファイルが存在するかをチェック.
            if (File.Exists(filename))  // File.Existsでfilenameなるファイルが存在するかチェック.
            {

                // 存在する場合.
                Console.WriteLine(filename + " is Exists."); // "Exists"と出力.
                return true;    // trueを返す.

            }
            else
            {

                // 存在しない場合.
                Console.WriteLine(filename + " is not Exists."); // "not Exists"と出力.
                return false;    // falseを返す.

            }

        };

        // "test.txt"があるかどうかチェック.
        if (fcd("test.txt"))    // fcdに"test.txt"を渡す.
        {

            // OK
            Console.WriteLine("Check OK."); // "Check OK."と出力.

        }
        else
        {

            // NG
            Console.WriteLine("Check NG."); // "Check NG."と出力.

        }

    }

}