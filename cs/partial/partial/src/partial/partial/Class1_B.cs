// Class1の定義(B)
partial class Class1
{
    public Class1()
    {
        // 初期化.
        this.x = 0; // メンバのxを0に初期化.
        this.y = 0; // メンバのyを0に初期化.
        this.result = 0;    // メンバのresultを0に初期化.
    }
    public void Add(int x, int y)   // 加算メソッドAdd.
    {
        // 加算.
        this.x = x; // xをメンバにセット.
        this.y = y; // yをメンバにセット.
        this.result = this.x + this.y;  // this.xとthis.yの加算結果をthis.resultに格納.
    }
    public int GetResult()  // 結果取得メソッドGetResult.
    {
        // 結果.
        return result;  // メンバresultを返す.
    }
}
