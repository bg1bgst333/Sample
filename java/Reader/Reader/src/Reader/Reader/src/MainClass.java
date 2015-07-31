// パッケージ・クラスのインポート
import java.io.FileReader;	// FileReaderクラス(java.ioパッケージ)
import java.io.IOException;	// IOExceptionクラス(java.io.パッケージ)
import java.io.Reader;		// Readerクラス(java.ioパッケージ)

//メインクラス
class MainClass {	// MainClassクラスの定義

	// Javaのエントリポイント
	public static void main(String[] args) {	// mainメソッドの定義

		// 変数の初期化
		Reader reader = null;		// Reader型変数readerをnullに初期化.
		char[] buf = new char[128];	// char型配列buf(長さ128)を生成.

		// test.txtを読み込む.
		try {	// tryブロック
			reader = new FileReader("test.txt");	// Reader型変数readerに"test.txt"を開くFileReaderのインスタンスを入れる.
			reader.read(buf);	// reader.readで読み込んだ文字列をbufに格納.
			System.out.print(buf);	// bufの内容をSystem.out.printで出力.
			reader.close();	// closeで閉じる.
		}
		catch (IOException e) {	// IOExceptionをキャッチしないといけない.
			// 例外処理
			System.out.println("e.toString() = " + e.toString());	// e.toString()の内容を出力.
			try {	// tryブロック
				reader.close();	// closeで閉じる.
			}
			catch (IOException e1) {	// IOExceptionをキャッチしないといけない.
				System.out.println("e1.toString() = " + e1.toString());	// e1.toString()の内容を出力.
				System.exit(-1);	// exit(-1)で終了.
			}
			System.exit(-1);	// exit(-1)で終了.
		}

	}

}