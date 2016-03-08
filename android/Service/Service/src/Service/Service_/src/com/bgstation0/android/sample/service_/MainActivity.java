package com.bgstation0.android.sample.service_;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;

public class MainActivity extends Activity implements OnClickListener{	// View.OnClickListenerを実装.

	// タグの定義
	private final String TAG = "MainActivity";	// TAGは"MainActivity"

	// Activityが生成されたとき.
    @Override
    protected void onCreate(Bundle savedInstanceState) {	// onCreateの定義
    	
    	// 親クラスの処理と, activity_mainの表示.
        super.onCreate(savedInstanceState);	// super.onCreateで親クラスの既定処理.
        setContentView(R.layout.activity_main);	// setContentViewでR.layout.activity_mainを表示.
        
        // button1を取得し, OnClickListenerとして自身をセット.
        Button button1 = (Button)findViewById(R.id.button1);	// findViewByIdでR.id.button1を取得.
        button1.setOnClickListener(this);	// button1.setOnClickListenerをthis(自身)をセット.
        
        // button2を取得し, OnClickListenerとして自身をセット.
        Button button2 = (Button)findViewById(R.id.button2);	// findViewByIdでR.id.button2を取得.
        button2.setOnClickListener(this);	// button2.setOnClickListenerをthis(自身)をセット.
        
        // onCreateのログを表示.
        Log.v(TAG, "onCreate()");	// Log.vで"onCreate()"と出力.
    }
    
    // View.OnClickListenerインタフェースのオーバーライドメソッドを実装.
    public void onClick(View v){	// onClickをオーバーライド.
    	
    	// switch-case文で振り分ける.
    	switch (v.getId()){	// v.getIdでidを取得し, idごとに振り分ける.
    		
    		// button1
    		case R.id.button1:
    			
    			// サービスの開始
    			Intent intent1 = new Intent(this, MainService.class);	// MainServiceを対象としたIntentオブジェクトintent1を生成.
    			startService(intent1);	// startServiceでintent1を指定してServiceを起動.
    			Log.v(TAG, "startService(MainService)");	// Log.vで"startService(MainService)"と表示.
    			break;	// breakで抜ける.
    			
    		// button2
    		case R.id.button2:

    			// サービスの開始
    			Intent intent2 = new Intent(this, MainService.class);	// MainServiceを対象としたIntentオブジェクトintent2を生成.
    			stopService(intent2);	// stopServiceでintent2を指定してServiceを停止.
    			Log.v(TAG, "stopService(MainService)");	// Log.vで"stopService(MainService)"と表示.
    			break;	// breakで抜ける.
    			
    	}
    }
}
