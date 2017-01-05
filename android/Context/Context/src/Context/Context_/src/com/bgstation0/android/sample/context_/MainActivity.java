package com.bgstation0.android.sample.context_;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.Toast;

public class MainActivity extends Activity implements OnClickListener{	// View.OnClickListenerを実装.

	// タグの定義
	private final String TAG = "MainActivity";	// TAGは"MainActivity"
		
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // Toastでthisの内容を文字列にしたものを表示.
     	Toast.makeText(this, this.toString(), Toast.LENGTH_LONG).show();
     		
        // button1を取得し, OnClickListenerとして自身をセット.
        Button button1 = (Button)findViewById(R.id.button1);	// findViewByIdでR.id.button1を取得.
        button1.setOnClickListener(this);	// button1.setOnClickListenerをthis(自身)をセット.
        
        // button2を取得し, OnClickListenerとして自身をセット.
        Button button2 = (Button)findViewById(R.id.button2);	// findViewByIdでR.id.button2を取得.
        button2.setOnClickListener(this);	// button2.setOnClickListenerをthis(自身)をセット.
        
        // button3を取得し, OnClickListenerとして自身をセット.
        Button button3 = (Button)findViewById(R.id.button3);	// findViewByIdでR.id.button3を取得.
        button3.setOnClickListener(this);	// button3.setOnClickListenerをthis(自身)をセット.
        
    }
    
    // View.OnClickListenerインタフェースのオーバーライドメソッドを実装.
    public void onClick(View v){	// onClickをオーバーライド.
    	
    	// switch-case文で振り分ける.
    	switch (v.getId()){	// v.getIdでidを取得し, idごとに振り分ける.
    		
    		// button1
    		case R.id.button1:
    			
    			// アクティビティの開始.
    	    	Intent intent1 = new Intent(this, SubActivity.class);	// SubActivityを対象としたIntentオブジェクトintent1を生成.
    	    	startActivity(intent1);	// startActivityでintent1を指定してActivityを起動.
    			break;	// breakで抜ける.
    	
    		// button2
    		case R.id.button2:
    			
    			// サービスの開始.
    			Intent intent2 = new Intent(this, SubService.class);	// SubServiceを対象としたIntentオブジェクトintent2を生成.
    			startService(intent2);	// startServiceでintent2を指定してServiceを起動.
    			Log.v(TAG, "startService(SubService)");	// Log.vで"startService(SubService)"と表示.
    			break;	// breakで抜ける.
    			
    		// button3
    		case R.id.button3:
    			
    			// サービスの停止.
    			Intent intent3 = new Intent(this, SubService.class);	// SubServiceを対象としたIntentオブジェクトintent3を生成.
    			stopService(intent3);	// stopServiceでintent3を指定してServiceを停止.
    			Log.v(TAG, "stopService(SubService)");	// Log.vで"stopService(SubService)"と表示.
    			break;	// breakで抜ける.
    			
    	}
    	
    }

}
