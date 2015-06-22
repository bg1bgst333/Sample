// メインクラス
class Overload {	// Overloadクラスの定義

	// Javaのエントリポイント
	public static void main(String[] args) {	// mainメソッドの定義

		// オブジェクトoverload2の生成.
		Overload2 overload2 = new Overload2();	// Overload2オブジェクトoverload2を生成.

		// オブジェクトの持つフィールドの内容を出力.
		overload2.output();	// outputメソッドでフィールドの内容を出力.

		// オブジェクトに整数値をセット.
		overload2.set(10);	// set(int n)メソッドでoverload2に10をセット.

		// オブジェクトの持つフィールドの内容を出力.
		overload2.output();	// outputメソッドでフィールドの内容を出力

		// オブジェクトに文字列をセット.
		overload2.set("ABC");	// set(String s)メソッドでoverload2に"ABC"をセット.

		// オブジェクトの持つフィールドの内容を出力.
		overload2.output();	// outputメソッドでフィールドの内容を出力

		// オブジェクトに整数値と文字列をセット.
		overload2.set(20, "XYZ");	// set(int n, String s)メソッドでoverload2に20と"XYZ"をセット.

		// オブジェクトの持つフィールドの内容を出力.
		overload2.output();	// outputメソッドでフィールドの内容を出力

	}

}