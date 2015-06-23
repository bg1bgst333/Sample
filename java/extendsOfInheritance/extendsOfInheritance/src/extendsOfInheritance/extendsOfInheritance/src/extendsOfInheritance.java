// メインクラス
class extendsOfInheritance {	// extendsOfInheritanceクラスの定義

	// Javaのエントリポイント
	public static void main(String[] args) {	// mainメソッドの定義

		// オブジェクトeoi3の生成.
		extendsOfInheritance3 eoi3 = new extendsOfInheritance3();	// extendsOfInheritance3オブジェクトeoi3を生成.

		// オブジェクトの持つフィールドの内容を出力.
		eoi3.outputAll();	// outputAllメソッドでフィールドの内容を出力.

		// 整数値と文字列をセット.
		eoi3.set(50, "ABCDE");	// extendsOfInheritance2のsetで50, "ABCDE"をセット.

		// オブジェクトの持つフィールドの内容を出力.
		eoi3.outputAll();	// extendsOfInheritance3のoutputAllメソッドでフィールドの内容を出力.

		// 整数値, 文字列, 実数値, 真偽値をセット.
		eoi3.set(100, "VWXYZ", 0.123f, true);	// extendsOfInheritance3のsetで100, "VWXYZ", 0.123f, trueをセット.

		// オブジェクトの持つフィールドの内容を出力.
		eoi3.outputAll();	// extendsOfInheritance3のoutputAllメソッドでフィールドの内容を出力.

	}

}