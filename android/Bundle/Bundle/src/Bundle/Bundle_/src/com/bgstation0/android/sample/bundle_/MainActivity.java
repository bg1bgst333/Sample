package com.bgstation0.android.sample.bundle_;

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
        button1.setOnClickListener(this);	// button1.setOnClickListenerをthis(自身)をセット.
    }
    
    // View.OnClickListenerインタフェースのオーバーライドメソッドを実装.
    public void onClick(View v){	// onClickをオーバーライド.

    	// SubActivityに渡すパラメータの準備.
    	Bundle args = new Bundle();	// Bundleオブジェクトargsの生成.
    	args.putString("str", "ABCDE");	// キーを"str", 値を"ABCDE"としてputStringでセット.
    	args.putInt("num", 10);	// キーを"num", 値を10としてputIntでセット.
    	args.putBoolean("bool", true);	// キーを"bool", 値をtrueとしてputBooleanでセット.
    	
    	// アクティビティの開始.
    	Intent intent1 = new Intent(this, SubActivity.class);	// SubActivityを対象としたIntentオブジェクトintent1を生成.
    	intent1.putExtras(args);	//  intent1.putExtrasでargsをintent1にセット.
    	startActivity(intent1);	// startActivityでintent1を指定してActivityを起動.
    	
    }
    
}
