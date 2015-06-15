// メインクラス
class Class {	// Classクラスの定義

	// Javaのエントリポイント
	public static void main(String[] args) {	// mainメソッドの定義

		// オブジェクトの生成.
		Class2 class2 = new Class2();	// Class2オブジェクトclass2を生成.

		// オブジェクトに値をセット.
		class2.set(10, "ABC");	// setメソッドでclass2に10と"ABC"をセット.

		// オブジェクトの持つフィールドの内容を出力.
		class2.output();	// outputメソッドでフィールドの内容を出力.

	}

}