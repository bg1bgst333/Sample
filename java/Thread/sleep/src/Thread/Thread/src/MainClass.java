// メインクラス
public class MainClass{	// MainClassの定義

	// Javaのエントリポイント
	public static void main(String[] args){	// mainメソッドの定義

		// 休止前.
		System.out.println("Thread.sleep before");	// "Thread.sleep before"と出力.

		// 休止中
		// tryで囲む..
		try {
			Thread.sleep(3000);	// 3秒(3000ミリ秒)休止.
		} catch (InterruptedException e) {
			// TODO 自動生成された catch ブロック
			e.printStackTrace();
		}

		// 休止後.
		System.out.println("Thread.sleep after");	// "Thread.sleep after"と出力.

	}

}