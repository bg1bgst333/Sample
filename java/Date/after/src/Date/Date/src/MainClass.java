import java.util.Date;

// メインクラス
public class MainClass{	// MainClassの定義

	// Javaのエントリポイント
	public static void main(String[] args){	// mainメソッドの定義

		// tryで囲む.
		try {

			// この時点での時刻を取得.
			Date date1 = new Date();	// date1を取得.
			System.out.println(date1);	// date1を出力.

			// 5秒休止.
			Thread.sleep(5000);	// Thread.sleepで5000ミリ秒休止.

			// この時点での時刻を取得.
			Date date2 = new Date();	// date2を取得.
			System.out.println(date2);	// date2を出力.

			// 指定の日付より後か判定.
			if (date2.after(date1)){	// date2がdate1より後なら.
				System.out.println("date2 > date1");	// "date2 > date1"と出力.
			}

		} catch (InterruptedException e) {
			// TODO 自動生成された catch ブロック
			e.printStackTrace();
		}

	}

}