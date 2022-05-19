// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)
using System.Xml.Serialization; // XMLシリアライザ(System.Xml.Serialization名前空間)

// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // シリアライザの生成.
        XmlSerializer serializer = new XmlSerializer(typeof(UserInfo)); // UserInfoのXmlSerializerオブジェクトserializerを生成.
        Console.WriteLine(serializer);  // そのまま出力.

    }

}