import java.util.Date;

// メインクラス
public class MainClass{	// MainClassの定義

	// Javaのエントリポイント
	public static void main(String[] args){	// mainメソッドの定義

		// Dateクラスで現在時刻を取得して出力.
		Date date = new Date();	// Dateオブジェクトdateを生成.(この時, dateに現在時刻がセットされている.)
		System.out.println(date);	// dateを出力.(System.out.printlnが文字列として出力するようになっている.)

	}

}