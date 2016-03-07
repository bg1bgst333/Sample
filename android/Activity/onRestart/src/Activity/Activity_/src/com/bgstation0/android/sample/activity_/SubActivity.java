package com.bgstation0.android.sample.activity_;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

// MainActivityによって起動されるSubActivity.
public class SubActivity extends Activity {	// SubActivityの定義.

	// タグの定義
	private final String TAG = "SubActivity";	// TAGは"SubActivity"
	
	// Activityが生成されたとき.
	@Override
    protected void onCreate(Bundle savedInstanceState) {	// onCreateの定義
		
		// 親クラスの処理
		super.onCreate(savedInstanceState);	// super.onCreateで親クラスの既定処理.
		
		// "SubActivity!"の表示.
		TextView tv = new TextView(this);	// TextViewオブジェクトtvの生成.
		tv.setText("SubActivity!");	// tv.setTextで"SubActivity!"のセット.
		setContentView(tv);	// setContentViewでtvを表示.
	}
	
    // Activityが開始されたとき.
    protected void onStart() {	// onStartの定義
    	
    	// 親クラスの処理
    	super.onStart();	// super.onStartで親クラスの既定処理.
    	
    	// onStartのログを表示.
    	Log.v(TAG, "onStart()");	// Log.vで"onStart()"と出力.
    }
    
    // Activityが再開されるとき.
    protected void onRestart() {	// onRestartの定義
    	
    	// 親クラスの処理
    	super.onRestart();	// super.onRestartで親クラスの既定処理.
    	
    	// onRestartのログを表示.
    	Log.v(TAG, "onRestart()");	// Log.vで"onRestart()"と出力.
    }
    
    // Activityが表示されるとき.
    protected void onResume() {	// onResumeの定義
    	
    	// 親クラスの処理
    	super.onResume();	// super.onResumeで親クラスの既定処理.
    	
    	// onResumeのログを表示.
    	Log.v(TAG, "onResume()");	// Log.vで"onResume()"と出力.
    }
    
    // Activityが一時停止されたとき.
    protected void onPause() {	// onPauseの定義
    	
    	// 親クラスの処理
    	super.onPause();	// super.onPauseで親クラスの既定処理.
    	
    	// onPauseのログを表示.
    	Log.v(TAG, "onPause()");	// Log.vで"onPause()"と出力.
    }
    
    // Activityが停止されたとき.
    protected void onStop() {	// onStopの定義
    	
    	// 親クラスの処理
    	super.onStop();	// super.onStopで親クラスの既定処理.
    	
    	// onStopのログを表示.
    	Log.v(TAG, "onStop()");	// Log.vで"onStop()"と出力.
    }
    
    // Activityが破棄されたとき.
    protected void onDestroy() {	// onDestroyの定義
    	
    	// 親クラスの処理
    	super.onDestroy();	// super.onDestroyで親クラスの既定処理.
    	
    	// onDestroyのログを表示.
    	Log.v(TAG, "onDesroy()");	// Log.vで"onDestroy()"と出力.
    }
}
