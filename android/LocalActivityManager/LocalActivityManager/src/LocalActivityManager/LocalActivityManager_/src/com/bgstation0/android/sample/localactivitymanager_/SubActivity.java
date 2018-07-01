package com.bgstation0.android.sample.localactivitymanager_;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.widget.Toast;

public class SubActivity extends Activity {

	// Activityが作成された時.
	@Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_sub);
        
        // "onCreate"の表示.
        Toast.makeText(this, "onCreate", Toast.LENGTH_LONG).show();	// Toastで"onCreate"を表示.
        
	}
	
	// Activityが破棄されたとき.
    protected void onDestroy() {	// onDestroyの定義
    	
    	// 親クラスの処理
    	super.onDestroy();	// super.onDestroyで親クラスの既定処理.
    	
    	// "onDestroy"の表示.
        Toast.makeText(this, "onDestroy", Toast.LENGTH_LONG).show();	// Toastで"onDestroy"を表示.
        
    }
	
}