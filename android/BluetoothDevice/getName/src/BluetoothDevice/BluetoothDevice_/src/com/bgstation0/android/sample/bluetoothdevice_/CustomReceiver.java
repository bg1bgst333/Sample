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
		String action = intent.getAction();	// intent.getAction�œ���ꂽ�A�N�V������action�Ɋi�[.
		if (action == BluetoothAdapter.ACTION_DISCOVERY_STARTED){	// ACTION_DISCOVERY_STARTED��������.
			Toast.makeText(context, "ACTION_DISCOVERY_STARTED", Toast.LENGTH_LONG).show();	// "ACTION_DISCOVERY_STARTED"�ƕ\��.
		}
		else if (action == BluetoothAdapter.ACTION_DISCOVERY_FINISHED){	// ACTION_DISCOVERY_FINISHED��������.
			Toast.makeText(context, "ACTION_DISCOVERY_FINISHED", Toast.LENGTH_LONG).show();	// "ACTION_DISCOVERY_FINISHED"�ƕ\��.
		}
		else if (action == BluetoothDevice.ACTION_FOUND){	// ACTION_FOUND��������.
			//Toast.makeText(context, "ACTION_FOUND", Toast.LENGTH_LONG).show();	// "ACTION_FOUND"�ƕ\��.
			BluetoothDevice bluetoothDevice = intent.getParcelableExtra(BluetoothDevice.EXTRA_DEVICE);	// bluetoothDevice���擾.
			Toast.makeText(context, "name = " + bluetoothDevice.getName(), Toast.LENGTH_LONG).show();	// bluetoothDevice.getName�Ŏ擾�������O��\��.
		}
	}

}