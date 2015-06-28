// メインクラス
class MainClass {	// MainClassクラスの定義

	// Javaのエントリポイント
	public static void main(String[] args) {	// mainメソッドの定義

		// try-catch
		try {	// 例外が起きそうな場所.(tryブロック)

			// 0で除算してみる.
			int i = 0 / 0;	// 0の除算になるので, 例外が発生する.

		}
		catch (Exception ex)	{	// 例外を処理する場所.(catchブロック)

			// 例外処理
			System.out.println("ex = " + ex.toString());	// toStringメソッドで例外exの内容を取得し, 出力.

		}

	}

}