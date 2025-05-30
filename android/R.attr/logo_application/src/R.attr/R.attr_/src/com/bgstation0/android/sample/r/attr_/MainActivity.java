package com.bgstation0.android.sample.r.attr_;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
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
        
        // button2を取得し, OnClickListenerとして自身をセット.
        Button button2 = (Button)findViewById(R.id.button2);	// findViewByIdでR.id.button2を取得.
        button2.setOnClickListener(this);	// button2.setOnClickListenerでthis(自身)をセット.
        
    }
    
    // View.OnClickListenerインタフェースのオーバーライドメソッドを実装.
    public void onClick(View v){	// onClickをオーバーライド.
    	
    	// リソースIDごとに振り分け.
    	if (v.getId() == R.id.button1){	// button1.
    		
    		// button1が押されたらSubActivityを起動.
    		Intent intent = new Intent(this, SubActivity.class);	// SubActivityを対象としたIntentオブジェクトintentを生成.
    		startActivity(intent);	// startActivityでintentを指定してActivityを起動.
    	
    	}
    	else{	// button2.
    		
    		// button2が押されたらThirdActivityを起動.
    		Intent intent = new Intent(this, ThirdActivity.class);	// ThirdActivityを対象としたIntentオブジェクトintentを生成.
    		startActivity(intent);	// startActivityでintentを指定してActivityを起動.
    		
    	}
    	
    }
    
}