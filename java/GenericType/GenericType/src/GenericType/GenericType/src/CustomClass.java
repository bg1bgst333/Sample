// カスタムクラス
public class CustomClass<T>{	// CustomClassの定義
	private T val;	// T型val.
	public void setVal(T val){	// valに値をセット.
		this.val = val;	// メンバのvalに引数のvalをセット.
	}
	public T getVal(){	// valの値を返す.
		return this.val;	// メンバのvalを返す.
	}
}
