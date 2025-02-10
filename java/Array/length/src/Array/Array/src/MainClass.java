// メインクラス
class MainClass {	// MainClassクラスの定義

	// Javaのエントリポイント
	public static void main(String[] args) {	// mainメソッドの定義

		// 配列の初期化
		int[] aryNumbers = new int[5];	// int型配列aryNumbersはint型の要素数5の配列として初期化.

		// 配列に値をセット.
		aryNumbers[0] = 7;	// aryNumbers[0]には7をセット.
		aryNumbers[1] = 4;	// aryNumbers[1]には4をセット.
		aryNumbers[2] = 6;	// aryNumbers[2]には6をセット.
		aryNumbers[3] = 10;	// aryNumbers[3]には10をセット.
		aryNumbers[4] = 3;	// aryNumbers[4]には3をセット.

		// 配列の各要素を出力.
		for (int i = 0; i < aryNumbers.length; i++) {	// iが0からaryNumbers.lengthの前まで繰り返す.

			// i番目を出力
			System.out.println("aryNumbers[" + i + "] = " + aryNumbers[i]);	// System.out.printlnでaryNumbers[i]の値を出力.

		}

	}

}