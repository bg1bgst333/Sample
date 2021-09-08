﻿// 名前空間の登録
using System;   // 共通データ型と基本クラス(System名前空間)
using System.Threading; // マルチスレッド(System.Threading名前空間)

// MainClassの定義
class MainClass
{

    // Mainメソッドの定義
    static void Main()
    {

        // 現在の同期コンテキストを出力.
        Console.WriteLine("SynchronizationContext.Current = " + SynchronizationContext.Current);    // SynchronizationContext.Currentを出力.(コンソールアプリの場合, nullになっている.)

    }

}