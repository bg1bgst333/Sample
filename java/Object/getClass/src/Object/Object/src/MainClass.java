// メインクラス
public class MainClass{	// MainClassの定義

	// Javaのエントリポイント
	public static void main(String[] args){

		// Object.getClassでClassオブジェクトを取得.
		String str = "ABC";	// Stringオブジェクトstrを"ABC"で初期化.
		Class strClass = str.getClass();	// str.getClassでstrClassを取得.
		System.out.println(strClass.toString());	// strClass.toString()で出力.

		// ジェネリクス版.
		Class<?> strClass2 = str.getClass();	// strClass2を取得.(Class<String>でそのまま受け取れないのでClass<?>にした.)
		System.out.println(strClass2.toString());	// strClass2.toString()で出力.

	}

}