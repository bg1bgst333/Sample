// メインクラス
public class MainClass{	// MainClassの定義

	// Javaのエントリポイント
	public static void main(String[] args){	// mainメソッドの定義
	
		// StringBuilderで文字列の連結をする.
		StringBuilder sb = new StringBuilder();	// StringBuilderオブジェクトsbの生成.
		sb.append("ABC").append("DEF").append("GHI"); // メソッドチェーンで書ける.
		System.out.println("sb.toString() = " + sb.toString());	// sbをStringに変換して出力.
		
	}

}
