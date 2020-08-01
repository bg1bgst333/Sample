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
        var t = Task.Factory.StartNew(() => // Task.Factory.StartNewでタスクをセットして実行.(戻り値のTask<int>をtに格納.)
        {

            // Funcの実行.
            return Func();  // Funcを実行し, 戻り値を返す.(ここでのreturnの戻り値がtのResultプロパティに入る.)

        }); // 処理内容をラムダ式で書く.

        // 結果の出力処理を続けて行いたいので, ContinueWithで行う.
        t.ContinueWith(x => Console.WriteLine("x.Result( = t.Result) = " + x.Result));  // t.Resultの結果を出力する処理をContinueWithで行う.

        // 終了しないように10秒待機.
        Thread.Sleep(10000);    // 10秒待機.

    }

    // Funcメソッドの定義
    static int Func()
    {

        // 5秒後に10を返す.
        Thread.Sleep(5000); // 5秒待機.
        return 10;  // 10を返す.

    }

}