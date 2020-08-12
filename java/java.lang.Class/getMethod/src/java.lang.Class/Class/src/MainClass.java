// クラスのインポート
import com.bgstation0.java.sample.CustomClass;	// CustomClassのインポート.

// メインクラス
public class MainClass{	// MainClassの定義

	// Javaのエントリポイント
	public static void main(String[] args){

		// tryで囲む.
		try {
			// CustomClassのmethod1を取得.
			System.out.println(CustomClass.class.getMethod("method1", null).toString());	// CustomClass.class.getMethodで"method1"の情報を取得し出力.
		} catch (Exception ex) {	// 例外をcatch.
			System.out.println(ex);	// exを出力.
		}

	}

}