// メインクラス
class MainClass {	// MainClassクラスの定義

	// Javaのエントリポイント
	public static void main(String[] args) {	// mainメソッドの定義

		// オブジェクトclass1の生成.
		Class1 class1 = new Class1();	// Class1オブジェクトclass1を生成.

		// オブジェクトの持つフィールドの内容を出力.
		class1.output();	// outputメソッドでフィールドの内容を出力.

		// オブジェクトに整数値をセット.
		class1.set(10);	// set(int n)メソッドでclass1に10をセット.

		// オブジェクトの持つフィールドの内容を出力.
		class1.output();	// outputメソッドでフィールドの内容を出力

		// オブジェクトに文字列をセット.
		class1.set("ABC");	// set(String s)メソッドでclass1に"ABC"をセット.

		// オブジェクトの持つフィールドの内容を出力.
		class1.output();	// outputメソッドでフィールドの内容を出力

		// オブジェクトに整数値と文字列をセット.
		class1.set(20, "XYZ");	// set(int n, String s)メソッドでclass1に20と"XYZ"をセット.

		// オブジェクトの持つフィールドの内容を出力.
		class1.output();	// outputメソッドでフィールドの内容を出力

	}

}