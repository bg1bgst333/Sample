// パッケージ・クラスのインポート
import java.io.FileOutputStream;	// FileOutputStreamクラス(java.ioパッケージ)
import java.io.IOException;			// IOExceptionクラス(java.ioパッケージ)
import java.io.OutputStream;		// OutputStreamクラス(java.ioパッケージ)

// メインクラス
class MainClass {	// MainClassクラスの定義

	// Javaのエントリポイント
	public static void main(String[] args) {	// mainメソッドの定義

		// 変数の初期化
		OutputStream out = null;	// OutputStream型変数outをnullに初期化.
		byte[] buf = new byte[5];	// 書き込むバイト配列buf.(長さ5)

		// bufにバイト値をセット.
		buf[0] = 0x41;	// 'A'
		buf[1] = 0x42;	// 'B'
		buf[2] = 0x43;	// 'C'
		buf[3] = 0x44;	// 'D'
		buf[4] = 0x45;	// 'E'

		// test.txtにbufの一部を書き込む.
		try {	// tryブロック
			out = new FileOutputStream("test.txt");	// OutputStream変数outにFileOutputStreamインスタンスを入れる.
			out.write(buf, 1, 3);	// write(byte[] b, int off, int len)でbufの1文字目から3文字分を書き込む.
			out.close();	// close()で閉じる.
		}
		catch (IOException e) {	// IOExceptionの時.
			// 例外処理
			System.out.println("e.toString() = " + e.toString());	// e.toString()の内容を出力.
			try {	// tryブロック
				out.close();	// close()で閉じる.
			}
			catch (IOException e1) {	// IOExceptionをキャッチしないといけない.
				System.out.println("e1.toString() = " + e1.toString());	// e1.toString()の内容を出力.
				System.exit(-1);	// exit(-1)で終了.
			}
			System.exit(-1);	// exit(-1)で終了.
		}

	}

}