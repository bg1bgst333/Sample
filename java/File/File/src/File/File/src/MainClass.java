// パッケージ・クラスのインポート
import java.io.File;	// Fileクラス(java.ioパッケージ)

// メインクラス
class MainClass {	// MainClassクラスの定義

	// Javaのエントリポイント
	public static void main(String[] args) {	// mainメソッドの定義

		// ファイルオブジェクトの作成.
		File file = new File("dir", "test.txt");	// Fileオブジェクトfileを作成.(アクセスしたいファイルがあるフォルダの相対パス"dir"とファイル名"test.txt"を指定.)
		if (file.exists()){	// exists()メソッドで存在しているか確認.
			System.out.println("Exist!");	// 真なら(存在していれば)"Exist!"を出力.
		}
		else{
			System.out.println("Not Exist!");	// 偽なら(存在していなければ)"Not Exist!"を出力.
		}

	}

}