// メインクラス
class MainClass {	// MainClassクラスの定義

	// Javaのエントリポイント
	public static void main(String[] args) {	// mainメソッドの定義

		// オブジェクトclass1_1の生成.
		Class1 class1_1 = new Class1();	// Class1オブジェクトclass1_1を生成.

		// オブジェクトの持つフィールドの内容を出力.
		class1_1.output();	// outputメソッドでフィールドの内容を出力.

		// オブジェクトに値をセット.
		class1_1.set(10, "ABC");	// setメソッドでclass1_1に10と"ABC"をセット.

		// オブジェクトの持つフィールドの内容を出力.
		class1_1.output();	// outputメソッドでフィールドの内容を出力.

		// オブジェクトclass1_2の生成.
		Class1 class1_2 = new Class1(20, "XYZ");	// Class1オブジェクトclass1_2を生成.(初期値に20, "XYZ"をセット.)

		// オブジェクトの持つフィールドの内容を出力.
		class1_2.output();	// outputメソッドでフィールドの内容を出力.

		// オブジェクトに値をセット.
		class1_2.set(30, "zzz");	// setメソッドでclass1_2に30と"zzz"をセット.

		// オブジェクトの持つフィールドの内容を出力.
		class1_2.output();	// outputメソッドでフィールドの内容を出力.

	}

}