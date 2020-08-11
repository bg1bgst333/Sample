// メインクラス
public class MainClass{	// MainClassの定義

	// Javaのエントリポイント
	public static void main(String[] args){

		// Integerの値を持つオブジェクトの生成.
		CustomClass<Integer> intClass = new CustomClass<Integer>();	// CustomClass<Integer>オブジェクトintClassの生成.

		// 値の設定.
		intClass.setVal(123);	// intClass.setValで123をセット.

		// 値の取得と出力.
		System.out.println("intClass.getVal() = " + intClass.getVal());	// intClassのgetValで取得した値を出力.

		// Stringの値を持つオブジェクトの生成.
		CustomClass<String> strClass = new CustomClass<String>();	// CustomClass<String>オブジェクトstrClassの生成.

		// 値の設定.
		strClass.setVal("ABC");	// strClass.setValで123をセット.

		// 値の取得と出力.
		System.out.println("strClass.getVal() = " + strClass.getVal());	// strClassのgetValで取得した値を出力.

	}

}