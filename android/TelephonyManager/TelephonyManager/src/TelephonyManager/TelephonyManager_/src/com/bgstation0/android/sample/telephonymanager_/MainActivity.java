package com.bgstation0.android.sample.telephonymanager_;

import android.app.Activity;
import android.content.Context;
import android.os.Bundle;
import android.telephony.TelephonyManager;
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
				// TelephonyManagerを取得.
				TelephonyManager telephonyManager = (TelephonyManager)mContext.getSystemService(TELEPHONY_SERVICE);	// telephonyManagerを取得.
				// 電話番号を取得.
				String phoneNumber = telephonyManager.getLine1Number();	// telephonyManager.getLine1NumberでphoneNumberを取得.
				Toast.makeText(mContext, "phoneNumber = " + phoneNumber, Toast.LENGTH_LONG).show();	// phoneNumberを表示.
			}
			
        });
        
    }
    
}