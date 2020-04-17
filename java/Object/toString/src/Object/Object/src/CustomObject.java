// カスタムオブジェクト
class CustomObject {	// Objectの派生クラスCustomObject

	// フィールド
	String str;	// Stringクラスフィールドstr.
	int value;	// int型フィールドvalue.

	// メソッド
	public void setStr(String str) {	// strをセットするメソッドsetStr.
		this.str = str;	// メンバに引数をセット.
	}
	public void setValue(int value) {	// valueをセットするメソッドsetValue.
		this.value = value;	// メンバに引数をセット.
	}
	@Override
	public String toString(){	// オーバーライドメソッドtoString.
		String retStr = "CustomObject[str = " + str + ", " + "value = " + value + "]";	// retStrにメンバフィールドの値をセット.
		return retStr;	// retStrを返す.
	}

}