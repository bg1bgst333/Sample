// メインクラス
public class MainClass{	// MainClassの定義

	// Javaのエントリポイント
	public static void main(String[] args){	// mainメソッドの定義

		// StringBufferで文字列の連結をする.
		StringBuffer sb = new StringBuffer();	// StringBufferオブジェクトsbの生成.
		sb.append("ABC");	// sb.appendで"ABC"を連結.
		System.out.println("sb.toString() = " + sb.toString());	// sbをStringに変換して出力.
		sb.append("DEF");	// sb.appendで"DEF"を連結.
		System.out.println("sb.toString() = " + sb.toString());	// sbをStringに変換して出力.
		sb.append("GHI");	// sb.appendで"GHI"を連結.
		System.out.println("sb.toString() = " + sb.toString());	// sbをStringに変換して出力.

	}

}