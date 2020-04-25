// テストクラス
public class TestClass {
	// フィールド
	TestFunctionalInterface tif = null;	// nullで初期化.
	// メソッド
	public void method1(TestFunctionalInterface tif){
		this.tif = tif;	// tifをメンバにセット.
	}
	public int run(int x){	// xをもらって実行.
		return tif.func(x);	// tif.funcにxを渡して戻り値を返す.
	}
}
