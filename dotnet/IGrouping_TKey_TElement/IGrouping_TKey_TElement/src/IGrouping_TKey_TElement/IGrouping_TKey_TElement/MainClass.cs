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

        // いくつのグループに分けられたか出力.
        Console.WriteLine("result.Count() = " + result.Count());    // result.Count()の結果を出力.

        // グループの列挙.
        foreach (IGrouping<string, Member> g in result)
        {
            // そのグループの要素数を出力.
            Console.WriteLine(g.Count());
        }

    }

}