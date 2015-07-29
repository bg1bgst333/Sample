// パッケージ・クラスのインポート
import java.io.FileInputStream;	// FileInputStreamクラス(java.ioパッケージ)
import java.io.IOException;		// IOExceptionクラス(java.ioパッケージ)
import java.io.InputStream;		// InputStreamクラス(java.ioパッケージ)

// メインクラス
class MainClass {	// MainClassクラスの定義

	// Javaのエントリポイント
	public static void main(String[] args) {	// mainメソッドの定義

		// 変数の初期化
		InputStream in = null;	// InputStream型変数inをnullに初期化.
		int c = 0;	// readしたバイト値cを0に初期化.

		// test.txtを開く.
		try {	// tryブロック
			in = new FileInputStream("test.txt");	// InputStream変数inに"test.txt"を開くFileInputStreamのインスタンスを入れる.
			// readで読み込む.
			while ((c = in.read()) != -1){	// readで読み込んだ値
				System.out.println("c = " + c);	// cの値を出力.
			}
			in.close();	// close()で閉じる.
		}
		catch (IOException e) {	// IOExceptionをキャッチしないといけない.
			// 例外処理
			System.out.println("e.toString() = " + e.toString());	// e.toString()の内容を出力.
			System.exit(-1);	// exit(-1)で終了.
			try {	// tryブロック
				in.close();	// close()で閉じる.
			}
			catch (IOException e1) {	// IOExceptionをキャッチしないといけない.
				System.out.println("e1.toString() = " + e1.toString());	// e1.toString()の内容を出力.
				System.exit(-1);	// exit(-1)で終了.
			}
		}

	}

}