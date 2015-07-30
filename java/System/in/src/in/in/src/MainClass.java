// パッケージ・クラスのインポート
import java.io.IOException;	// IOExceptionクラス(java.ioパッケージ)

// メインクラス
class MainClass {	// MainClassクラスの定義

	// Javaのエントリポイント
	public static void main(String[] args) {	// mainメソッドの定義

		// 変数の初期化
		byte buf[] = new byte[128];	// バッファ用byte型配列buf(長さ128)を生成.
		
		// System.in.read()で読み込む.
		try {
				System.in.read(buf);	// System.in.read(byte[] b)で読み込んだ文字列をbufに格納.
				System.out.write(buf);	// System.out.writeでbufの内容を出力.
		}
		catch (IOException e) {	// IOExceptionをキャッチしないといけない.
				// 例外処理
				System.out.println("e.toString() = " + e.toString());	// e.toString()の内容を出力.
		}

	}

}