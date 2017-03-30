// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)

// 文字列を持つ構造体
struct TestStruct // TestStruct構造体の定義
{
    // メンバフィールドの定義
    public string str; // string型フィールドstr(あえてここをpublicにする.)
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
    public int i;  // int型フィールドi(あえてここをpublicにする.)
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