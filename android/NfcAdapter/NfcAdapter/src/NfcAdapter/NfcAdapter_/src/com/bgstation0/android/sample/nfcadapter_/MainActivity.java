package com.bgstation0.android.sample.nfcadapter_;

import android.app.Activity;
import android.content.Context;
import android.nfc.NfcAdapter;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.Toast;

public class MainActivity extends Activity {

	// メンバフィールドの定義.
	Context mContext = null;	// mContextをnullで初期化.
		
	@Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // mContextの初期化.
        mContext = this;	// mContextにthisをセット.
        
        // button1の初期化.
        Button button1 = (Button)findViewById(R.id.button1);	// button1を取得.
        button1.setOnClickListener(new OnClickListener(){

			@Override
			public void onClick(View v) {
				// TODO Auto-generated method stub
				// NfcAdapterの取得.
				NfcAdapter nfcAdapter = NfcAdapter.getDefaultAdapter();	// nfcAdapterの取得.
				if (nfcAdapter != null){	// nullではない.
					if (nfcAdapter.isEnabled()){	// 使用可能.
						Toast.makeText(mContext, "Nfc Enabled!", Toast.LENGTH_LONG).show();	// "Nfc Enabled!".
					}
					else{	// 使用不可.
						Toast.makeText(mContext, "Nfc Disabled!", Toast.LENGTH_LONG).show();	// "Nfc Disabled!".
					}
				}
				else{	// nullならサポートされていない.
					Toast.makeText(mContext, "Nfc Not Support!", Toast.LENGTH_LONG).show();	// "Nfc Not Support!".
				}
			}
			
        });
        
    }
    
}