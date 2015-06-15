// 整数値と文字列を持つクラス
class Class2 {	// Class2クラスの定義

	// フィールドの定義
	private int i;	// int型フィールドi
	private String str;	// Stringクラスフィールドstr

	// メソッドの定義
	// 整数値と文字列をフィールドにセット.
	public void set(int n, String s) {	// メソッドsetの定義
		i = n;	// nをiにセット.
		str = s;	// sをstrにセット.
	}

	// 各フィールドを出力.
	public void output(){	// メソッドoutputの定義
		System.out.println("i = " + i + ", " + "str = " + str);	// iとstrを出力.
	}

}