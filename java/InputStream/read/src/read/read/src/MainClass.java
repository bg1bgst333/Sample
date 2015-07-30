// パッケージ・クラスのインポート
import java.io.FileInputStream;	// FileInputStreamクラス(java.ioパッケージ)
import java.io.IOException;		// IOExceptionクラス(java.ioパッケージ)
import java.io.InputStream;		// InputStreamクラス(java.ioパッケージ)

// メインクラス
class MainClass {	// MainClassクラスの定義

	// Javaのエントリポイント
	public static void main(String[] args) {	// mainメソッドの定義

		// 変数の初期化
		InputStream in = null;		// InputStream型変数inをnullに初期化.
		byte buf[] = new byte[100];	// バッファ用byte型配列buf(長さ128)を生成.
		int len;					// 読み込んだ長さlen.

		// test.txtを開く.
		try {	// tryブロック
			in = new FileInputStream("test.txt");	// InputStream変数inに"test.txt"を開くFileInputStreamのインスタンスを入れる.
			// readで読み込む.
			len = in.read(buf);	// readで読み込んだバイトデータをbufに格納し, 戻り値の長さはlenに格納.
			for (int i = 0; i < len; i++){	// for文でbufの各要素を全部出力.
				System.out.print((char)buf[i]);	// bufの各要素をcharにキャストして出力.(今回は1バイト文字のみのファイルなので大丈夫.)
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