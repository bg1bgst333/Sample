//メインクラス
class MainClass {	// MainClassクラスの定義

	// Javaのエントリポイント
	public static void main(String[] args) {	// mainメソッドの定義

		// StringオブジェクトをObjectオブジェクトにキャスト.
		String str = "ABC";	// strを"ABC"で初期化.
		Object obj = str;	// strをObjectオブジェクトobjに格納.
		
		// オブジェクトの中身を出力.
		System.out.println("str = " + str);	// strを出力.
		System.out.println("obj = " + obj);	// objを出力.
		
		// 独自のオブジェクトCustomObjectをObjectオブジェクトにキャスト.
		CustomObject custom = new CustomObject();	// customを生成.
		Object obj2 = custom;	// customをObjectオブジェクトobj2に格納.
		
		// オブジェクトのtoStringを出力.
		System.out.println("custom.toString() = " + custom.toString());	// custom.toString()を出力.
		System.out.println("obj2.toString() = " + obj2.toString());	// obj2.toString()を出力.
		
	}
	
}