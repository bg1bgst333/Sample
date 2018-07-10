package com.bgstation0.android.sample.textwatcher_;

import android.app.Activity;
import android.content.Context;
import android.os.Bundle;
import android.text.Editable;
import android.text.TextWatcher;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends Activity implements TextWatcher{

	// メンバフィールドの定義.
	Context mContext = null;	// mContextをnullで初期化.
		
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // mContextにthisをセット.
        mContext = this;
        
        // EditTextの入力文字列に対するアクション.
        final EditText edittext1 = (EditText)findViewById(R.id.edittext1);	// edittext1を取得.
        edittext1.addTextChangedListener(this);	// thisをセット.
        
    }
    
 // 変化する前.
	@Override
	public void beforeTextChanged(CharSequence s, int start, int count, int after) {
		
		// Toast表示.
		Toast.makeText(mContext, "before: " + s, Toast.LENGTH_LONG).show();	// sを表示.
		
	}
	
	// 変化した時.
	@Override
	public void onTextChanged(CharSequence s, int start, int before, int count) {
		
		// Toast表示.
		MainActivity mainActivity = (MainActivity)mContext;	// mainActivtyを取得.
		final TextView textview1 = (TextView)mainActivity.findViewById(R.id.textview1);	// textview1を取得.
		textview1.setText(s);	// sをセット.
		
	}
	
	// 変化した後.
	@Override
	public void afterTextChanged(Editable s) {
		
		// Toast表示.
		Toast.makeText(mContext, "after: " + s, Toast.LENGTH_LONG).show();	// sを表示.
		
	}
    
}
