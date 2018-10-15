// annotationTestパッケージ.
package annotationTest;	// annotationTestパッケージとしておく.

// メインクラス
public class MainClass{	// MainClassの定義

	// Javaのエントリポイント
	public static void main(String[] args){	// mainメソッドの定義

		// AddClassオブジェクトを生成し, addObjに格納.
		AddClass addObj = new AddClass();	// addObjを生成.
		int result = addObj.add(10, 20);	// addObj.addで10と20を足す.
		System.out.println("result = " + result);	// resultを表示.

	}

}