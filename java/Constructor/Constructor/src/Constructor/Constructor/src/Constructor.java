// メインクラス
class Constructor {	// Constructorクラスの定義

	// Javaのエントリポイント
	public static void main(String[] args) {	// mainメソッドの定義

		// オブジェクトconstructor2の生成.
		Constructor2 constructor2 = new Constructor2();	// Constructor2オブジェクトconstructor2を生成.

		// オブジェクトの持つフィールドの内容を出力.
		constructor2.output();	// outputメソッドでフィールドの内容を出力.

		// オブジェクトに値をセット.
		constructor2.set(10, "ABC");	// setメソッドでconstructor2に10と"ABC"をセット.

		// オブジェクトの持つフィールドの内容を出力.
		constructor2.output();	// outputメソッドでフィールドの内容を出力.

		// オブジェクトconstructor2_2の生成.
		Constructor2 constructor2_2 = new Constructor2(20, "XYZ");	// Constructor2オブジェクトconstructor2_2を生成.(初期値に20, "XYZ"をセット.)

		// オブジェクトの持つフィールドの内容を出力.
		constructor2_2.output();	// outputメソッドでフィールドの内容を出力.

		// オブジェクトに値をセット.
		constructor2_2.set(30, "zzz");	// setメソッドでconstructor2_2に30と"zzz"をセット.

		// オブジェクトの持つフィールドの内容を出力.
		constructor2_2.output();	// outputメソッドでフィールドの内容を出力.

	}

}