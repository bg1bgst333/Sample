// パッケージ・クラスのインポート
import java.io.IOException;	// IOExceptionクラス(java.ioパッケージ)

// メインクラス
class MainClass {	// MainClassクラスの定義

	// Javaのエントリポイント
	public static void main(String[] args) {	// mainメソッドの定義

		// System.out.print
		System.out.print("ABC");	// System.out.printで"ABC"を出力.

		// System.out.println
		System.out.println("XYZ");	// System.out.printlnで"XYZ"を出力.

		// System.out.write
		byte[] bt = new byte[4];	// byte型配列btを用意.
		bt[0] = 0x50;	// P
		bt[1] = 0x51;	// Q
		bt[2] = 0x52;	// R
		bt[3] = 0x53;	// S
		try {	// tryブロック
			System.out.write(bt);	// btをwriteで出力.
		}
		catch (IOException e) {	// IOExceptionが来たら, キャッチしなければならない.
			// 例外処理
			System.out.println("e.toString() = " + e.toString());	// e.toString()の内容を出力.
		}

	}

}