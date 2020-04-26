// メインクラス
public class MainClass{	// MainClassの定義

	// Javaのエントリポイント
	public static void main(String[] args){	// mainメソッドの定義

		// Consumer<Integer>で値を渡す.
		TestClass testClass = new TestClass();	// testClassを取得.
		testClass.method1((x) -> {	// ラムダ式を渡す.
			System.out.println(x);	// xを出力.
		});
		testClass.run(100);	// 100を渡す.

	}

}