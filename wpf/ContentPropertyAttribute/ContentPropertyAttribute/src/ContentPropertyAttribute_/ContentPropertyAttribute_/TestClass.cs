// 名前空間の登録
using System.Collections.ObjectModel;   // コレクションオブジェクトモデルクラス(System.Collections.ObjectModel名前空間)
using System.Windows.Markup;    // マークアップ(System.Windows.Markup名前空間)

// 名前空間
namespace BGST
{

    // テストクラス
    [ContentProperty("TestCollection")]
    public class TestClass  // TestClassの定義
    {

        // コンストラクタ
        public TestClass()
        {
            // コレクションの初期化.
            TestCollection = new TestClassCollection(); // TestClassCollectionを生成.
        }

        // 普通の文字列プロパティ.
        private string testProperty;    // string型のフィールドtestProperty.
        public string TestProperty
        {
            // 取得
            get
            {
                return testProperty;    // testPropertyを返す.
            }
            // 設定
            set
            {
                testProperty = value;   // testPropertyに代入.
            }
        }

        // 自身のコレクションのプロパティ.
        public TestClassCollection TestCollection
        {
            get;
            set;
        }

    }

}