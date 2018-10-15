// メインクラス
public class MainClass{	// MainClassの定義

	// Javaのエントリポイント
	public static void main(String[] args){	// mainメソッドの定義

		// DerivedClassオブジェクトを作成し, BaseClassオブジェクトに格納.
		BaseClass b = new DerivedClass();	// DerivedClassオブジェクトをBaseClassのbに格納.
		b.print();	// b.printで表示.

	}

}