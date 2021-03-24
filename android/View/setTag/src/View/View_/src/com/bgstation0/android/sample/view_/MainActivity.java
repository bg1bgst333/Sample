package com.bgstation0.android.sample.view_;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.Toast;

public class MainActivity extends Activity implements OnClickListener{	// View.OnClickListenerを実装.

	// メンバフィールドの定義.
	private static final String TAG_BUTTON_1 = "tag_button_1";	// TAG_BUTTON_1を"tag_button_1"と定義.
	private static final String TAG_BUTTON_2 = "tag_button_2";	// TAG_BUTTON_2を"tag_button_2"と定義.
	
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // button1を取得し, OnClickListenerとして自身をセット.
        Button button1 = (Button)findViewById(R.id.button1);	// findViewByIdでR.id.button1を取得.
        button1.setOnClickListener(this);	// button1.setOnClickListenerでthis(自身)をセット.
        button1.setTag(TAG_BUTTON_1);	// TAG_BUTTON_1をセット.
        
        // button2を利用し, OnClickListenerとして自身をセット.
        Button button2 = (Button)findViewById(R.id.button2);	// findViewByIdでR.id.button2を取得.
        button2.setOnClickListener(this);	// button2.setOnClickListenerでthis(自身)をセット.
        button2.setTag(TAG_BUTTON_2);	// TAG_BUTTON_2をセット.
        
    }
    
    // View.OnClickListenerインタフェースのオーバーライドメソッドを実装.
    public void onClick(View v){	// onClickをオーバーライド.
    
    	// タグで振り分け.
    	String tag = (String)v.getTag();	// tagを取得.
    	if (tag != null){	// tagがnullでない時.
        	if (tag.equals(TAG_BUTTON_1)){	// TAG_BUTTON_1
        		Toast.makeText(this, "Button1", Toast.LENGTH_LONG).show();	// "Button1"をトースト表示.
    	    }
    	    else if (tag.equals(TAG_BUTTON_2)){	// TAG_BUTTON_2
    		    Toast.makeText(this, "Button2", Toast.LENGTH_LONG).show();	// "Button2"をトースト表示.
    	    }
        }
    
    }

}