// メインクラス
public class MainClass{	// MainClassの定義

	// Javaのエントリポイント
	public static void main(String[] args){	// mainメソッドの定義

		// Function<Integer, Integer>で値を渡す.
		TestClass testClass = new TestClass();	// testClassを取得.
		testClass.method1((x) -> {	// ラムダ式を渡す.
			return x * x;	// xの2乗を返す.
		});
		System.out.println(testClass.run(5));	// 5を渡した戻り値を出力.

	}

}