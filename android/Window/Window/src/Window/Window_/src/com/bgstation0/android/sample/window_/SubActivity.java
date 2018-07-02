package com.bgstation0.android.sample.window_;

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
        
        // "onCreate"とtagの表示.
        Intent intent = getIntent();	// intentを取得.
        String tag = intent.getStringExtra("tag");	// "tag"の値を取得.
        //Toast.makeText(this, "onCreate(" + tag + ")", Toast.LENGTH_LONG).show();	// Toastで"onCreate"とtagを表示.
        
	}
	
	// Activityが開始されたとき.
	@Override
    protected void onStart(){
    	super.onStart();
    	
    	// "onStart"とtagの表示.
        Intent intent = getIntent();	// intentを取得.
        String tag = intent.getStringExtra("tag");	// "tag"の値を取得.
        //Toast.makeText(this, "onStart(" + tag + ")", Toast.LENGTH_LONG).show();	// Toastで"onStart"とtagを表示.
        
    }
	
	// Activityが破棄されたとき.
	@Override
    protected void onDestroy() {	// onDestroyの定義
    	
    	// 親クラスの処理
    	super.onDestroy();	// super.onDestroyで親クラスの既定処理.
    	
    	// "onDestroy"の表示.
        //Toast.makeText(this, "onDestroy", Toast.LENGTH_LONG).show();	// Toastで"onDestroy"を表示.
        
    }
    
    @Override
    protected void onNewIntent(Intent intent){
    	super.onNewIntent(intent);
    	
    	// "onNewIntent"とtagの表示.
        String tag = intent.getStringExtra("tag");	// "tag"の値を取得.
        //Toast.makeText(this, "onNewIntent(" + tag + ")", Toast.LENGTH_LONG).show();	// Toastで"onNewIntent"とtagを表示.
        
    }
	
}