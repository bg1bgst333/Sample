package com.bgstation0.android.sample.bluetoothsocket_;

import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;

//�J�X�^�����V�[�o
public class CustomReceiver extends BroadcastReceiver {

    // �����o�t�B�[���h.
    MainActivity mMainActivity = null;	// null�ŏ�����.
    
    // �R���X�g���N�^.
    public CustomReceiver(MainActivity mainActivity){

        // ������.
        mMainActivity = mainActivity;	// mMainActivity��mainActivity���Z�b�g.
		
    }
    
    
    // ��M��.
    @Override
    public void onReceive(Context context, Intent intent) {
			
        // TODO Auto-generated method stub
        // action���Ƃ̏���.
        String action = intent.getAction();	// intent.getAction�œ���ꂽ�A�N�V������action�Ɋi�[.
        if (action == BluetoothAdapter.ACTION_DISCOVERY_STARTED){	// ACTION_DISCOVERY_STARTED��������.
     	
            // ���X�g�̃N���A.
            mMainActivity.mCustomAdapter.clear();

        }
        else if (action == BluetoothDevice.ACTION_FOUND){	// ACTION_FOUND��������.
				
            // Bluetooth�f�o�C�X�̒ǉ�.
            BluetoothDevice bluetoothDevice = intent.getParcelableExtra(BluetoothDevice.EXTRA_DEVICE);	// bluetoothDevice���擾.
            mMainActivity.mCustomAdapter.add(bluetoothDevice);	// bluetoothDevice��ǉ�.

        }

    }

}