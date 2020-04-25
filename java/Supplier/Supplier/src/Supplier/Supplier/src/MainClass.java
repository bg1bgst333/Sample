// メインクラス
public class MainClass{	// MainClassの定義

	// Javaのエントリポイント
	public static void main(String[] args){	// mainメソッドの定義

		// Supplier<Integer>で値を返す.
		TestClass testClass = new TestClass();	// testClassを取得.
		testClass.method1(() -> {	// ラムダ式を渡す.
			return 10;	// 10を返す.
		});
		System.out.println(testClass.run());	// runの戻り値を出力.

	}

}