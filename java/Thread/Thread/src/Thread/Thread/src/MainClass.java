// メインクラス
public class MainClass{	// MainClassの定義

	// Javaのエントリポイント
	public static void main(String[] args){	// mainメソッドの定義

		// CustomThread前.
		System.out.println("CustomThread before.");	// "CustomThread before."と出力.

		// CustomThread開始.
		CustomThread ct = new CustomThread();	// CustomThreadオブジェクトctを生成.
		ct.start();	// ct.startで開始.

		// CustomThread後.
		System.out.println("CustomThread after.");	// "CustomThread after."と出力.

	}

}