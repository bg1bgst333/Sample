//メインクラス
class MainClass {	// MainClassクラスの定義

	// Javaのエントリポイント
	public static void main(String[] args) {	// mainメソッドの定義

		// CustomObjectの生成.
		CustomObject obj = new CustomObject();	// CustomObjectオブジェクトobjを生成.

		// 文字列をセット.
		obj.setStr("ABC");	// obj.setStrで"ABC"をセット.

		// 整数値をセット.
		obj.setValue(123);	// obj.setValueで123をセット.

		// obj.toStringを出力.
		System.out.println("obj.toString() = " + obj.toString());	// obj.toString()を出力.

	}

}