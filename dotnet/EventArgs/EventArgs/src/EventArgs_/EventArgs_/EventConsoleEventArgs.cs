// 名前空間の登録
using System;   // 共通データ型と基本クラス(System名前空間)

// イベントコンソール引数クラス
public class EventConsoleEventArgs : EventArgs  // EventConsoleEventArgsクラスの定義
{

    // メンバの定義
    private bool result = false;    // 内部変数resultをfalseで初期化.
    public bool Result  // trueならループを抜けるプロパティResult.
    {
        get
        {
            return result;
        }
        set
        {
            result = value;
        }
    }
    private string line = "";   // 内部変数lineを""で初期化.
    public string Line    // 入力行文字列を持つプロパティLine.
    {
        get
        {
            return line;
        }
        set
        {
            line = value;
        }
    }
}