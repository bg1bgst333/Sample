// メインクラス
public class MainClass{

	// Javaのエントリポイント
	public static void main(String[] arg){ // mainメソッドの定義

		// 文字列str1の定義.
		String str1 = "ABCXYZABCXYZ";

		// 文字列の置換.
		String str2 = str1.replace("CX", "PQ");

		// 出力.
		System.out.println(str2);

	}

}
