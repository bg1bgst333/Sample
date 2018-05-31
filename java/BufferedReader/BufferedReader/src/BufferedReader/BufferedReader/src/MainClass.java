import java.io.BufferedReader;
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
		BufferedReader br = null;	// BufferedReader型brをnullに初期化.
		String strLine = null;	// String型strLineをnullに初期化.

		// test.txtを開く.
		try {	// tryブロック
			fin = new FileInputStream("test.txt");	// FileInputStreamで"test.txt"を開く.
			insr = new InputStreamReader(fin, "Shift_JIS");	// InputStreamReaderでfinをShift_JISからUnicodeに変換.
			br = new BufferedReader(insr);	// BufferedReaderにinsrを渡してbrを取得.
			while ((strLine = br.readLine()) != null){	// strLineがnullでない時.
				System.out.println("strLine = " + strLine);	// strLineを出力.
			}
			br.close();	// brを閉じる.
			fin.close();	// finを閉じる.
		}
		catch (IOException e) {	// IOExceptionをキャッチしないといけない.
			// 例外処理
			System.out.println("e.toString() = " + e.toString());	// e.toString()の内容を出力.
			System.exit(-1);	// exit(-1)で終了.
			try {	// tryブロック
				br.close();	// brを閉じる.
				fin.close();	// close()で閉じる.
			}
			catch (IOException e1) {	// IOExceptionをキャッチしないといけない.
				System.out.println("e1.toString() = " + e1.toString());	// e1.toString()の内容を出力.
				System.exit(-1);	// exit(-1)で終了.
			}
		}

	}

}