// パッケージ・クラスのインポート
import java.io.FileWriter;	// FileWriterクラス(java.ioパッケージ)
import java.io.IOException;	// IOExceptionクラス(java.ioパッケージ)
import java.io.Writer;		// Writerクラス(java.ioパッケージ)

//メインクラス
class MainClass {	// MainClassクラスの定義

	// Javaのエントリポイント
	public static void main(String[] args) {	// mainメソッドの定義
		
		// 変数の初期化
		Writer writer = null;	// Writer型変数writerをnullに初期化.
		
		// test.txtに文字列を書き込む.
		try{	// tryブロック
			writer = new FileWriter("test.txt");	// Writer型変数writerに"test.txt"を開くFileWriterのインスタンスを入れる.
			writer.write("ABCDE");	// writer.writeで文字列"ABCDE"を書き込む.
			writer.close();	// closeで閉じる.
		}
		catch (IOException e) {	// IOExceptionをキャッチしないといけない.
			// 例外処理
			System.out.println("e.toString() = " + e.toString());	// e.toString()の内容を出力.
			try {	// tryブロック
				writer.close();	// closeで閉じる.
			}
			catch (IOException e1) {	// IOExceptionをキャッチしないといけない.
				System.out.println("e1.toString() = " + e1.toString());	// e1.toString()の内容を出力.
				System.exit(-1);	// exit(-1)で終了.
			}
			System.exit(-1);	// exit(-1)で終了.
		}
		
	}
	
}