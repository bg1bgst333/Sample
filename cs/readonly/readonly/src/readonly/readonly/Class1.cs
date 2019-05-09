// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)

// Class1の定義
class Class1
{

    // フィールドの定義.
    private readonly int size;  // 配列の大きさint型変数size.(readonlyにする.)
    private int[] intArray; // int型配列intArray.

    // コンストラクタの定義
    public Class1(int size)
    {
        // 初期化
        this.size = size;   // this.sizeにsizeをセット.(readonlyはコンストラクタで初期化できる.)
        intArray = new int[size];   // size分の配列を用意.
    }

    // 配列の出力
    public void print()
    {
        // これは不可.
        //size = 20;  // readonlyなので, あとから変更不可.

        // サイズ出力
        Console.WriteLine("size = " + size);    // sizeを出力.
        
        // 配列に値を入れる.
        for (int i = 0; i < size; i++)    // size分繰り返す.
        {
            intArray[i] = i;    // i番目にiを入れる.
        }

        // 配列の表示
        for (int i = 0; i < size; i++)    // size分繰り返す.
        {
            Console.WriteLine("intArray[" + i + "] = " + intArray[i]); // i番目を出力.
        }
    }

}