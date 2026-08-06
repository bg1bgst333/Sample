// メインクラス
public class MainClass{

	// Javaのエントリポイント
	public static void main(String[] arg){ // mainメソッドの定義

		// 文字列strの定義.
		String str = "ABCDEABCDEABCDE";

		// 後方から探索して, 最初に見つかった指定文字列の位置.
		int index = str.lastIndexOf("ABC");

		// 出力.
		System.out.println(index);

	}

}
