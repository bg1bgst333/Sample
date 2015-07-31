// パッケージ・クラスのインポート
import java.io.File;	// Fileクラス(java.ioパッケージ)
import java.io.FileReader;	// FileReaderクラス(java.ioパッケージ)
import java.io.IOException;		// IOExceptionクラス(java.ioパッケージ)

//メインクラス
class MainClass {	// MainClassクラスの定義

	// Javaのエントリポイント
	public static void main(String[] args) {	// mainメソッドの定義

		// 変数の宣言
		char[] buf = new char[128];	// 文字列バッファbuf
		FileReader reader = null;	// ファイルリーダーreader

		// ファイルの存在確認
		File file = new File("test.txt");	// "test.txt"を示すFileオブジェクトfileを作成.
		if (!file.exists()){	// 存在しないなら.
			System.out.println("test.txt is not exist!");	// "test.txt is not exist!"と出力.
			System.exit(-1);	// exit(-1)で終了.
		}

		// テキストファイルの読み込み
		try{	// tryブロック
			reader = new FileReader(file);	// コンストラクタにfileを渡して, FileReaderオブジェクト生成.
			reader.read(buf);	// reader.readで読み込んだ文字列をbufに格納.
			System.out.print(buf);	// bufの内容を出力.
			reader.close();	// 閉じる.
		}
		catch (IOException e) {	// IOExceptionをキャッチしないといけない.
			// 例外処理
			System.out.println("e.toString() = " + e.toString());	// e.toString()の内容を出力.
			System.exit(-1);	// exit(-1)で終了.
			try {	// tryブロック
				reader.close();	// close()で閉じる.
			}
			catch (IOException e1) {	// IOExceptionをキャッチしないといけない.
				System.out.println("e1.toString() = " + e1.toString());	// e1.toString()の内容を出力.
				System.exit(-1);	// exit(-1)で終了.
			}
		}

	}

}