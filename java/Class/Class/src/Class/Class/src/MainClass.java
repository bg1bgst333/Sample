// メインクラス
class MainClass {	// MainClassクラスの定義

	// Javaのエントリポイント
	public static void main(String[] args) {	// mainメソッドの定義

		// オブジェクトの生成.
		Class1 class1 = new Class1();	// Class1オブジェクトclass1を生成.

		// オブジェクトに値をセット.
		class1.set(10, "ABC");	// setメソッドでclass1に10と"ABC"をセット.

		// オブジェクトの持つフィールドの内容を出力.
		class1.output();	// outputメソッドでフィールドの内容を出力.

	}

}