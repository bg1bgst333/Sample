// クラスのインポート
import com.bgstation0.java.sample.CustomClass;	// CustomClassのインポート.

// メインクラス
public class MainClass{	// MainClassの定義

	// Javaのエントリポイント
	public static void main(String[] args){

		// Stringのクラス名を取得し出力.
		System.out.println(String.class.getName());	// String.class.getNameでクラス名を取得し出力.

		// CustomClassのクラス名を取得し出力.
		System.out.println(CustomClass.class.getName());	// CustomClass.class.getNameでクラス名を取得し出力.

	}

}