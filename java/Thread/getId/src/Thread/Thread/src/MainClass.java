// メインクラス
public class MainClass{	// MainClassの定義

	// Javaのエントリポイント
	public static void main(String[] args){	// mainメソッドの定義

		// CustomThread前.
		System.out.println("CustomThread before.");	// "CustomThread before."と出力.

		// CustomThread生成.
		CustomThread ct = new CustomThread();	// CustomThreadオブジェクトctを生成.

		// スレッドID取得.
		System.out.println("[1]:ct.getId() = " + ct.getId());	// ct.getIdでスレッドID取得.

		// 開始.
		ct.start();	// ct.startで開始.

		// スレッドID取得.
		System.out.println("[2]:ct.getId() = " + ct.getId());	// ct.getIdでスレッドID取得.

		// CustomThread後.
		System.out.println("CustomThread after.");	// "CustomThread after."と出力.

	}

}