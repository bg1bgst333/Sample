// 派生クラス
class DerivedClass extends BaseClass implements SetInterface, GetInterface {	// DerivedClassクラスの定義

	// フィールドの定義
	String str;	// Stringクラスフィールドstr
	int i;		// int型フィールドi

	// メソッドの定義
	// iのセット
	public void set(int i) {	// set(int i)はSetInterfaceから.
		this.i = i;	// this.iにiをセット.
	}

	// strのセット
	public void set(String str) {	// set(String str)はSetInterfaceから.
		this.str = str;	// this.strにstrをセット.
	}

	// iとstrのセット
	public void set(int i, String str) {	// set(int i, String str)はSetInterfaceから.
		this.i = i;	// this.iにiをセット.
		this.str = str;	// this.strにstrをセット.
	}

	// iのゲット
	public int getInt() {	// getInt()はGetInterfaceから.
		return i;
	}

	// strのゲット
	public String getString() {	// getStringはGetInterfaceから.
		return str;
	}

	// 出力
	public void output() {	// outputはBaseClassから.
		System.out.println("i = " + i + ", str = " + str);	// iとstrを出力.
	}

}