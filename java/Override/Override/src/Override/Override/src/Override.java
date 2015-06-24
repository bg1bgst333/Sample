// メインクラス
class Override {	// Overrideクラスの定義

	// Javaのエントリポイント
	public static void main(String[] args) {	// mainメソッドの定義

		// オブジェクトo2の生成.
		Override2 o2 = new Override2();	// Override2オブジェクトo2を生成.
		o2.set(10, "ABC");	// Override2のsetメソッドで10, "ABC"をセット.
		o2.output();	// Override2のoutputメソッドで出力.

		// 1行改行
		System.out.println();	// System.out.printlnで改行して1行空ける.

		// オブジェクトo3の生成.
		Override3 o3 = new Override3();	// Override3オブジェクトo3を生成.
		o3.set(20, "XYZ", 1.23f, true);	// Override3のsetメソッドで20, "XYZ", 1.23, trueをセット.
		o3.output();	// Override3のoutputメソッドで出力.

		// 1行改行
		System.out.println();	// System.out.printlnで改行して1行空ける.

		// Override3オブジェクトを生成し, overrideに格納.
		Override2 override = new Override3();	// Override3オブジェクトインスタンスをOverride2オブジェクトoverrideに格納.
		override.set(100, "ABCDE");	// Override2のsetメソッドで100, "ABCDE"をセット.
		override.output();	// 実行時にはOverride3のoutputメソッドが呼ばれる.(セットしていないfやbが出力される.)

	}

}