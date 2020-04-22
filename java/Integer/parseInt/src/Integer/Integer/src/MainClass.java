// メインクラス
public class MainClass{	// MainClassの定義

	// Javaのエントリポイント
	public static void main(String[] args){	// mainメソッドの定義

		// 文字列を整数に変換する.
		String str = "20";	// strを"20"で初期化.
		int a = 10;	// aを10で初期化する.
		int x = Integer.parseInt(str);	// Integer.parseIntでstrをint型のxに変換.
		int ret = a + x;	// aとxを足した結果をretに格納.
		System.out.println("ret = " + ret);	// retを出力.

	}

}