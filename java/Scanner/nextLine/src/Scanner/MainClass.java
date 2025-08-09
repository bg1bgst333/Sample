//パッケージ・クラスのインポート
import java.util.Scanner;	// Scannerクラス(java.utilパッケージ)

//メインクラス
public class MainClass {	// MainClassクラスの定義

	// Javaのエントリポイント
	public static void main(String[] args){ // mainメソッドの定義

		// Scannerオブジェクトscannerの生成.
		Scanner scanner = new Scanner(System.in);       // new Scanner(System.in)で標準入力を読み取るscannerを生成.
		System.out.print("text1: ");
		String text1 = scanner.nextLine();
		System.out.println("text1 = " + text1);
		System.out.print("number1: ");
		int number1 = scanner.nextInt();
		System.out.println("number1 = " + number1);
		scanner.nextLine();	// 数値の後の改行を読み飛ばす.
		System.out.print("text2: ");
		String text2 = scanner.nextLine();
		System.out.println("text2 = " + text2);

	}

}