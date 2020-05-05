// メインクラス
public class MainClass{	// MainClassの定義

	// Javaのエントリポイント
	public static void main(String[] args){	// mainメソッドの定義

		// CustomThread前.
		System.out.println("CustomThread before.");	// "CustomThread before."と出力.

		// カレントスレッドID取得.
		System.out.println("[1]:Thread.currentThread.getId() = " + Thread.currentThread().getId());	// Thread.currentThread().getId()で取得.

		// CustomThread生成.
		CustomThread ct = new CustomThread();	// CustomThreadオブジェクトctを生成.

		// カレントスレッドID取得.
		System.out.println("[2]:Thread.currentThread.getId() = " + Thread.currentThread().getId());	// Thread.currentThread().getId()で取得.

		// 開始.
		ct.start();	// ct.startで開始.

		// カレントスレッドID取得.
		System.out.println("[3]:Thread.currentThread.getId() = " + Thread.currentThread().getId());	// Thread.currentThread().getId()で取得.

		// CustomThread後.
		System.out.println("CustomThread after.");	// "CustomThread after."と出力.

	}

}