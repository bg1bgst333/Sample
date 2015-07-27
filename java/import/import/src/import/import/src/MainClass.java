// パッケージ・クラスのインポート
import java.io.File;	// Fileクラス(java.ioパッケージ)

// メインクラス
class MainClass {	// MainClassクラスの定義

	// Javaのエントリポイント
	public static void main(String[] args) {	// mainメソッドの定義

		// ファイルの存在を確認.
		File f = new File("test.txt");	// Fileオブジェクトfを作成.(確認したいファイル名"test.txt"を指定.)
		if (f.exists()){	// exists()メソッドで存在しているか確認.
			System.out.println("Exist!");	// 真なら(存在していれば)"Exist!"を出力.
		}
		else{
			System.out.println("Not Exist!");	// 偽なら(存在していなければ)"Not Exist!"を出力.
		}

	}

}