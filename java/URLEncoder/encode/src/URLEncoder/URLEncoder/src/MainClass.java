import java.net.URLEncoder;

// メインクラス
public class MainClass {	// MainClassの定義

	// Javaのエントリポイント
	public static void main(String[] args){	// mainメソッドの定義

		// 変数の初期化.
		String strText = "あいうえお";	// strTextを"あいうえお"で初期化.

		// URLエンコード.
		try{	// tryで囲む.
			String strEncoded = URLEncoder.encode(strText, "UTF-8");	// URLEncoder.encodeでUTF-8でstrTextをURLエンコード.
			System.out.println(strEncoded);	// strEncodedを出力.
		}
		catch (Exception ex){
			System.out.println(ex.toString());	// ex.toString()を出力.
		}

	}

}