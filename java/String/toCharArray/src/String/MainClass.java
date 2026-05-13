// メインクラス
public class MainClass{

	// Javaのエントリポイント
	public static void main(String[] arg){ // mainメソッドの定義

		// 文字列を定義.
		String str = "ABCDE";

		// Stringをchar配列に変換.
		char[] chars = str.toCharArray();

		// 1文字ずつ出力.
		for (char c : chars){
			System.out.println(c);
		}

	}

}
