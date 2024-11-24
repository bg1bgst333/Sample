// カスタム位置座標クラス
class CustomPoint // CustomPointクラスの定義
{
    // メンバの定義.
    public int x;   // 水平位置座標x.
    public int y;   // 垂直位置座標y
    // コンストラクタ
    public CustomPoint(int x, int y)
    {
        // 引数をメンバにセット.
        this.x = x;
        this.y = y;
    }
    // +演算子のオーバーロード.
    public static CustomPoint operator +(CustomPoint a, CustomPoint b)
    {
        // 各要素を足した新しいインスタンスを返す.
        return new CustomPoint(a.x + b.x, a.y + b.y);
    }
}