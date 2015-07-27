// メインクラス
class MainClass {	// MainClassクラスの定義

	// Javaのエントリポイント
	public static void main(String[] args) {	// mainメソッドの定義

		// オブジェクトの宣言
		String str;	// Stringオブジェクトstr.

		// 出力.
		System.out.println("ABCDE");	// System.out.printlnで"ABCDE"と出力.

		// 環境変数"windir"の値を取得.
		str = System.getenv("windir");	// System.getenvで環境変数"windir"の値を取得し, strに格納.
		System.out.println("System.getenv(\"windir\") = " + str);	// strの値を出力.

		// 終了
		System.exit(0);	// System.exitで終了.(終了コードは0.)

		// ここは呼ばれない.
		System.out.println("No Call.");	// System.out.printlnで"No Call."と出力.(ただし, ここは呼ばれない.)

	}

}