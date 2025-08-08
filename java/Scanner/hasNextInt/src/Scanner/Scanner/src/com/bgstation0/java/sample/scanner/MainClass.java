// パッケージ名定義
package com.bgstation0.java.sample.scanner;	// com.bgstation0.java.sample.scannerパッケージ.

//パッケージ・クラスのインポート
import java.util.Scanner;	// Scannerクラス(java.utilパッケージ)

//メインクラス
public class MainClass {	// MainClassクラスの定義

	// Javaのエントリポイント
	public static void main(String[] args){	// mainメソッドの定義

		// Scannerオブジェクトscannerの生成.
		Scanner scanner = new Scanner(System.in);	// new Scanner(System.in)で標準入力を読み取るscannerを生成.
        System.out.print("number: ");
        if (scanner.hasNextInt()) {
            int number = scanner.nextInt();
            System.out.println("number = " + number);
        }
		else {
            System.out.println("Not number.");
        }

	}

}