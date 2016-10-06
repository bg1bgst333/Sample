package com.bgstation0.android.sample.intentservice_;

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
    	// CustomIntentServiceの起動
    	int param = 10;	// int型paramを10にセット.
    	Intent intent = new Intent(this, CustomIntentService.class);	// CustomIntentServiceを起動するintentを作成.
    	intent.putExtra("param", param);	// intent.putExtraでキーを"param", 値をparam( = 10)として引数を渡す.
    	Log.d("MainActivity", "startService, param = " + param);	// Log.dで"startService"とparamの値を出力.
    	startService(intent);	// startServiceでintentの指すサービスを起動.   	
    }
}
