// メインクラス
class MainClass {	// MainClassクラスの定義
	// Javaのエントリポイント
	public static void main(String[] args) {	// mainメソッドの定義

		// boolean型変数の宣言と初期化.
		boolean b1;	// boolean型変数b1の宣言.
		boolean b2 = false;	// boolean型変数b2をfalseに初期化.
		boolean b3;	// boolean型変数b3の宣言.
		int x = 10;	// int型変数xを10に初期化.

		// boolean型変数への代入.
		b1 = true;	// b1にtrueを代入.

		// boolean型変数の出力.
		System.out.println("b1 = " + b1);	// System.out.printlnでb1を出力.
		System.out.println("b2 = " + b2);	// System.out.printlnでb2を出力.

		// 条件式の真偽
		b3 = x == 10;	// xが10かどうかの真偽値をb3に格納.
		System.out.println("b3 = " + b3);	// System.out.printlnでb3を出力.

		// if文での判定
		if (b3){	// b3が真
			System.out.println("b3 is true!");	// System.out.printlnで"b3 is true!"を出力.
		}

	}
}