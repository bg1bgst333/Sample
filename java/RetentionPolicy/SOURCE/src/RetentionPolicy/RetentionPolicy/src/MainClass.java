// クラスのインポート
import java.lang.annotation.Annotation;
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
			// アノテーションの取得.
			Annotation[] annotations = method1.getDeclaredAnnotations();	// アノテーションを取得.
			System.out.println("annotations[0] = " + annotations[0]);	// annotations[0]を出力.
		} catch (Exception ex) {	// 例外をcatch.
			System.out.println(ex);	// exを出力.
		}

	}

}