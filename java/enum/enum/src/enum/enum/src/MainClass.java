// メインクラス
public class MainClass{	// MainClassの定義

	// Javaのエントリポイント
	public static void main(String[] args){

		// カスタム列挙型を使う.
		CustomEnum customEnum = CustomEnum.SECOND;	// SECOND.

		// どれか判定.
		if (customEnum == CustomEnum.FIRST){	// FIRSTなら.
			System.out.println(CustomEnum.FIRST);	// 定数側をそのまま出力.
		}
		else if (customEnum == CustomEnum.SECOND){	// SECONDなら.
			System.out.println(CustomEnum.SECOND);	// 定数側をそのまま出力.
		}
		else if (customEnum == CustomEnum.THIRD){	// THIRDなら.
			System.out.println(CustomEnum.THIRD);	// 定数側をそのまま出力.
		}

		// 変数側も出力.
		System.out.println(customEnum);	// そのまま出力.

	}

}