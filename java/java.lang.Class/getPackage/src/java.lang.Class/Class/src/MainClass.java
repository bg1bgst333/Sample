// クラスのインポート
import com.bgstation0.java.sample.CustomClass;	// CustomClassのインポート.

// メインクラス
public class MainClass{	// MainClassの定義

	// Javaのエントリポイント
	public static void main(String[] args){

		// Stringのパッケージを取得し出力.
		System.out.println(String.class.getPackage());	// String.class.getPackageでパッケージ文字列を取得し出力.

		// CustomClassのパッケージを取得し出力.
		System.out.println(CustomClass.class.getPackage());	// CustomClass.class.getPackageでパッケージ文字列を取得し出力.

	}

}