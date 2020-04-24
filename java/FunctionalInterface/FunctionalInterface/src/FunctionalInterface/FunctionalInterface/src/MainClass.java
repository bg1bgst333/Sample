// メインクラス
public class MainClass{	// MainClassの定義

	// Javaのエントリポイント
	public static void main(String[] args){	// mainメソッドの定義

		// 関数型インターフェースにstaticメソッドを渡す.
		TestFunctionalInterface tfi = MainClass::func;	// tfiにfuncを渡す.
		System.out.println(tfi.func(2));	// 2を渡した結果を出力.

	}

	// 渡すstaticメソッドの実装.
	public static int func(int x){
		return x * x;	// xの2乗を返す.
	}

}