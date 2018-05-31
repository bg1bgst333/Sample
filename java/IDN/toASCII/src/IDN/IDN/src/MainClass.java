import java.net.IDN;

// メインクラス
public class MainClass {	// MainClassの定義

	// Javaのエントリポイント
	public static void main(String[] args){	// mainメソッドの定義

		// 変数の初期化.
		String strDomain = "日本語.jp";	// strDomainを"日本語.jp"で初期化.

		// Punycodeへの変換.
		String strPunycode = IDN.toASCII(strDomain);	// IDN.toASCIIでPunycodeへ変換.

		// Punycodeの出力.
		System.out.println(strPunycode);	// strPunycodeを出力.

	}

}