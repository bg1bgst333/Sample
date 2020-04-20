// サブオブジェクト
class SubObject implements Cloneable{

	// フィールド
	int data;	// int型フィールドdata

	// メソッド
	public void setData(int data) {	// dataをセットするメソッドsetData.
		this.data = data;	// メンバに引数をセット.
	}
	@Override
	public String toString(){	// オーバーライドメソッドtoString.
		String retStr = "SubObject[data = " + data + "]";	// retStrにメンバフィールドの値をセット.
		return retStr;	// retStrを返す.
	}
	@Override
	public Object clone(){	// オブジェクトのクローンをするオーバーライドメソッドclone.
		try{
			return (SubObject)super.clone();	// 親クラス(Object)のcloneを呼ぶ.
		}
		catch (CloneNotSupportedException e){
			throw new InternalError(e.getMessage());	// InternalErrorに投げる.
		}
	}
}