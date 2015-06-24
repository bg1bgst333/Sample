// 整数値, 文字列, 実数値, 真偽値を持つクラス
class Override3 extends Override2 {	// Override2クラスを継承したOverride3クラスの定義.

	// フィールドの定義
	private float f;	// float型フィールドf
	private boolean b;	// boolean型フィールb

	// メソッドの定義
	// 初期化処理
	Override3() {	// コンストラクタOverride3()
		super(0, "-");	// super(Override2のコンストラクタ)で, 0と"-"をセット.
		f = 0;			// fに0をセット.
		b = false;		// bにfalseをセット.
	}

	// 整数値, 文字列, 実数, 真偽値をフィールドにセット.
	public void set(int i, String str, float f, boolean b) {	// メソッドset(int i, String str, float f, boolean b)の定義.
		super.set(i, str);	// super.set(Override2のset)で, iとstrをセット.
		this.f = f;		// this.fにfをセット.
		this.b = b;		// this.bにbをセット.
	}

	// 各フィールドを出力.
	public void output() {	// メソッドoutputの定義
		super.output();	// super.output(Override2のoutput)で, iとstrを出力.
		System.out.println("f = " + f + ", " + "b = " + b);	// fとbを出力.
	}

}