﻿// 名前空間の登録
using System;   // 共通データ型と基本クラス(System名前空間)
using System.Threading; // マルチスレッド(System.Threading名前空間)
using System.Threading.Tasks;   // タスク(System.Threading.Tasks名前空間)

// MainClassの定義
class MainClass
{

    // Mainメソッドの定義
    static void Main()
    {

        // タスクの実行
        var t = Task<string>.Factory.StartNew(() => { // Task.Factory.StartNewでタスクをセットして実行.

             // Funcの実行.
            return Func();  // Funcを実行し, 戻り値を返す.

        }); // 処理内容をラムダ式で書く.

        // 結果を待って出力.
        Console.WriteLine(t.Result);    // t.Resultは確定するまで待ってくれる.

    }

    // Funcメソッドの定義
    static string Func()
    {

        // 5秒後に"ABC"を返す.
        Thread.Sleep(5000); // 5秒待機.
        return "ABC";  // "ABC"を返す.

    }

}