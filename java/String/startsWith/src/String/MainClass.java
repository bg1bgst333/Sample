// メインクラス
public class MainClass{

	// Javaのエントリポイント
	public static void main(String[] arg){ // mainメソッドの定義

		// 文字列strの定義.
		String str = "ABXYZCDE";

		// 指定の文字列で始まるか判定.
		boolean b = str.startsWith("ABXY");

		// 出力.
		System.out.println(b);

	}

}
