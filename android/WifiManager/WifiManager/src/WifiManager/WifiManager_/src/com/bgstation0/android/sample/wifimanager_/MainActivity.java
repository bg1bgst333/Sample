package com.bgstation0.android.sample.wifimanager_;

import android.app.Activity;
import android.content.Context;
import android.net.wifi.WifiInfo;
import android.net.wifi.WifiManager;
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
				// WifiManagerの取得.
				WifiManager wifiManager = (WifiManager)mContext.getSystemService(WIFI_SERVICE);	// wifiManagerを取得.
				// WifiInfoの取得.
				WifiInfo wifiInfo = wifiManager.getConnectionInfo();	// wifiInfoを取得.
				// ssid取得.
				String ssid = wifiInfo.getSSID();	// ssidを取得.
				Toast.makeText(mContext, "ssid = " + ssid, Toast.LENGTH_LONG).show();	// ssidを表示.
			}
			
        });
        
    }
    
}