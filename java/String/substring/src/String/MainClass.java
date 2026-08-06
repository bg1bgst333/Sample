// メインクラス
public class MainClass{

	// Javaのエントリポイント
	public static void main(String[] arg){ // mainメソッドの定義

		// 文字列strの定義.
		String str = "ABCDE";

		// 2文字目以降を抽出.
		String substr = str.substring(2);

		// 出力.
		System.out.println(substr);

	}

}
