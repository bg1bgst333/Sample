// パッケージ・クラスのインポート
import java.io.PrintWriter;

// メインクラス
public class MainClass{
	// Javaのエントリポイント
	public static void main(String[] arg){ // mainメソッドの定義

		// PrintWritrの出力.
		try (PrintWriter pw = new PrintWriter("test.txt")){
			pw.append("[ABC, ").append("DEF]\n");
		}
		catch (Exception e){
			e.printStackTrace();
		}

	}

}
