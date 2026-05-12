// メインクラス
public class MainClass{

	// Javaのエントリポイント
	public static void main(String[] arg){ // mainメソッドの定義

		// 指定の書式で文字列を生成.
		String str = String.format("ABC:%s:DEF:%d", "XYZ", 123);

		// 出力.
		System.out.println(str);

	}

}
