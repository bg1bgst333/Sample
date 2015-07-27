// パッケージ・クラスのインポート
import java.io.FileNotFoundException;	// FileNotFoundExceptionクラス(java.ioパッケージ)
import java.io.FileOutputStream;	// FileOutputStreamクラス(java.ioパッケージ)
import java.io.PrintStream;	// PrintStreamクラス(java.ioパッケージ)

// メインクラス
class MainClass {	// MainClassクラスの定義

	// Javaのエントリポイント
	public static void main(String[] args) {	// mainメソッドの定義

		// オブジェクトの宣言
		PrintStream out = null;	// PrintStreamオブジェクトoutをnullに初期化.

		// PrintStreamオブジェクトの作成.
		try {	// tryブロックで囲む.
			out = new PrintStream(new FileOutputStream("test.txt"));	// "test.txt"に出力するPrintStreamオブジェクトoutを作成.
			out.println(123);	// printlnで123を出力.
			out.println("ABC");	// printlnで"ABC"を出力.
		}
		catch (FileNotFoundException e) {	// FileNotFoundExceptionの時.
			System.out.println("e.toString()" + e.toString());	// printlnでe.toStringの内容を出力.
		}
		finally {	// finallyなので, 必ずここを処理.
			if (out != null){	// outがnullでない時.
				out.close();	// outを閉じる.
			}
		}

	}

}