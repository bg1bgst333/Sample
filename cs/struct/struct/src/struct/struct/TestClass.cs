// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)

// 文字列を持つクラス
class TestClass // TestClassクラスの定義
{
    // メンバフィールドの定義
    private string str; // string型フィールドstr
    public string Str   // strの設定と取得をするプロパティStr.
    {
        get
        {
            // strを返す.
            return str;
        }
        set
        {
            // strにvalueを格納.
            str = value;
        }
    }
    private int i;  // int型フィールドi
    public int I    // iの設定と取得をするプロパティI.
    {
        get
        {
            // iを返す.
            return i;
        }
        set
        {
            // iにvalueを格納.
            i = value;
        }
    }
    // iとstrを表示.
    public void Show()
    {
        Console.WriteLine("i = " + i + ", str = " + str);
    }
}