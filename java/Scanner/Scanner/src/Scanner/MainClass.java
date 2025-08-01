// パッケージ・クラスのインポート
import java.util.Scanner; // Scannerクラス(java.utilパッケージ)

// メインクラス
class MainClass { // MainClassクラスの定義

  // Javaのエントリポイント
  public static void main(String[] args){ // mainメソッドの定義

    // Scannerオブジェクトscannerの生成.
    Scanner scanner = new Scanner(System.in); // new Scanner(System.in)で標準入力を読み取るscannerを生成.

    // デフォルトの区切り文字(空白文字)まで読み取る.
    String text = scanner.next(); // scanner.nextで読み込んだ文字列をtextに取得.

    // textを出力.
    System.out.println("text = " + text); // System.out.printlnでtextを出力.

  }

}
