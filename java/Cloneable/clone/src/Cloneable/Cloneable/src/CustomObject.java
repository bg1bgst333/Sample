// カスタムオブジェクト
class CustomObject implements Cloneable{	// Objectの派生クラスCustomObject(Cloneableを実装.)

	// フィールド
	String str;	// Stringクラスフィールドstr.
	int value;	// int型フィールドvalue.
	SubObject subObj;	// SubObjectクラスフィールドsubObj.

	// メソッド
	public void setStr(String str) {	// strをセットするメソッドsetStr.
		this.str = str;	// メンバに引数をセット.
	}
	public void setValue(int value) {	// valueをセットするメソッドsetValue.
		this.value = value;	// メンバに引数をセット.
	}
	public void setSubObj(SubObject subObj){	// subObjをセットするメソッドsetSubObj.
		this.subObj = subObj;	// メンバに引数をセット.
	}
	public void setData(int data){	// subObjのdataをセットするメソッドsetData.
		this.subObj.data = data;	// メンバのメンバに引数をセット.
	}
	@Override
	public String toString(){	// オーバーライドメソッドtoString.
		String retStr = "CustomObject[str = " + str + ", " + "value = " + value + ", subObj.data = " + subObj.data + "]";	// retStrにメンバフィールドの値をセット.
		return retStr;	// retStrを返す.
	}
	@Override
	public Object clone(){	// オブジェクトのクローンをするオーバーライドメソッドclone.
		try{
			// まず自身をクローン.
			CustomObject customObj = (CustomObject)super.clone();	// super.cloneの戻り値をcustomObjに代入.
			// subObjをクローン.
			customObj.subObj = (SubObject)this.subObj.clone();	// customObj.subObjにsubObj.cloneを代入.
			return customObj;	// customObjを返す.
		}
		catch (CloneNotSupportedException e){
			throw new InternalError(e.getMessage());	// InternalErrorに投げる.
		}
	}

}