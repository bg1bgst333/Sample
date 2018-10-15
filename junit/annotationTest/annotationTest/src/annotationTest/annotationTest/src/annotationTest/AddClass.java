// annotationTestパッケージ.
package annotationTest;	// annotationTestパッケージとしておく.

// 加算クラス
public class AddClass {	// AddClassの定義.

	// 加算add.
	public int add(int a, int b){

		// aとbを足した結果を返す.
		return a + b;	// a + bの結果を返す.
		//return a - b;	// a - bの結果を返す.(これにしたらテストは失敗する.)

	}

}