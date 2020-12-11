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

// メインアクティビティクラスMainActivity(View.OnClickListenerを実装.)
public class MainActivity extends Activity implements OnClickListener{

	// メンバフィールドの定義
	Context mContext = null;	// mContextをnullで初期化.
	
	// アクティビティ生成時
    @Override
    protected void onCreate(Bundle savedInstanceState) {
    	
    	// 既定の処理
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // mContextに自身をセット.
        mContext = this;	// mContextにthisを格納.
        
        // button1の初期化.
        Button button1 = (Button)findViewById(R.id.button1);	// button1を取得.
        button1.setOnClickListener(this);	// thisをセット.
        
    }

    // クリック時
	@Override
	public void onClick(View v) {
		
		// TODO Auto-generated method stub
		// BluetoothAdapterの取得.
		BluetoothAdapter bluetoothAdapter = BluetoothAdapter.getDefaultAdapter();	// bluetoothAdapterの取得.
		if (bluetoothAdapter != null){	// nullでない.
			
			// 対応済み
			Toast.makeText(mContext, "Bluetooth is supported!", Toast.LENGTH_LONG).show();	// "Bluetooth is supported!".
			
		}
		else{
			
			// 非対応
			Toast.makeText(mContext, "Bluetooth is not supported!", Toast.LENGTH_LONG).show();	// "Bluetooth is not supported!".
			
		}
		
	}
	
}