// メインクラス
class implementsOfinterface {	// implementsOfinterfaceクラスの定義

	// Javaのエントリポイント
	public static void main(String[] args) {	// mainメソッドの定義

		// implementsOfinterface2オブジェクトの生成と出力.
		implementsOfinterface2 ii2 = new implementsOfinterface2();	// implementsOfinterface2オブジェクトを生成し, ii2に格納.
		ii2.output();	// outputで出力.

		// implementsOfinterface5オブジェクトの生成, 値の設定, 取得, 出力.
		implementsOfinterface5 ii5 = new implementsOfinterface5();	// implementsOfinterface5オブジェクトを生成し, ii5に格納.
		ii5.set(10, "ABC");	// setで10, "ABC"を設定.
		int i = ii5.getInt();	// getIntで整数値を取得し, iに格納.
		String s = ii5.getString();	// getStringで文字列を取得し, sに格納.
		System.out.println("i = " + i + ", s = " + s);	// iとsを出力.
		ii5.output();	// ii5の内容を出力.

	}

}