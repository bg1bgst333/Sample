// メインクラス
public class MainClass{

	// Javaのエントリポイント
	public static void main(String[] arg){ // mainメソッドの定義

		// 文字列の定義.
		String str1 = "aBcDe";
		String str2 = "AbCdE";

		// 大文字小文字問わず等しいか判定.
		boolean b = str1.equalsIgnoreCase(str2);

		// 出力.
		System.out.println(b);

	}

}
