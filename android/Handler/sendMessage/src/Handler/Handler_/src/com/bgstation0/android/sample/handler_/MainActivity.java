package com.bgstation0.android.sample.handler_;

import android.app.Activity;
import android.content.Context;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.Toast;

public class MainActivity extends Activity implements OnClickListener{	// View.OnClickListenerを実装.

	// メンバフィールドの定義.
	private final String TAG = "Handler_";	// TAG"Handler_"の定義.
	private Handler mHandler;	// HandlerオブジェクトmHandler.
	private Context mContext = null;	// Context型mContextをnullで初期化.
	
	@Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // コンテキスト初期化.
        mContext = this;	// mContextにthisをセット.
        
        // button1を取得し, OnClickListenerとして自身をセット.
        Button button1 = (Button)findViewById(R.id.button1);	// findViewByIdでR.id.button1を取得.
        button1.setOnClickListener(this);	// button1.setOnClickListenerでthis(自身)をセット.
        
    }
    
	// View.OnClickListenerインタフェースのオーバーライドメソッドを実装.
    public void onClick(View v){	// onClickをオーバーライド.
    
    	// ハンドラーの準備.
    	mHandler = new Handler(){	// Handlerオブジェクトhandlerの生成.
    		
    		// メッセージが来た時の処理.
    		@Override
    		public void handleMessage(Message msg){
    
    			// メッセージを確認.
    			if (msg != null){	// msgがnullでない.
    				Toast.makeText(mContext, "msg.obj = " + (String)msg.obj, Toast.LENGTH_LONG).show();	// msg.objを表示.
    				Toast.makeText(mContext, "msg.what = " + msg.what, Toast.LENGTH_LONG).show();	// msg.whatを表示.
    			}
    			
    			// メッセージが来たら, "Pushed!".
    			Button button1 = (Button)findViewById(R.id.button1);	// findViewByIdでR.id.button1を取得.
	    		button1.setText("Pushed!");	// button1.setTextで"Pushed!"に変更.
	    		
    		}
    		
    	};
    	
    	// スレッドの作成と実行.
    	CustomThread customThread = new CustomThread(mHandler, 1);	// コンストラクタにmHandlerと1を渡して, customThreadを作成.
    	customThread.start();	// customThread.start()で実行.
    		
    }
    
}