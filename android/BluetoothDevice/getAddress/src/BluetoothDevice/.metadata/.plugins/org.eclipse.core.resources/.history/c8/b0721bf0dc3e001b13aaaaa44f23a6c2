package com.bgstation0.android.sample.bluetoothdevice_;

import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.widget.Toast;

public class CustomReceiver extends BroadcastReceiver {

	@Override
	public void onReceive(Context context, Intent intent) {
		// TODO Auto-generated method stub
		String action = intent.getAction();	// intent.getActionで得られたアクションをactionに格納.
		if (action == BluetoothAdapter.ACTION_DISCOVERY_STARTED){	// ACTION_DISCOVERY_STARTEDが来た時.
			Toast.makeText(context, "ACTION_DISCOVERY_STARTED", Toast.LENGTH_LONG).show();	// "ACTION_DISCOVERY_STARTED"と表示.
		}
		else if (action == BluetoothAdapter.ACTION_DISCOVERY_FINISHED){	// ACTION_DISCOVERY_FINISHEDが来た時.
			Toast.makeText(context, "ACTION_DISCOVERY_FINISHED", Toast.LENGTH_LONG).show();	// "ACTION_DISCOVERY_FINISHED"と表示.
		}
		else if (action == BluetoothDevice.ACTION_FOUND){	// ACTION_FOUNDが来た時.
			//Toast.makeText(context, "ACTION_FOUND", Toast.LENGTH_LONG).show();	// "ACTION_FOUND"と表示.
			BluetoothDevice bluetoothDevice = intent.getParcelableExtra(BluetoothDevice.EXTRA_DEVICE);	// bluetoothDeviceを取得.
			Toast.makeText(context, "name = " + bluetoothDevice.getName(), Toast.LENGTH_LONG).show();	// bluetoothDevice.getNameで取得した名前を表示.
		}
	}

}