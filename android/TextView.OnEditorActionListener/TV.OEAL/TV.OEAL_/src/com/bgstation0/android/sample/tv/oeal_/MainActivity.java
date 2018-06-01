package com.bgstation0.android.sample.tv.oeal_;

import android.app.Activity;
import android.os.Bundle;
import android.view.KeyEvent;
import android.view.Menu;
import android.view.MenuItem;
import android.view.inputmethod.EditorInfo;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.TextView.OnEditorActionListener;
import android.widget.Toast;

public class MainActivity extends Activity implements OnEditorActionListener{

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // EditTextのキー入力アクションカスタマイズ.
        EditText edittext1 = (EditText)findViewById(R.id.edittext1);	// edittext1を取得.
        edittext1.setOnEditorActionListener(this);	// thisを渡す.
    
    }
    
    @Override
	public boolean onEditorAction(TextView v, int actionId, KeyEvent event) {

		// Enterキー(Go)が押された時.
		if (actionId == EditorInfo.IME_ACTION_GO){	// IME_ACTION_GOの時.
			
			// 入力されたテキストを表示.
			Toast.makeText(this, v.getText().toString(), Toast.LENGTH_LONG).show();	// v.getText().toString()で取得したテキストを表示.
			return true;	// trueを返す.
		
		}
		
		// false.
		return false;	// falseを返す.
		
	}
    
}