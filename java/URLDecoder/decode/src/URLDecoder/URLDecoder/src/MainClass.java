import java.net.URLDecoder;

// メインクラス
public class MainClass {	// MainClassの定義

	// Javaのエントリポイント
	public static void main(String[] args){	// mainメソッドの定義

		// 変数の初期化.
		String strText = "%E3%81%82%E3%81%84%E3%81%86%E3%81%88%E3%81%8A";	// strTextを"%E3%81%82%E3%81%84%E3%81%86%E3%81%88%E3%81%8A"で初期化.

		// URLデコード.
		try{	// tryで囲む.
			String strDecoded = URLDecoder.decode(strText, "UTF-8");	// URLDecoder.decodeでUTF-8でstrTextをURLデコード.
			System.out.println(strDecoded);	// strDecodedを出力.
		}
		catch (Exception ex){
			System.out.println(ex.toString());	// ex.toString()を出力.
		}

	}

}