// スワップクラス
class Swap<T>   // Swap<T>クラスの定義
{

    // メンバフィールドの定義
    private T x;    // T型フィールドx.
    public T X     // T型値を返すプロパティX.
    {
        get // 取得時
        {
            return x;   // xを返す.
        }
        set // 設定時
        {
            x = value;  // 渡された値をxに格納.
        }
    }
    private T y;    // T型フィールドy.
    public T Y     // T型値を返すプロパティY.
    {
        get // 取得時
        {
            return y;   // yを返す.
        }
        set // 設定時
        {
            y = value;  // 渡された値をyに格納.
        }
    }

    // メンバメソッドの定義
    public void DoSwap()    // スワップ実行メソッドDoSwap
    {

        // 変数の宣言
        T tmp;  // T型一時変数tmp.

        // スワップ処理.
        tmp = X;    // tmpにXを格納.
        X = Y;      // XにYを格納.
        Y = tmp;    // Yにtmpを格納.

    }

}