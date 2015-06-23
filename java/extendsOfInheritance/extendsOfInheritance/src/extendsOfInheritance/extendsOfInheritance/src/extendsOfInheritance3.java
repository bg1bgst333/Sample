// 整数値, 文字列, 実数値, 真偽値を持つクラス
class extendsOfInheritance3 extends extendsOfInheritance2 {	// extendsOfInheritance2クラスを継承したextendsOfInheritance3クラスの定義.

	// フィールドの定義
	private float f;	// float型フィールドf
	private boolean b;	// boolean型フィールb

	// メソッドの定義
	// 初期化処理
	extendsOfInheritance3() {	// コンストラクタextendsOfInheritance3()
		set(0, "-");	// extendsOfInheritance2のsetで, 0と"-"をセット.
		f = 0;			// fに0をセット.
		b = false;		// bにfalseをセット.
	}

	// 整数値, 文字列, 実数, 真偽値をフィールドにセット.
	public void set(int i, String str, float f, boolean b) {	// メソッドset(int i, String str, float f, boolean b)の定義.
		set(i, str);	// extendsOfInheritance2のsetで, iとstrをセット.
		this.f = f;		// this.fにfをセット.
		this.b = b;		// this.bにbをセット.
	}

	// 各フィールドを出力.
	public void outputAll() {	// メソッドoutputAllの定義
		output();	// extendsOfInheritance2のoutputで, iとstrを出力.
		System.out.println("f = " + f + ", " + "b = " + b);	// fとbを出力.
	}

}
