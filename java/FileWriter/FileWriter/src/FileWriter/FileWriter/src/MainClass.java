// パッケージ・クラスのインポート
import java.io.File;	// Fileクラス(java.ioパッケージ)
import java.io.FileWriter;	// FileWriterクラス(java.ioパッケージ)
import java.io.IOException;		// IOExceptionクラス(java.ioパッケージ)

//メインクラス
class MainClass {	// MainClassクラスの定義

	// Javaのエントリポイント
	public static void main(String[] args) {	// mainメソッドの定義

		// 変数の宣言
		FileWriter writer = null;	// ファイルライターwriter

		// ファイルの存在確認
		File file = new File("test.txt");	// "test.txt"を示すFileオブジェクトfileを作成.
		if (!file.exists()){	// 存在しないなら.
			System.out.println("test.txt is not exist!");	// "test.txt is not exist!"と出力.(強制終了はしない.)
		}

		// test.txtに書き込む.
		try{	// tryブロック
			writer = new FileWriter(file);	// コンストラクタにfileを渡して, FileWriterオブジェクト生成.
			writer.write("ABCDE");	// writer.writeで"ABCDE"を書き込む.
			writer.close();	// close()で閉じる.
		}
		catch (IOException e) {	// IOExceptionの時.
			// 例外処理
			System.out.println("e.toString() = " + e.toString());	// e.toString()の内容を出力.
			try {	// tryブロック
				writer.close();	// writer.close()で閉じる.
			}
			catch (IOException e1) {	// IOExceptionをキャッチしないといけない.
				System.out.println("e1.toString() = " + e1.toString());	// e1.toString()の内容を出力.
				System.exit(-1);	// exit(-1)で終了.
			}
			System.exit(-1);	// exit(-1)で終了.
		}

	}

}