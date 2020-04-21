// メインクラス
public class MainClass{	// MainClassの定義

	// Javaのエントリポイント
	public static void main(String[] args){	// mainメソッドの定義

		// 文字列の長さを取得.
		String str = "ABCDE";	// strを"ABCDE"で初期化.
		int len = str.length();	// str.lengthで長さを取得し, lenに格納.
		System.out.println("len = " + len);	// lenを出力.

		// 日本語の場合..
		String str2 = "あいうえお";	// str2を"あいうえお"で初期化.
		int len2 = str2.length();	// str2.lengthで長さを取得し, len2に格納.
		System.out.println("len2 = " + len2);	// len2を出力.

	}

}