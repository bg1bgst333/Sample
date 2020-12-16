package com.bgstation0.android.sample.bluetoothadapter_;

import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.widget.Toast;

public class CustomReceiver extends BroadcastReceiver {

	// メンバフィールド.
	MainActivity mMainActivity = null;	// nullで初期化.
	
	// コンストラクタ.
	public CustomReceiver(MainActivity mainActivity){
		
		// 初期化.
		mMainActivity = mainActivity;	// mMainActivityにmainActivityをセット.
		
	}
	
	// 受信時.
	@Override
	public void onReceive(Context context, Intent intent) {
		// TODO Auto-generated method stub
		String action = intent.getAction();	// intent.getActionで得られたアクションをactionに格納.
		if (action == BluetoothAdapter.ACTION_DISCOVERY_STARTED){	// ACTION_DISCOVERY_STARTEDが来た時.
			//Toast.makeText(context, "ACTION_DISCOVERY_STARTED", Toast.LENGTH_LONG).show();	// "ACTION_DISCOVERY_STARTED"と表示.
			// リストのクリア.
			mMainActivity.mCustomAdapter.clear();
		}
		else if (action == BluetoothAdapter.ACTION_DISCOVERY_FINISHED){	// ACTION_DISCOVERY_FINISHEDが来た時.
			//Toast.makeText(context, "ACTION_DISCOVERY_FINISHED", Toast.LENGTH_LONG).show();	// "ACTION_DISCOVERY_FINISHED"と表示.
			// アダプタのセット.
			mMainActivity.mListView1.setAdapter(mMainActivity.mCustomAdapter);
		}
		else if (action == BluetoothDevice.ACTION_FOUND){	// ACTION_FOUNDが来た時.
			//Toast.makeText(context, "ACTION_FOUND", Toast.LENGTH_LONG).show();	// "ACTION_FOUND"と表示.
			BluetoothDevice bluetoothDevice = intent.getParcelableExtra(BluetoothDevice.EXTRA_DEVICE);	// bluetoothDeviceを取得.
			//Toast.makeText(context, "name = " + bluetoothDevice.getName(), Toast.LENGTH_LONG).show();	// bluetoothDevice.getNameで取得した名前を表示.
			//Toast.makeText(context, "address = " + bluetoothDevice.getAddress(), Toast.LENGTH_LONG).show();	// bluetoothDevice.getAddressで取得したアドレスを表示.
			// アイテムの追加.
			ListItem item = new ListItem();
			item.name = bluetoothDevice.getName();
			item.address = bluetoothDevice.getAddress();
			mMainActivity.mCustomAdapter.add(item);
		}
	}

}