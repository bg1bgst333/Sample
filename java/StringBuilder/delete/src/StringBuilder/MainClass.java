// メインクラス
public class MainClass{	// MainClassの定義

	// Javaのエントリポイント
	public static void main(String[] args){	// mainメソッドの定義
	
		// StringBuilder.deleeteで一部を削除する.
		StringBuilder sb = new StringBuilder();	// StringBuilderオブジェクトsbの生成.
		sb.append("ABCDE"); // まずはappendで"ABCDE"を連結.
		sb.delete(2, 4); // 2番目から4番目の前まで削除.
		System.out.println("sb.toString() = " + sb.toString());	// sbをStringに変換して出力.
		
	}

}
