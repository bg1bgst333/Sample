import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;

// メインクラス
public class MainClass {	// MainClassの定義

	// Javaのエントリポイント
	public static void main(String[] args){	// mainメソッドの定義

		// 変数の初期化
		FileInputStream fin = null;	// FileInputStream型変数finをnullに初期化.
		InputStreamReader insr = null;	// InputStreamReader型insrをnullに初期化.
		int c = 0;	// readしたバイト値cを0に初期化.

		// test.txtを開く.
		try {	// tryブロック
			fin = new FileInputStream("test.txt");	// FileInputStreamで"test.txt"を開く.
			insr = new InputStreamReader(fin, "Shift_JIS");	// InputStreamReaderでfinをShift_JISからUnicodeに変換.
			while ((c = insr.read()) != -1){	// 読み込んだ文字cが-1でない時.
				System.out.println("c = " + c);	// cの値を出力.
			}
		}
		catch (IOException e) {	// IOExceptionをキャッチしないといけない.
			// 例外処理
			System.out.println("e.toString() = " + e.toString());	// e.toString()の内容を出力.
			System.exit(-1);	// exit(-1)で終了.
			try {	// tryブロック
				fin.close();	// close()で閉じる.
			}
			catch (IOException e1) {	// IOExceptionをキャッチしないといけない.
				System.out.println("e1.toString() = " + e1.toString());	// e1.toString()の内容を出力.
				System.exit(-1);	// exit(-1)で終了.
			}
		}

	}

}