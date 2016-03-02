package com.bgstation0.android.sample.view_;

import android.app.Activity;
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
        
        // button3を取得し, OnClickListenerとして自身をセット.
        Button button3 = (Button)findViewById(R.id.button3);	// findViewByIdでR.id.button3を取得.
        button3.setOnClickListener(this);	// button3.setOnClickListenerでthis(自身)をセット.       
    }
    
    // View.OnClickListenerインタフェースのオーバーライドメソッドを実装.
    public void onClick(View v){	// onClickをオーバーライド.
    	// ボタンのidをごとに処理を振り分ける.
    	switch (v.getId()) {	// v.getIdでView(Button)のidを取得.
    		case R.id.button1:	// R.id.button1の時.
    			Button b1 = (Button)v;	// vを(Button)にキャストしてb1に格納.
    			b1.setText("Clicked!");	// b1.setTextで"Clicked!"に変更.
    			break;	// breakで抜ける.
    		case R.id.button2:	// R.id.button2の時.
    			Button b2 = (Button)v;	// vを(Button)にキャストしてb2に格納.
    			b2.setText("Clicked!");	// b2.setTextで"Clicked!"に変更.
    			break;	// breakで抜ける.
    		case R.id.button3:	// R.id.button3の時.
    			Button b3 = (Button)v;	// vを(Button)にキャストしてb3に格納.
    			b3.setText("Clicked!");	// b3.setTextで"Clicked!"に変更.
    			break;	// breakで抜ける.		
    	}
    }
}