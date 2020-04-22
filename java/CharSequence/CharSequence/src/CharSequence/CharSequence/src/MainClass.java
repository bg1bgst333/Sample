// メインクラス
public class MainClass{	// MainClassの定義

	// Javaのエントリポイント
	public static void main(String[] args){	// mainメソッドの定義

		// Stringで渡す.
		String str = "ABCDE";	// Stringオブジェクトstrを"ABCDE"で初期化.
		func(str);	// funcにstrを渡す.

		// StringBufferで渡す.
		StringBuffer sb = new StringBuffer();	// StringBufferオブジェクトsbを生成.
		sb.append("FGHIJ");	// sb.appendで"FGHIJ"を連結.
		func(sb);	// funcにsbを渡す.

	}

	// CharSequenceを受け取るメソッドfunc.
	public static void func(CharSequence cs){

		// 内容と長さを出力.
		System.out.println("cs = " + cs + ", cs.length() = " + cs.length());	// csの中身とcs.lengthを出力.

	}

}