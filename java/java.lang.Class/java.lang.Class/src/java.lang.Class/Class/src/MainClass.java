// メインクラス
public class MainClass{	// MainClassの定義

	// Javaのエントリポイント
	public static void main(String[] args){

		// .classキーワードでClassオブジェクトを取得.
		Class intClass = Integer.class;	// Integer.classでintClassを取得.
		System.out.println(intClass.toString());	// intClass.toString()を出力.

		// ジェネリクス版.
		Class<String> strClass = String.class;	// String.classでstrClassを取得.
		System.out.println(strClass.toString());	// strClass.toString()で出力.

	}

}