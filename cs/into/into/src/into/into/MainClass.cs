// 名前空間の登録
using System;   // 共通データ型と基本クラス(System名前空間)
using System.Collections.Generic;   // ジェネリクスコレクションクラス(System.Collections.Generic名前空間)
using System.Linq;  // LINQクラス(System.Linq名前空間)

// メインクラス
class MainClass // MainClassの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // メンバーリストの生成.
        var members = new List<Member>();   // MemberクラスのListを生成し, membersに格納.

        // メンバーの追加.
        members.Add(new Member("Suzuki", 33, "Tokyo")); // members.Addで"Suzuki"を追加.
        members.Add(new Member("Sato", 30, "Saitama")); // members.Addで"Sato"を追加.
        members.Add(new Member("Takahashi", 28, "Osaka"));  // members.Addで"Takahashi"を追加.
        members.Add(new Member("Tanaka", 26, "Osaka")); // members.Addで"Tanaka"を追加.
        members.Add(new Member("Kobayashi", 24, "Tokyo")); // members.Addで"Kobayashi"を追加.

        // LINQでメンバーの出身地でグループ化.
        var result = from member in members group member by member.Birthplace;  // group-byでmember.Birthplaceでグループ化の結果をresultに格納.
        
        // 全グループの列挙.
        foreach (var g in result)
        {

            // キーの出力.
            Console.WriteLine("g.Key = " + g.Key);    // g.Keyを出力.
            
            // 要素の列挙.
            foreach (var e in g)
            {
                Console.WriteLine("e.Name = " + e.Name);   // e.Nameを出力.
            }

        }

        // 区切り線.
        Console.WriteLine("-----");

        // 出身地を"東京"に絞る.
        var tokyo = from member in members
                    group member by member.Birthplace into g    // intoでクエリ結果をいったんgに格納.
                    where g.Key == "Tokyo"  // Keyは"Tokyo".
                    select g;   // gを選択.

        // 再び列挙.
        foreach (var t in tokyo)
        {

            // キーの出力.
            Console.WriteLine("t.Key = " + t.Key);    // t.Keyを出力.

            // 要素の列挙.
            foreach (var e in t)
            {
                Console.WriteLine("e.Name = " + e.Name);   // e.Nameを出力.
            }

        }

    }

}