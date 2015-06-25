// 派生クラス
class abstractClass4 extends abstractClass2 {	// abstractClass2クラスから派生したabstractClass4クラスの定義.

	// フィールドの定義
	int i;	// int型フィールドi.
	String str;	// Stringクラスフィールドstr.

	// メンバの定義
	// フィールドにセット.
	void set(int i, String str){	// set(int i, Strimg str)の定義.
		this.i = i;	// this.iにiをセット.
		this.str = str;	// this.strにstrをセット.
	}

	// 出力.
	void output(){	// output()の定義.
		System.out.println("[i, str] = " + "[" + i + ", " + str + "]");	// "[i, str] = [<整数値>, <文字列>]"の書式で出力.
	}

}