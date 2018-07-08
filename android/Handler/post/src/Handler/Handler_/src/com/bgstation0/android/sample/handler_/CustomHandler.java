package com.bgstation0.android.sample.handler_;

import android.content.Context;
import android.os.Handler;
import android.widget.Button;

public class CustomHandler extends Handler implements Runnable{

	// メンバフィールドの定義.
	Context mContext = null;	// mContextをnullで初期化.
	
	// コンストラクタ
	public CustomHandler(Context context){
		
		// メンバにセット.
		mContext = context;	// mContextにcontextをセット.
		
	}
	
	// メッセージキューにポスト.
	public boolean post(){
		return super.post(this);
	}
	
	// 実行処理.
	@Override
	public void run(){
		Button button1 = (Button)((MainActivity)mContext).findViewById(R.id.button1);	// button1を取得.
		button1.setText("Pushed!");	// "Pushed!"に変更.
	}
	
}
