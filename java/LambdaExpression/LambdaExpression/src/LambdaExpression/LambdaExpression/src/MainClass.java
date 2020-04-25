// メインクラス
public class MainClass{	// MainClassの定義

	// Javaのエントリポイント
	public static void main(String[] args){	// mainメソッドの定義

		// 関数型インターフェースが持つ関数をその場で定義.
		TestClass testClass = new TestClass();	// TestClassオブジェクトtestClassを生成.
		testClass.method1(new TestFunctionalInterface(){	// TestFunctionalInterfaceをnewで生成し, funcを実装.
			@Override
			public int func(int x){
				return x * x;	// xの2乗を返す.
			}
		});
		System.out.println(testClass.run(2));	// 2を渡す.

		// ラムダ式で表現.
		TestClass testClass2 = new TestClass();	// TestClassオブジェクトtestClass2を生成.
		testClass.method1((x) -> {	// ラムダ式を渡す.
			return x * x * x;	// xの3乗を返す.
		});
		System.out.println(testClass.run(2));	// 2を渡す.

	}

}