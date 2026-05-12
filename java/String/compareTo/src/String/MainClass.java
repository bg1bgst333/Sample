// メインクラス
public class MainClass{

	// Javaのエントリポイント
	public static void main(String[] arg){ // mainメソッドの定義

		// 2つの文字列を定義.
		String str1 = "ABC";
		String str2 = "BCD";

		// 2つの文字列を比較し, ASCIIコードにおける差を比較する.
		int result = str1.compareTo(str2);

		// 出力.
		System.out.println(result);

	}

}
