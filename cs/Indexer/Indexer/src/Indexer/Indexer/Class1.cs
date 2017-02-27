// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)

// Class1の定義
class Class1
{
    // フィールドの定義.
    private int size;   // 配列の大きさsize.
    private int[] intArray; // int型配列intArray;

    // コンストラクタの定義
    public Class1(int size)
    {
        intArray = new int[size];   // size分の配列を用意.
        this.size = size;   // メンバにセット.
    }

    // インデクサの定義
    public int this[int index]
    {    // index番目の処理.
        // 取得時.
        get
        {
            if (index < 0)  // indexが負はエラー.
            {
                Console.WriteLine("invalid!(index < 0)");    // "invalid!(index < 0)"を出力.
                return -1;  // -1を返す.
            }
            else if (index > size - 1)  // indexがsize - 1より大きい場合もエラー.
            {
                Console.WriteLine("invalid!(index > size - 1)");    // "invalid!(index > size - 1)"を出力.
                return -1;  // -1を返す.
            }
            else
            {
                return intArray[index]; // intArrayのindex番目の値を返す.
            }
        }
        // 設定時.
        set
        {
            if (index < 0)  // indexが負はエラー.
            {
                Console.WriteLine("invalid!(index < 0)");    // "invalid!(index < 0)"を出力.
            }
            else if (index > size - 1)  // indexがsize - 1より大きい場合もエラー.
            {
                Console.WriteLine("invalid!(index > size - 1)");    // "invalid!(index > size - 1)"を出力.
            }
            else if (value < 0)  // 負の値ならエラー
            {
                Console.WriteLine("invalid!(value < 0)");    // "invalid!(value < 0)"を出力.
            }
            else // 0以上なら値を設定.
            {
                intArray[index] = value;    // intArrayのindex番目にvalueをセット.
            }
        }
    }
}