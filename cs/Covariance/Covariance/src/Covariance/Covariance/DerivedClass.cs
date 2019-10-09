// 派生クラス
class DerivedClass : BaseClass // BaseClassを継承したDerivedClassクラスの定義
{
    // プロパティ
    // Addressプロパティ
    private string address;
    public string Address
    {
        get
        {
            return address;
        }
        set
        {
            address = value;
        }
    }
}