package com.bgstation0.android.sample.view.basesavedstate_;

import android.os.Parcel;
import android.os.Parcelable;
import android.view.View.BaseSavedState;

// カスタムセーブドステート.
public class CustomSavedState extends BaseSavedState {

	// メンバフィールドの定義
	public String mStr1 = "";	// mStr1を""で初期化.
	public String mStr2 = "";	// mStr2を""で初期化.
	public String mStr3 = "";	// mStr3を""で初期化.
	
	// コンストラクタ
	public CustomSavedState(Parcelable superState){
		super(superState);
	}
	
	// プライベートコンストラクタ
	private CustomSavedState(Parcel in){
		super(in);
		mStr1 = in.readString();	// mStr1に格納.
		mStr2 = in.readString();	// mStr2に格納.
		mStr3 = in.readString();	// mStr3に格納.
	}
	
	// 書き込み.
	@Override
	public void writeToParcel(Parcel out, int flags){
		super.writeToParcel(out,  flags);
		out.writeString(mStr1);	// mStr1を書き込み.
		out.writeString(mStr2);	// mStr2を書き込み.
		out.writeString(mStr3);	// mStr3を書き込み.
	}
	
	public static final Parcelable.Creator<CustomSavedState> CREATOR = new Parcelable.Creator<CustomSavedState>(){
		public CustomSavedState createFromParcel(Parcel in){
			return new CustomSavedState(in);
		}
		public CustomSavedState[] newArray(int size){
			return new CustomSavedState[size];
		}
	};
	
}