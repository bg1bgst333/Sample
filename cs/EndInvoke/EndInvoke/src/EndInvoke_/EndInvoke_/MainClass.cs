// 名前空間の登録
using System;           // 共通データ型と基本クラス(System名前空間)
using System.Threading; // マルチスレッド(System.Threading名前空間)

// デリゲートの定義.
delegate int AsyncronousFuncDelegate(int a, int b, ref int refValue);   // 引数がint, int, ref intで, 戻り値がintの関数を持つデリゲートAsyncronousFuncDelegate.

// MainClassの定義
class MainClass
{
    // Mainメソッドの定義
    static void Main()
    {

        // 変数の宣言・初期化.
        int result;         // 計算結果を格納するint型result.
        int refValue = 0;   // AsyncronousFuncに参照渡しで渡すint型refValueを0で初期化.

        // デリゲートの生成.
        AsyncronousFuncDelegate asyncronousFunc = new AsyncronousFuncDelegate(AsyncronousFunc); // AsyncronousFuncを非同期実行するAsyncronousFuncDelegateオブジェクトasyncronousFuncを生成.

        // 非同期処理の実行.
        IAsyncResult iar = asyncronousFunc.BeginInvoke(10, 20, ref refValue, null, null);    // コンパイラによって生成されたasyncronousFunc.BeginInvokeで非同期実行し, 戻り値のIAsyncResultオブジェクトをiarに格納.(引数として10, 20, refValueを渡す.)

        // "Calculating..."と出力.
        Console.WriteLine("Calculating...");    // "Calculating..."と出力.

        // 計算結果の取得.
        result = asyncronousFunc.EndInvoke(ref refValue, iar); // asyncronousFunc.EndInvokeで完了まで待って, 計算結果を取得する.(resultにもrefValueにも計算結果が格納されている.)

        // 計算結果の出力.
        Console.WriteLine("result = " + result);        // resultの値を出力.
        Console.WriteLine("refValue = " + refValue);    // refValueの値を出力.

    }

    // 非同期処理スタティックメソッドAsyncronousFunc.
    static int AsyncronousFunc(int a, int b, ref int refValue)
    {

        // 変数の宣言
        int result; // 計算結果を一時的に格納するint型result.

        // 計算
        result = a + b; ;   // aとbを足した結果をresultに格納.

        // 5秒休止.
        Thread.Sleep(5000); // Thread.Sleepで5秒休止.

        // refValueに格納.
        refValue = result;  // refValueにresultを格納.

        // 戻り値を返す.
        return result;  // returnでresultを返す.

    }

}