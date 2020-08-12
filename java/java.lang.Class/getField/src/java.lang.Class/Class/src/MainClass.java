// クラスのインポート
import com.bgstation0.java.sample.CustomClass;	// CustomClassのインポート.

// メインクラス
public class MainClass{	// MainClassの定義

	// Javaのエントリポイント
	public static void main(String[] args){

		// tryで囲む.
		try {
			// CustomClassのval1を取得.
			System.out.println(CustomClass.class.getField("val1").toString());	// CustomClass.class.getFieldで"val1"の情報を取得し出力.
		} catch (Exception ex) {	// 例外をcatch.
			System.out.println(ex);	// exを出力.
		}

	}

}