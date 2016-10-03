package com.bgstation0.android.sample.thread_;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;

public class MainActivity extends Activity implements OnClickListener{	// View.OnClickListenerを実装.

	// メンバフィールドの定義.
	//private final String TAG = "Thread_";	// TAG"Thread_"の定義.
	
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // button1を取得し, OnClickListenerとして自身をセット.
        Button button1 = (Button)findViewById(R.id.button1);	// findViewByIdでR.id.button1を取得.
        button1.setOnClickListener(this);	// button1.setOnClickListenerでthis(自身)をセット.
        
    }

    // View.OnClickListenerインタフェースのオーバーライドメソッドを実装.
    public void onClick(View v){	// onClickをオーバーライド.
    	
    	// Thread.sleepで擬似的に重たい処理を実行.
    	// tryで囲まないといけない.
    	/*
    	try{
    		Log.d(TAG, "Thread.sleep before");	// Log.dで"Thread.sleep before"とログ出力.
    		Thread.sleep(10000);	// Thread.sleepで10秒休止.
    		Log.d(TAG, "Thread.sleep after");	// Log.dで"Thread.sleep after"とログ出力.
    	}
    	catch(Exception ex){
    		Log.d(TAG, "ex = " + ex.toString());	// Log.dでexを出力.
    	}
    	*/
    	
    	// 重たい処理はCustomThreadで処理する.
    	CustomThread ct = new CustomThread();	// CustomThreadオブジェクトctを生成.
    	ct.start();	// ct.startで開始.
    	
    }
    
}
