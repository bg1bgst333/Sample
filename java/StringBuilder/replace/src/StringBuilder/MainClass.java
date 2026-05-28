// メインクラス
public class MainClass{	// MainClassの定義

	// Javaのエントリポイント
	public static void main(String[] args){	// mainメソッドの定義
	
		// StringBuilder.replaceで一部を指定の文字列に置換する.
		StringBuilder sb = new StringBuilder();	// StringBuilderオブジェクトsbの生成.
		sb.append("ABCDE"); // まずはappendで"ABCDE"を連結.
		sb.replace(2, 4, "XYZ"); // 2番目から4番目の前までを"XYZ"で置換.
		System.out.println("sb.toString() = " + sb.toString());	// sbをStringに変換して出力.
		
	}

}
