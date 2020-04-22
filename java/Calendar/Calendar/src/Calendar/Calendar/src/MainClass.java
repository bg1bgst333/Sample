import java.util.Calendar;

// メインクラス
public class MainClass{	// MainClassの定義

	// Javaのエントリポイント
	public static void main(String[] args){	// mainメソッドの定義

		// Calendarオブジェクトの取得.
		Calendar calendar = Calendar.getInstance();	// Calendar.getInstanceでオブジェクトインスタンス取得.
		int m = calendar.get(Calendar.MONTH) + 1;	// 月を取得.(0から始まるので1足す.)
		int d = calendar.get(Calendar.DATE);	// 日を取得.
		System.out.println(m + "/" + d);	// mとdで日付を出力.

	}

}