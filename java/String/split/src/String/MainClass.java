// メインクラス
public class MainClass{

	// Javaのエントリポイント
	public static void main(String[] arg){ // mainメソッドの定義

		// 文字列strの定義.
		String str = "ABC, DEF, GHI, JKL";

		// 正規表現にマッチした文字列で分解.
		String[] strs = str.split(", ");

		// 出力.
		for (String s : strs){
			System.out.println(s);
		}

	}

}
