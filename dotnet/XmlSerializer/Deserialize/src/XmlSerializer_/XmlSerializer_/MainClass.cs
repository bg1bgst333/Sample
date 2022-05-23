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
        
        // オブジェクトの生成.
        UserInfo userInfo = new UserInfo(); // UserInfoオブジェクトを生成.

        // test.xmlをデシリアライズ.
        using (FileStream fs = new FileStream("test.xml", FileMode.Open)) // FileStreamでtest.xmlを開く.
        {
            userInfo = (UserInfo)serializer.Deserialize(fs);  // serializer.DeserializeでfsをuserInfoにデシリアライズ. 
            Console.WriteLine("userInfo.name = " + userInfo.name); // userInfo.nameを出力.
            Console.WriteLine("userInfo.age = " + userInfo.age); // userInfo.ageを出力.
            Console.WriteLine("userInfo.address = " + userInfo.address); // userInfo.addressを出力.
        }

    }

}