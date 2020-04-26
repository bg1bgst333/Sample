// メインクラス
public class MainClass{	// MainClassの定義

	// Javaのエントリポイント
	public static void main(String[] args){	// mainメソッドの定義

		// Predicate<Integer>で値を渡す.
		TestClass testClass = new TestClass();	// testClassを取得.
		testClass.method1((x) -> {	// ラムダ式を渡す.
			// xが0以上かどうかを判定.
			if (x >= 0){	// xが0以上.
				return true;	// trueを返す.
			}
			else{	// xが負の値.
				return false;	// falseを返す.
			}
		});
		System.out.println(testClass.run(1));	// 1を渡した戻り値を出力.

	}

}