package com.bgstation0.android.sample.textview_;

import android.app.Activity;
import android.content.Context;
import android.os.Bundle;
import android.view.KeyEvent;
import android.view.Menu;
import android.view.MenuItem;
import android.view.inputmethod.EditorInfo;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends Activity {

	// メンバフィールドの定義.
	Context mContext = null;	// mContextをnullで初期化.
	
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // mContextにthisをセット.
        mContext = this;
        
        // EditTextのキー入力アクションカスタマイズ.
        final EditText edittext1 = (EditText)findViewById(R.id.edittext1);	// edittext1を取得.
        edittext1.setOnEditorActionListener(new TextView.OnEditorActionListener() {
			
			@Override
			public boolean onEditorAction(TextView v, int actionId, KeyEvent event) {
				// TODO Auto-generated method stub
				
				// Enterキー(Done)が押された時.
				if (actionId == EditorInfo.IME_ACTION_DONE){	// IME_ACTION_DONEの時.
					
					// 入力されたテキストを表示.
					Toast.makeText(mContext, edittext1.getText().toString(), Toast.LENGTH_LONG).show();	// edittext1.getText().toString()で取得したテキストを表示.
					return true;	// trueを返す.
				
				}
				
				// false.
				return false;	// falseを返す.
				
			}
			
		});
        
    }
    
}