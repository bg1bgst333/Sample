// パッケージ・クラスのインポート
import java.io.File;	// Fileクラス(java.ioパッケージ)
import java.io.FileOutputStream;	// FileOutputStreamクラス(java.ioパッケージ)
import java.io.IOException;		// IOExceptionクラス(java.ioパッケージ)

//メインクラス
class MainClass {	// MainClassクラスの定義

	// Javaのエントリポイント
	public static void main(String[] args) {	// mainメソッドの定義

		// 変数の宣言
		byte[] buf = new byte[5];	// バイト値を持つbyte型配列buf.(長さ5)
		FileOutputStream stream = null;	// ファイル出力ストリームstream

		// bufにバイト値をセット.
		buf[0] = 0x41;	// 'A'
		buf[1] = 0x42;	// 'B'
		buf[2] = 0x43;	// 'C'
		buf[3] = 0x44;	// 'D'
		buf[4] = 0x45;	// 'E'

		// ファイルの存在確認
		File file = new File("test.txt");	// "test.txt"を示すFileオブジェクトfileを作成.
		if (!file.exists()){	// 存在しない場合.
			System.out.println("test.txt is not exist!");	// "test.txt is not exist!"と出力.(強制終了はしない.)
		}

		// test.txtに書き込む.
		try{	// tryブロック
			stream = new FileOutputStream(file);	// コンストラクタにfileを渡して, FileOutputStreamオブジェクト生成.
			stream.write(buf);	// write()でbufを書き込む.
			stream.close();	// close()で閉じる.
		}
		catch (IOException e) {	// IOExceptionの時.
			// 例外処理
			System.out.println("e.toString() = " + e.toString());	// e.toString()の内容を出力.
			try {	// tryブロック
				stream.close();	// close()で閉じる.
			}
			catch (IOException e1) {	// IOExceptionをキャッチしないといけない.
				System.out.println("e1.toString() = " + e1.toString());	// e1.toString()の内容を出力.
				System.exit(-1);	// exit(-1)で終了.
			}
			System.exit(-1);	// exit(-1)で終了.
		}

	}

}