// メインクラス
public class MainClass{	// MainClassの定義

	// Javaのエントリポイント
	public static void main(String[] args){	// mainメソッドの定義
	
		// StringBuilder.insertで文字列を挿入する.
		StringBuilder sb = new StringBuilder();	// StringBuilderオブジェクトsbの生成.
		sb.append("ABCDE"); // まずはappendで"ABCDE"を連結.
		sb.insert(3, "XYZ"); // insertで0から数えて3番目の位置に"XYZ"を挿入.
		System.out.println("sb.toString() = " + sb.toString());	// sbをStringに変換して出力.
		
	}

}
