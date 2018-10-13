package com.bgstation0.android.sample.bluetoothadapter_;

import android.app.Activity;
import android.bluetooth.BluetoothAdapter;
import android.content.Context;
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
				// BluetoothAdapterの取得.
				BluetoothAdapter bluetoothAdapter = BluetoothAdapter.getDefaultAdapter();	// bluetoothAdapterの取得.
				if (bluetoothAdapter != null){	// nullでない.
					if (bluetoothAdapter.isEnabled()){	// 使用可能.
						Toast.makeText(mContext, "Bluetooth Enabled!", Toast.LENGTH_LONG).show();	// "Bluetooth Enabled!".
					}
					else{	// 使用不可.
						Toast.makeText(mContext, "Bluetooth Disabled!", Toast.LENGTH_LONG).show();	// "Bluetooth Disabled!".
					}
				}
				else{	// nullならサポートされていない.
					Toast.makeText(mContext, "Bluetooth Not Support!", Toast.LENGTH_LONG).show();	// "Bluetooth Not Support!".
				}
			}
			
        });
        
    }
    
}