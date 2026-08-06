// メインクラス
public class MainClass{

	// Javaのエントリポイント
	public static void main(String[] arg){ // mainメソッドの定義

		// 文字列strの定義.
		String str = "ABCDE";

		// 1文字目から3文字目までを抽出.
		String substr = str.substring(1, 4); // 抽出するのはendIndex - 1までなので注意!

		// 出力.
		System.out.println(substr);

	}

}
