// 名前空間の登録
using System;       // 共通データ型と基本クラス(System名前空間)

// デリゲートの宣言
public delegate void EventDelegate(string inputString);    // 引数がstringで戻り値がvoidのdelegateを宣言.

// 入力チェッククラス
public class InputCheckClass // InputCheckクラスの定義
{

    // メンバフィールドの定義
    private string target;  // イベント発生条件となる文字列target.
    public event EventDelegate callback;    // EventDelegate型のevent用デリゲート変数callback.
    
    // メンバメソッドの定義
    // コンストラクタ
    public InputCheckClass(string target)
    {

        // 引数をメンバにセット.
        this.target = target;   // this.targetにtargetを格納.

    }

    // メンバメソッド
    public void InputCheckLoop()    // 入力チェックループメソッドInputCheckLoop
    {

        // 入力文字列をチェック.
        do
        {
            string str = Console.ReadLine();    // Console.ReadLineで読み込んだ文字列をstrに格納.
            if (str == target)  // strとtargetが同じなら.
            {
                callback(str);  // callbackを実行.
                break; // このループを抜ける.
            }
        }
        while (true);   // 常にtrue.

    }

}