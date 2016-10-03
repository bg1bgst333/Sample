package com.bgstation0.android.sample.runnable_;

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
	private final String TAG = "Runnable_";	// TAG"Runnable_"の定義.
	
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
    
    	// 匿名クラスでRunnableを実装したThreadを生成して開始.
    	new Thread(new Runnable(){	// Threadオブジェクトを生成, 引数にRunnableを継承した匿名クラスオブジェクトを渡す.(使い捨てなら参照を変数に格納しなくていい.)
    		public void run(){	// Runnable.runをオーバーライド.
    			try{
    	    		Log.d(TAG, "Thread.sleep before");	// Log.dで"Thread.sleep before"とログ出力.
    	    		Thread.sleep(10000);	// Thread.sleepで10秒休止.
    	    		Log.d(TAG, "Thread.sleep after");	// Log.dで"Thread.sleep after"とログ出力.
    	    	}
    	    	catch(Exception ex){
    	    		Log.d(TAG, "ex = " + ex.toString());	// Log.dでexを出力.
    	    	}
    		}
    	}).start();	// startで開始.
    	
    }
    
}
