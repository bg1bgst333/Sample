package com.bgstation0.android.sample.activity_;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;

public class MainActivity extends Activity {

	// タグの定義
	private final String TAG = "MainActivity";	// TAGは"MainActivity"
	
	// Activityが生成されたとき.
    @Override
    protected void onCreate(Bundle savedInstanceState) {	// onCreateの定義
    	
    	// 親クラスの処理と, activity_mainの表示.
        super.onCreate(savedInstanceState);	// super.onCreateで親クラスの既定処理.
        setContentView(R.layout.activity_main);	// setContentViewでR.layout.activity_mainを表示.
        
        // onCreateのログを表示.
        Log.v(TAG, "onCreate()");	// Log.vで"onCreate()"と出力.   
    }
    
    // Activityが開始されたとき.
    protected void onStart() {	// onStartの定義
    	
    	// 親クラスの処理
    	super.onStart();	// super.onStartで親クラスの既定処理.
    	
    	// onStartのログを表示.
    	Log.v(TAG, "onStart()");	// Log.vで"onStart()"と出力.
    }
    
    // Activityが表示されるとき.
    protected void onResume() {	// onResumeの定義
    	
    	// 親クラスの処理
    	super.onResume();	// super.onResumeで親クラスの既定処理.
    	
    	// onResumeのログを表示.
    	Log.v(TAG, "onResume()");	// Log.vで"onResume()"と出力.
    }
}
