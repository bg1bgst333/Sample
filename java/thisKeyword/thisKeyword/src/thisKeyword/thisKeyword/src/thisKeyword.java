// メインクラス
class thisKeyword {	// thisKeywordクラスの定義

	// Javaのエントリポイント
	public static void main(String[] args) {	// mainメソッドの定義

		// オブジェクトthiskey2の生成.
		thisKeyword2 thiskey2 = new thisKeyword2();	// thisKeyword2オブジェクトthiskey2を生成.

		// オブジェクトの持つフィールドの内容を出力.
		thiskey2.output();	// outputメソッドでフィールドの内容を出力.

		// オブジェクトに整数値をセット.
		thiskey2.set(10);	// set(int i)メソッドでthiskey2に10をセット.

		// オブジェクトの持つフィールドの内容を出力.
		thiskey2.output();	// outputメソッドでフィールドの内容を出力

		// オブジェクトに文字列をセット.
		thiskey2.set("ABC");	// set(String str)メソッドでthiskey2に"ABC"をセット.

		// オブジェクトの持つフィールドの内容を出力.
		thiskey2.output();	// outputメソッドでフィールドの内容を出力

		// オブジェクトに整数値と文字列をセット.
		thiskey2.set(20, "XYZ");	// set(int i, String str)メソッドでthiskey2に20と"XYZ"をセット.

		// オブジェクトの持つフィールドの内容を出力.
		thiskey2.output();	// outputメソッドでフィールドの内容を出力

	}

}