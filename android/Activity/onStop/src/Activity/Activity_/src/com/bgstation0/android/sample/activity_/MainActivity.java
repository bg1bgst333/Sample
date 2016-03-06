package com.bgstation0.android.sample.activity_;

import android.app.Activity;
import android.content.Intent;
import android.net.Uri;
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
        button1.setOnClickListener(this);	// button1.setOnClickListenerでthis(自身)をセット.
        
        // onCreateのログを表示.
        Log.v(TAG, "onCreate()");	// Log.vで"onCreate()"と出力.       
    }
    
    // View.OnClickListenerインタフェースのオーバーライドメソッドを実装.
    public void onClick(View v){	// onClickをオーバーライド.
    	// ボタンが押されたらインテントで"http://bg1hatenablog.com"を開くことができるアプリに渡して表示してもらう.
    	Intent intent = new Intent(Intent.ACTION_VIEW, Uri.parse("http://bg1.hatenablog.com"));	// Intent.ACTION_VIEW(画面表示アクション)で"http://bg1.hatenablog.com"を表示するIntentオブジェクトintentを生成.
    	startActivity(intent);	// startActivityでintentを指定して表示してくれるアプリを起動.
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
