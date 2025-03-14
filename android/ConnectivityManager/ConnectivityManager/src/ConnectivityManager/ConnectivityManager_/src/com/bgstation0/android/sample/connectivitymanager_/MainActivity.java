package com.bgstation0.android.sample.connectivitymanager_;

import android.app.Activity;
import android.content.Context;
import android.net.ConnectivityManager;
import android.net.NetworkInfo;
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
				// ConnectivityManagerの取得.
				ConnectivityManager connectivityManager = (ConnectivityManager)mContext.getSystemService(CONNECTIVITY_SERVICE);	// connectivityManagerの取得.
				// NetworkInfoの取得.
				NetworkInfo networkInfo = connectivityManager.getActiveNetworkInfo();	// アクティブなnetworkInfoを取得.
				if (networkInfo == null){	// nullなら.
					Toast.makeText(mContext, "networkInfo == null!", Toast.LENGTH_LONG).show();	// "networkInfo == null!"とトースト表示.
				}
				else if (networkInfo.isConnected()){	// isConnectedがtrueなら.
					Toast.makeText(mContext, "Connected!", Toast.LENGTH_LONG).show();	// "Connected!"とトースト表示.
				}
				else{	// isConnectedがfalseなら.
					Toast.makeText(mContext, "Not Connected!", Toast.LENGTH_LONG).show();	// "Not Connected!"とトースト表示.
				}
			}
			
        });
        
    }
    
}