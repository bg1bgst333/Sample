// 名前空間BGST
namespace BGST
{

    // テストクラス
    public class TestClass  // TestClassの定義
    {

        // フィールド
        public int testField;   // int型のフィールドtestField.

        // プロパティ
        private int testPropertyNum;    // int型のフィールドtestPropertyNum.
        public int TestPropertyNum  // int型のプロパティTestPropertyNum.
        {

            // 取得
            get
            {
                // testPropertyNumを返す.
                return testPropertyNum; // returnでtestPropertyNumを返す.
            }

            // 設定
            set
            {
                // testPropertyNumに格納.
                testPropertyNum = value;    // valueをtestPropertyNumに格納.
            }

        }

        // コンストラクタ
        public TestClass()  // コンストラクタTestClass.
        {

            // メンバの初期化.
            testField = 10; // testFieldを10で初期化.

        }

        // メソッド
        public int GetTestField()   // testFieldを返すGetTestField.
        {

            // testFieldを返す.
            return testField;   // returnでtestFieldを返す.

        }

    }

}