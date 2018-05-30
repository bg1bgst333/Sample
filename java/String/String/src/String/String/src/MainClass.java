// メインクラス
public class MainClass{	// MainClassの定義

	// Javaのエントリポイント
	public static void main(String[] args){	// mainメソッドの定義

		// Stringオブジェクトの宣言と初期化.
		//String str1;	// Stringオブジェクトstr1の宣言.(これだと初期化も代入もないのでコンパイル前にエラーにされる.)
		String str1 = null;	// Stringオブジェクトstr1の初期化でnullをセット.
		String str2 = "DEF";	// Stringオブジェクトstr2の初期化.
		String str3 = new String("GHI");	// Stringオブジェクトstr3の初期化生成.

		// Stringオブジェクトの参照と出力.
		try{	// tryで囲む.
			System.out.println(str1);	// str1の出力.
			System.out.println(str2);	// str2の出力.
			System.out.println(str3);	// str3の出力.
		}
		catch (Exception ex){
			System.out.println(ex.toString());	// 例外の出力.
		}

		// 文字列の代入と連結.
		str1 = "ABC";	// str1に"ABC"を代入.
		str2 = "XYZ";	// str2に"XYZ"を代入.
		str3 = str1 + str2;	// str3にstr1とstr2を連結したものを代入.
		str3 = str3 + "HOGE";	// str3に"HOGE"を連結.

		// Stringオブジェクトの参照と出力.
		try{	// tryで囲む.
			System.out.println(str1);	// str1の出力.
			System.out.println(str2);	// str2の出力.
			System.out.println(str3);	// str3の出力.
		}
		catch (Exception ex){
			System.out.println(ex.toString());	// 例外の出力.
		}

	}

}