// メインクラス
class MainClass {	// MainClassクラスの定義

	// Javaのエントリポイント
	public static void main(String[] args) {	// mainメソッドの定義

		// オブジェクトbaseの生成.
		BaseClass base = new BaseClass();	// BaseClassオブジェクトbaseを生成.
		base.set(10, "ABC");	// BaseClassのsetメソッドで10, "ABC"をセット.
		base.output();	// BaseClassのoutputメソッドで出力.

		// 1行改行
		System.out.println();	// System.out.printlnで改行して1行空ける.

		// オブジェクトderivedの生成.
		DerivedClass derived = new DerivedClass();	// DerivedClassオブジェクトderivedを生成.
		derived.set(20, "XYZ", 1.23f, true);	// DerivedClassのsetメソッドで20, "XYZ", 1.23, trueをセット.
		derived.output();	// DerivedClassのoutputメソッドで出力.

		// 1行改行
		System.out.println();	// System.out.printlnで改行して1行空ける.

		// DerivedClassオブジェクトを生成し, BaseClassのoverrideに格納.
		BaseClass override = new DerivedClass();	// DerivedClassオブジェクトインスタンスをBaseClassオブジェクトoverrideに格納.
		override.set(100, "ABCDE");	// BaseClassのsetメソッドで100, "ABCDE"をセット.
		override.output();	// 実行時にはDerivedClassのoutputメソッドが呼ばれる.(セットしていないfやbが出力される.)

	}

}