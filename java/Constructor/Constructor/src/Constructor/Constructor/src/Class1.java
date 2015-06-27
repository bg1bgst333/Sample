// 整数値と文字列を持つクラス
class Class1 {	// Class1クラスの定義

	// フィールドの定義
	private int i;	// int型フィールドi
	private String str;	// Stringクラスフィールドstr

	// メソッドの定義
	// 初期化処理
	Class1(){	// コンストラクタClass1()
		i = 0;	// 0をiにセット.
		str = "-";	// "-"をstrにセット.
	}

	// 初期化処理(指定の値をセット.)
	Class1(int n, String s){	// コンストラクタClass1(int n, String s)
		i = n;	// nをiにセット.
		str = s;	// sをstrにセット.
	}

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