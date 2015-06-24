// 整数値と文字列を持つクラス
class Override2 {	// Override2クラスの定義

	// フィールドの定義
	private int i;	// int型フィールドi
	private String str;	// Stringクラスフィールドstr

	// メソッドの定義
	// 初期化処理
	Override2() {	// コンストラクタOverride2()
		i = 0;	// 0をiにセット.
		str = "-";	// "-"をstrにセット.
	}

	// 初期化処理(指定の値をセット.)
	Override2(int i, String str){	// コンストラクタOverride2(int i, String str).(これも名前が同じで引数が違うのでオーバーロードと言える.)
		this.i = i;	// iをthis.iにセット.(this.iはフィールドのi, iは引数のi.)
		this.str = str;	// strをthis.strにセット.(this.strはフィールドのstr, strは引数のstr.)
	}

	// 整数値と文字列をフィールドにセット.
	public void set(int i, String str) {	// メソッドset(int i, String str)の定義.
		this.i = i;	// iをthis.iにセット.(this.iはフィールドのi, iは引数のi.)
		this.str = str;	// strをstrにセット.(this.strはフィールドのstr, strは引数のstr.)
	}

	// 各フィールドを出力.
	public void output(){	// メソッドoutputの定義
		System.out.println("i = " + i + ", " + "str = " + str);	// iとstrを出力.
	}

}