// メインクラス
public class MainClass{

	// Javaのエントリポイント
	public static void main(String[] arg){ // mainメソッドの定義

		// 文字列str1の定義.
		String str1 = "  \t ABC  \n  ";

		// 前後の空白類を除去.
		String str2 = str1.trim();

		// 出力.
		System.out.println("[" + str2 + "]");

	}

}
