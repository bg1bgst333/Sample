// メインクラス
class MainClass {	// MainClassクラスの定義

	// Javaのエントリポイント
	public static void main(String[] args) {	// mainメソッドの定義

		// BaseClassオブジェクトの生成と出力.
		BaseClass base = new BaseClass();	// BaseClassオブジェクトを生成し, baseに格納.
		base.output();	// base.outputで出力.

		// DerivedClassオブジェクトの生成, 値の設定, 取得, 出力.
		DerivedClass derived = new DerivedClass();	// DerivedClassオブジェクトを生成し, derivedに格納.
		derived.set(10, "ABC");	// setで10, "ABC"を設定.
		int i = derived.getInt();	// getIntで整数値を取得し, iに格納.
		String s = derived.getString();	// getStringで文字列を取得し, sに格納.
		System.out.println("i = " + i + ", s = " + s);	// iとsを出力.
		derived.output();	// derived.outputで出力.

	}

}