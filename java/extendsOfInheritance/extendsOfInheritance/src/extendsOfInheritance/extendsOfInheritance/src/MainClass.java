// メインクラス
class MainClass {	// MainClassクラスの定義

	// Javaのエントリポイント
	public static void main(String[] args) {	// mainメソッドの定義

		// オブジェクトderivedの生成.
		DerivedClass derived = new DerivedClass();	// DerivedClassオブジェクトderivedを生成.

		// オブジェクトの持つフィールドの内容を出力.
		derived.outputAll();	// DerivedClassのoutputAllメソッドでフィールドの内容を出力.

		// 整数値と文字列をセット.
		derived.set(50, "ABCDE");	// BaseClassのsetで50, "ABCDE"をセット.

		// オブジェクトの持つフィールドの内容を出力.
		derived.outputAll();	// DerivedClassのoutputAllメソッドでフィールドの内容を出力.

		// 整数値, 文字列, 実数値, 真偽値をセット.
		derived.set(100, "VWXYZ", 0.123f, true);	// DerivedClassのsetで100, "VWXYZ", 0.123f, trueをセット.

		// オブジェクトの持つフィールドの内容を出力.
		derived.outputAll();	// DerivedClassのoutputAllメソッドでフィールドの内容を出力.

	}

}