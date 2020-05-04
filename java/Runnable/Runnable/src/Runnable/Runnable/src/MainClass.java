// メインクラス
public class MainClass{	// MainClassの定義

	// Javaのエントリポイント
	public static void main(String[] args){	// mainメソッドの定義

		// 匿名クラスでRunnableを実装したThreadを生成して開始.
		System.out.println("CustomThread before.");	// "CustomThread before."と出力.
		new Thread(new Runnable(){
			public void run(){
				System.out.println("Thread.sleep before.");	// "Thread.sleep before."と出力.
				try {
					Thread.sleep(3000);
				} catch (InterruptedException e) {
					// TODO 自動生成された catch ブロック
					e.printStackTrace();
				}	// 3秒休止.
				System.out.println("Thread.sleep after.");	// "Thread.sleep after."と出力.
			}
		}).start();	// 開始.
		System.out.println("CustomThread after.");	// "CustomThread after."と出力.

	}

}