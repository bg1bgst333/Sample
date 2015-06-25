// メインクラス
class abstractClass {	// abstractClassクラスの定義

	// Javaのエントリポイント
	public static void main(String[] args) {	// mainメソッドの定義

		// abstractClass3オブジェクトインスタンスをabstractClass2のオブジェクトに格納.
		abstractClass2 aco2_1 = new abstractClass3();	// abstractClass3オブジェクトインスタンスを生成し, abstractClass2オブジェクトaco2_1に格納.

		// aco2_1に値をセット.
		aco2_1.set(10, "ABC");	// setメソッドで10と"ABC"をセット.

		// aco2_1の内容を出力.
		aco2_1.output();	// outputメソッドで整数値と文字列を出力.

		// abstractClass4オブジェクトインスタンスをabstractClass2のオブジェクトに格納.
		abstractClass2 aco2_2 = new abstractClass4();	// abstractClass4オブジェクトインスタンスを生成し, abstractClass2オブジェクトaco2_2に格納.

		// aco2_2に値をセット.
		aco2_2.set(20, "XYZ");	// setメソッドで20と"XYZ"をセット.

		// aco2_2の内容を出力.
		aco2_2.output();	// outputメソッドで整数値と文字列を出力.

	}

}