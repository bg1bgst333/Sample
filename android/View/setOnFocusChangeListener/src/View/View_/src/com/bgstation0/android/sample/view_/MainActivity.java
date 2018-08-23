package com.bgstation0.android.sample.view_;

import android.app.Activity;
import android.content.Context;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.EditText;
import android.widget.Toast;

public class MainActivity extends Activity {

	// メンバフィールドの定義.
	Context mContext = null;	// mContextにnullをセット.
	
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // mContextの取得.
        mContext = this;	// mContextにthisをセット.
        
        // edittext1の取得.
        EditText edittext1 = (EditText)findViewById(R.id.edittext1);	// edittext1を取得.
        
        // フォーカスリスナーのセット.
        edittext1.setOnFocusChangeListener(new View.OnFocusChangeListener() {
			
			@Override
			public void onFocusChange(View v, boolean hasFocus) {
				// TODO Auto-generated method stub
				
				// フォーカス状態を表示.
				Toast.makeText(mContext, "hasFocus = " + String.valueOf(hasFocus), Toast.LENGTH_LONG).show();	// hasFocusを表示.
				
			}
			
		});
        
    }
    
}