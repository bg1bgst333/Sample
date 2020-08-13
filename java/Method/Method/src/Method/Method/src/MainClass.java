// クラスのインポート
import java.lang.reflect.Method;

import com.bgstation0.java.sample.CustomClass;	// CustomClassのインポート.

// メインクラス
public class MainClass{	// MainClassの定義

	// Javaのエントリポイント
	public static void main(String[] args){

		// tryで囲む.
		try {
			// CustomClassのmethod1を取得し, Methodオブジェクトmethod1に格納.
			Method method1 = CustomClass.class.getMethod("method1", null);	// CustomClass.class.getMethodでmethod1を取得.
			// 引数の数を取得.
			System.out.println("method1.getParameterCount() = " + method1.getParameterCount());	// method1.getParameterCountで引数の数を出力.
		} catch (Exception ex) {	// 例外をcatch.
			System.out.println(ex);	// exを出力.
		}

	}

}