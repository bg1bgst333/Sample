package com.bgstation0.android.sample.application_;

import android.app.Application;
import android.widget.Toast;

public class CustomApplication extends Application {

	// メンバフィールドの定義
	private int appCount = 0;	// int型appCountを0に初期化.

	// アプリケーション作成時.
	@Override
	public void onCreate(){
		super.onCreate();
		
		// ToastでappCountを表示.
		Toast.makeText(this, "appCount = " + appCount, Toast.LENGTH_LONG).show();
	}
	
	// アプリケーション終了時.(実際には呼ばれないので注意!)
	@Override
	public void onTerminate(){
		// ToastでappCountを表示.
		Toast.makeText(this, "appCount = " + appCount, Toast.LENGTH_LONG).show();
				
		super.onTerminate();
	}
	
	// appCountの取得
	public int getAppCount(){
		return appCount;	// appCountを返す.
	}
	
	// appCountの設定
	public void setAppCount(int count){
		appCount = count;	// appCountにcountを代入.
	}
}
