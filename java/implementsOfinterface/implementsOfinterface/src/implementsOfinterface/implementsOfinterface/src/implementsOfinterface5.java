// 派生クラス
class implementsOfinterface5 extends implementsOfinterface2 implements implementsOfinterface3, implementsOfinterface4 {	// implementsOfinterface5クラスの定義

	// フィールドの定義
	String str;	// Stringクラスフィールドstr
	int i;		// int型フィールドi

	// メソッドの定義
	// iのセット
	public void set(int i) {	// set(int i)はimplementsOfinterface3から.
		this.i = i;	// this.iにiをセット.
	}

	// strのセット
	public void set(String str) {	// set(String str)はimplementsOfinterface3から.
		this.str = str;	// this.strにstrをセット.
	}

	// iとstrのセット
	public void set(int i, String str) {	// set(int i, String str)はimplementsOfinterface3から.
		this.i = i;	// this.iにiをセット.
		this.str = str;	// this.strにstrをセット.
	}

	// iのゲット
	public int getInt() {	// getInt()はimplementsOfinterface4から.
		return i;
	}

	// strのゲット
	public String getString() {	// getStringはimplementsOfinterface5から.
		return str;
	}

	// 出力
	public void output() {	// outputはimplementsOfinterface2から.
		System.out.println("i = " + i + ", str = " + str);	// iとstrを出力.
	}

}