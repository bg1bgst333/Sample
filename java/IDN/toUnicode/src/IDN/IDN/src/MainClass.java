import java.net.IDN;

// メインクラス
public class MainClass {	// MainClassの定義

	// Javaのエントリポイント
	public static void main(String[] args){	// mainメソッドの定義

		// 変数の初期化.
		String strDomain = "xn--wgv71a119e.jp";	// strDomainを"xn--wgv71a119e.jp"で初期化.

		// Punycodeから日本語への変換.
		String strUnicode = IDN.toUnicode(strDomain);	// IDN.toUnicodeで日本語への変換.

		// 日本語の出力.
		System.out.println(strUnicode);	// strUnicodeを出力.

	}

}