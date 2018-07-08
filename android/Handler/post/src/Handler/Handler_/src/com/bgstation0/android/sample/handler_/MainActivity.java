package com.bgstation0.android.sample.handler_;

import android.app.Activity;
import android.os.Bundle;
import android.os.Handler;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;

public class MainActivity extends Activity implements OnClickListener{	// View.OnClickListenerを実装.

	// メンバフィールドの定義.
	private final String TAG = "Handler_";	// TAG"Handler_"の定義.
	private CustomHandler handler;	// CustomHandlerオブジェクトhandler.

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
    
    	// ハンドラーの準備.
    	handler = new CustomHandler(this);	// CustomHandlerオブジェクトhandlerのインスタンス生成.(thisを渡す.)
    	
    	// 匿名クラスでRunnableを実装したThreadを生成して開始.
    	new Thread(new Runnable(){	// Threadオブジェクトを生成, 引数にRunnableを継承した匿名クラスオブジェクトを渡す.(使い捨てなら参照を変数に格納しなくていい.)
    		public void run(){	// Runnable.runをオーバーライド.
    			// 10秒たったらButton1のテキストを"Pushed!"に変える.
    			try{
    	    		Thread.sleep(10000);	// Thread.sleepで10秒休止.
    	    		//Button button1 = (Button)findViewById(R.id.button1);	// findViewByIdでR.id.button1を取得.
    	    		//button1.setText("Pushed!");	// button1.setTextで"Pushed!"に変更.
    	    		handler.post();	// CustomHandler.postの実行.
    			}
    	    	catch(Exception ex){
    	    		Log.d(TAG, "ex = " + ex.toString());	// Log.dでexを出力.
    	    	}
    		}
    	}).start();	// startで開始.
    }
}
