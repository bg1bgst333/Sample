package com.bgstation0.android.sample.log_;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;

public class MainActivity extends Activity {

	// ログを検索しやすくするためのタグを定義.
	private final String TAG = "MainActivity";	// TAGを"MainActivity"とする.(finalなので変更不可の文字列.)
	
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // ログの表示
        Log.v(TAG, "onCreate(VERBOSE)");	// Log.vでログレベルVERBOSEなログとして"onCreate(VERBOSE)"を出力.
        Log.d(TAG, "onCreate(DEBUG)");		// Log.dでログレベルDEBUGなログとして"onCreate(DEBUG)"を出力.
        Log.i(TAG, "onCreate(INFO)");		// Log.iでログレベルINFOなログとして"onCreate(INFO)"を出力.
        Log.w(TAG, "onCreate(WARN)");		// Log.wでログレベルWARNなログとして"onCreate(WARN)"を出力.
        Log.e(TAG, "onCreate(ERROR)");		// Log.eでログレベルERRORなログとして"onCreate(ERROR)"を出力.
    }
}
