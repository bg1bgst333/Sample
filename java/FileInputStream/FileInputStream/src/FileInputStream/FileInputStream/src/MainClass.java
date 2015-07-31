// パッケージ・クラスのインポート
import java.io.File;	// Fileクラス(java.ioパッケージ)
import java.io.FileInputStream;	// FileInputStreamクラス(java.ioパッケージ)
import java.io.IOException;		// IOExceptionクラス(java.ioパッケージ)

//メインクラス
class MainClass {	// MainClassクラスの定義

	// Javaのエントリポイント
	public static void main(String[] args) {	// mainメソッドの定義

		// 変数の宣言
		byte[] buf = new byte[128];	// バッファbuf
		FileInputStream stream = null;	// ファイル入力ストリームstream

		// ファイルの存在確認
		File file = new File("test.txt");	// "test.txt"を示すFileオブジェクトfileを作成.
		if (!file.exists()){	// 存在しないなら.
			System.out.println("test.txt is not exist!");	// "test.txt is not exist!"と出力.
			System.exit(-1);	// exit(-1)で終了.
		}

		// ファイルの読み込み
		try {	// tryブロック
			stream = new FileInputStream(file);	// コンストラクタにfileを渡して, FileInputStreamオブジェクト生成.
			int len = stream.read(buf);	// readで読み込んだバイト列をbufに格納.(戻り値の読み込んだ長さをlenに格納.)
			for (int i = 0; i < len; i++){	// for文でlen文字繰り返す.
				System.out.print((char)buf[i]);	// bufの内容をcharにキャストして1文字ずつ出力.
			}
			stream.close();	// 閉じる.
		}
		catch (IOException e) {	// IOExceptionをキャッチしないといけない.
			// 例外処理
			System.out.println("e.toString() = " + e.toString());	// e.toString()の内容を出力.
			System.exit(-1);	// exit(-1)で終了.
			try {	// tryブロック
				stream.close();	// close()で閉じる.
			}
			catch (IOException e1) {	// IOExceptionをキャッチしないといけない.
				System.out.println("e1.toString() = " + e1.toString());	// e1.toString()の内容を出力.
				System.exit(-1);	// exit(-1)で終了.
			}
		}

	}

}