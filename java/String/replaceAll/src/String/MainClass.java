// メインクラス
public class MainClass{

	// Javaのエントリポイント
	public static void main(String[] arg){ // mainメソッドの定義

		// 文字列str1の定義.
		String str1 = "ABC.ABC:ABC!ABC";

		// 正規表現にマッチする部分の置換.
		String str2 = str1.replaceAll("B\\w+", "XY"); // Bから始まり, その後に英数字が1文字以上続く.

		// 出力.
		System.out.println(str2);

	}

}
