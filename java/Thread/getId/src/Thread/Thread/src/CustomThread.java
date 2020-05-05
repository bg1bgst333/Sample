// カスタムスレッド
public class CustomThread extends Thread{

	// 処理
	public void run(){

		// tryで囲む.
		try {

			// スレッドID取得.
			System.out.println("[3]:getId() = " + getId());	// getIdでスレッドID取得.

			// 休止前.
			System.out.println("Thread.sleep before");

			// 休止中.
			Thread.sleep(3000);

			// 休止後.
			System.out.println("Thread.sleep after");

		} catch (InterruptedException e) {
			// TODO 自動生成された catch ブロック
			e.printStackTrace();
		}

	}

}