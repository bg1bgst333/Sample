// カスタムスレッド
public class CustomThread extends Thread{

	// 処理
	public void run(){

		// tryで囲む.
		try {

			// 休止前.
			System.out.println("Thread.sleep before");

			// カレントスレッドID取得.
			System.out.println("[4]:Thread.currentThread.getId() = " + Thread.currentThread().getId());	// Thread.currentThread().getId()で取得.

			// 休止中.
			Thread.sleep(3000);

			// カレントスレッドID取得.
			System.out.println("[5]:Thread.currentThread.getId() = " + Thread.currentThread().getId());	// Thread.currentThread().getId()で取得.

			// 休止後.
			System.out.println("Thread.sleep after");

		} catch (InterruptedException e) {
			// TODO 自動生成された catch ブロック
			e.printStackTrace();
		}

	}

}