// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)
using System.Xml.Serialization; // XMLシリアライザ(System.Xml.Serialization名前空間)
using System.IO;    // ファイル入出力とデータストリーム(System.IO名前空間)

// メインクラス
class MainClass // MainClassクラスの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // シリアライザの生成.
        XmlSerializer serializer = new XmlSerializer(typeof(UserInfo)); // UserInfoのXmlSerializerオブジェクトserializerを生成.
        
        // オブジェクトの生成と初期化.
        UserInfo userInfo = new UserInfo(); // UserInfoオブジェクトを生成.
        userInfo.name = "Taro";
        userInfo.age = 20;
        userInfo.address = "Tokyo";

        // test.xmlにオブジェクトをシリアライズ.
        using (FileStream fs = new FileStream("test.xml", FileMode.Create)) // FileStreamでtest.xmlを開く.
        {
            serializer.Serialize(fs, userInfo); // serializer.SerializeでfsにuserInfoをシリアライズ.
        }

    }

}