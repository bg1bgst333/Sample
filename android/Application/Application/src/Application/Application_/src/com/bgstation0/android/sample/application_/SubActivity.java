package com.bgstation0.android.sample.application_;

import android.app.Activity;
import android.os.Bundle;
import android.widget.TextView;
import android.widget.Toast;

public class SubActivity extends Activity {

	// メンバフィールドの定義
	private CustomApplication customApp;	// CustomApplication型customApp
	private int subCount = 0;	// int型subCountを0に初期化.
	
	// Activityが生成されたとき.
	@Override
	protected void onCreate(Bundle savedInstanceState) {	// onCreateの定義
		super.onCreate(savedInstanceState);
			
		// "SubActivity!"の表示.
		TextView tv = new TextView(this);	// TextViewオブジェクトtvの生成.
		tv.setText("SubActivity!");	// tv.setTextで"SubActivity!"のセット.
		setContentView(tv);	// setContentViewでtvを表示.

		// ToastでsubCountの値を表示.
		Toast.makeText(this, "subCount = " + subCount, Toast.LENGTH_LONG).show();		
				
		// subCountを1増やす.
		subCount++;	// subCountをインクリメント.
		
		// CustomApplicationオブジェクトの取得.
		customApp = (CustomApplication)getApplication();	// getApplicationでcustomAppを取得.
		
		// customAppのappCount取得.
		int appCount = customApp.getAppCount();	// customApp.getAppCountでappCountを取得.
		
		// ToastでappCountの値を表示.
		Toast.makeText(this, "appCount = " + appCount, Toast.LENGTH_LONG).show();
		
		// appCountを1増やす.
		appCount++;	// appCountをインクリメント.
		
		// customAppのaooCount設定.
		customApp.setAppCount(appCount);	// customApp.setAppCountでappCountを設定.
	}
		
	// Activityが破棄されたとき.
	@Override
	protected void onDestroy(){
		
		// ToastでsubCountの値を表示.
		Toast.makeText(this, "subCount = " + subCount, Toast.LENGTH_LONG).show();
		
		// customAppのappCount取得.
		int appCount = customApp.getAppCount();	// customApp.getAppCountでappCountを取得.
				
		// ToastでappCountの値を表示.
		Toast.makeText(this, "appCount = " + appCount, Toast.LENGTH_LONG).show();
						
		super.onDestroy();
	}
}
