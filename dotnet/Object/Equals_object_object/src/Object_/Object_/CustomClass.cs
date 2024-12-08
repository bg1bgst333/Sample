// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)

// カスタムクラス
public class CustomClass    // CustomClassクラスの定義
{
    public int num; // int型num.
    public CustomClass(int num) // numをもらうコンストラクタ.
    {
        this.num = num; // numを格納.
    }
    public override bool Equals(object obj) // Equalsをオーバーライド.
    {
        Console.WriteLine("Equals Start");
        if (obj == null || !(obj is CustomClass))   // nullまたはCustomClassではない.
        {
            Console.WriteLine("Equals End");
            return false;   // falseを返す.
        }
        else   // CustomClassである.
        {
            Console.WriteLine("Equals End");
            return num == ((CustomClass)obj).num;   // 値を比較.  
        }
    }
}