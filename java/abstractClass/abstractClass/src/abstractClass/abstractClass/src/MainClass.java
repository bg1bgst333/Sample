// メインクラス
class MainClass {	// MainClassクラスの定義

	// Javaのエントリポイント
	public static void main(String[] args) {	// mainメソッドの定義

		// DerivedClass1オブジェクトインスタンスをAbstractClassのオブジェクトに格納.
		AbstractClass abstract1 = new DerivedClass1();	// DerivedClass1オブジェクトインスタンスを生成し, AbstractClassオブジェクトabstract1に格納.

		// abstract1に値をセット.
		abstract1.set(10, "ABC");	// setメソッドで10と"ABC"をセット.

		// abstract1の内容を出力.
		abstract1.output();	// outputメソッドで整数値と文字列を出力.

		// DerivedClass2オブジェクトインスタンスをAbstractClassのオブジェクトに格納.
		AbstractClass abstract2 = new DerivedClass2();	// DerivedClass2オブジェクトインスタンスを生成し, AbstractClassオブジェクトabstract2に格納.

		// abstract2に値をセット.
		abstract2.set(20, "XYZ");	// setメソッドで20と"XYZ"をセット.

		// abstract2の内容を出力.
		abstract2.output();	// outputメソッドで整数値と文字列を出力.

	}

}