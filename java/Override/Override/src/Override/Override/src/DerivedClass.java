// 整数値, 文字列, 実数値, 真偽値を持つクラス
class DerivedClass extends BaseClass {	// BaseClassクラスを継承したDerivedClassクラスの定義.

	// フィールドの定義
	private float f;	// float型フィールドf
	private boolean b;	// boolean型フィールb

	// メソッドの定義
	// 初期化処理
	DerivedClass() {	// コンストラクタDerivedClass()
		super(0, "-");	// super(BaseClassのコンストラクタ)で, 0と"-"をセット.
		f = 0;			// fに0をセット.
		b = false;		// bにfalseをセット.
	}

	// 整数値, 文字列, 実数, 真偽値をフィールドにセット.
	public void set(int i, String str, float f, boolean b) {	// メソッドset(int i, String str, float f, boolean b)の定義.
		super.set(i, str);	// super.set(BaseClassのset)で, iとstrをセット.
		this.f = f;		// this.fにfをセット.
		this.b = b;		// this.bにbをセット.
	}

	// 各フィールドを出力.
	public void output() {	// メソッドoutputの定義
		super.output();	// super.output(BaseClassのoutput)で, iとstrを出力.
		System.out.println("f = " + f + ", " + "b = " + b);	// fとbを出力.
	}

}