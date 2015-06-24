// メインクラス
class superKeyword {	// superKeywordクラスの定義

	// Javaのエントリポイント
	public static void main(String[] args) {	// mainメソッドの定義

		// オブジェクトsk3の生成.
		superKeyword3 sk3 = new superKeyword3();	// superKeyword3オブジェクトsk3を生成.

		// オブジェクトの持つフィールドの内容を出力.
		sk3.output();	// outputメソッドでフィールドの内容を出力.

		// 整数値と文字列をセット.
		sk3.set(50, "ABCDE");	// superKeyword2のsetで50, "ABCDE"をセット.

		// オブジェクトの持つフィールドの内容を出力.
		sk3.output();	// outputメソッドでフィールドの内容を出力.

		// 整数値, 文字列, 実数値, 真偽値をセット.
		sk3.set(100, "VWXYZ", 0.123f, true);	// superKeyword3のsetで100, "VWXYZ", 0.123f, trueをセット.

		// オブジェクトの持つフィールドの内容を出力.
		sk3.output();	// outputメソッドでフィールドの内容を出力.

	}

}