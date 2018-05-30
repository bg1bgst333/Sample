// メインクラス
public class MainClass{	// MainClassの定義

	// Javaのエントリポイント
	public static void main(String[] args){	// mainメソッドの定義

		// int型のラッパークラスIntegerオブジェクトの生成.
		Integer val = new Integer(123);	// Integerオブジェクトvalは初期値123のオブジェクト.

		// 文字列への変換.
		String str = val.toString();	// val.toStringで文字列にしたものをstrに格納.

		// val1とstr1の出力.
		System.out.println(val);	// valの出力.
		System.out.println(str);	// strの出力.

	}

}