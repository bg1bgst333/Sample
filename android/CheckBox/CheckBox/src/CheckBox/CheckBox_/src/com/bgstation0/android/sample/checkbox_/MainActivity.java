package com.bgstation0.android.sample.checkbox_;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.Toast;

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
    	// checkbox1を取得し, チェック状態を確認する.
    	CheckBox checkbox1 = (CheckBox)findViewById(R.id.checkbox1);	// findViewByIdでR.id.checkbox1を取得.
    	if (checkbox1.isChecked()){	// checkbox1.isCheckedでチェックされている場合.
    		Toast.makeText(this, "Checked!", Toast.LENGTH_SHORT).show();	// Toastで"Checked!"と表示.
    	}
    	else{	// チェックされていない場合.
    		Toast.makeText(this,  "Not checked!", Toast.LENGTH_SHORT).show();	// Toastで"Not checked!"と表示.
    	}
    }
}
