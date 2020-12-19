package com.bgstation0.android.sample.bluetoothsocket_;

import java.util.ArrayList;

import android.bluetooth.BluetoothDevice;
import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.TextView;

//�J�X�^���A�_�v�^
public class CustomAdapter extends ArrayAdapter<BluetoothDevice> {
	
	// �C���t���[�^�[�̒�`.
	LayoutInflater mInflater;	// �C���t���[�^�[mInflater.

	// �R���X�g���N�^
	public CustomAdapter(Context context, int resource, ArrayList<BluetoothDevice> objects) {
		
		// ����̏���.
		super(context, resource, objects);
		
		// TODO Auto-generated constructor stub
		// �C���t���[�^�擾.
		mInflater = (LayoutInflater)context.getSystemService(context.LAYOUT_INFLATER_SERVICE);	// �C���t���[�^�[�̎擾.(�����͓���̂łЂƂ܂������������̂��Ƒ����Ă���.)
		
	}
	
	// �A�C�e���\���̃J�X�^�}�C�Y
	@Override
	public View getView(int position, View convertView, ViewGroup parent) {
		
		// convertView��null�̎�.
		if (convertView == null){
			convertView = mInflater.inflate(R.layout.list_item, null);	// convertView��null�Ȃ�mInflater.inflate�Ŏ擾.(�����͓���̂łЂƂ܂������������̂��Ƒ����Ă���.)
		}
		TextView tvname = (TextView)convertView.findViewById(R.id.list_item_name);	// convertView.findViewById��R.id.list_item_name��tvname�Ɋi�[.
		tvname.setText(getItem(position).getName());	// position�Ԗڂ̃A�C�e����getName��tvname.setText�ŃZ�b�g.
		TextView tvaddress = (TextView)convertView.findViewById(R.id.list_item_address);	// convertView.findViewById��R.id.list_item_address��tvaddress�Ɋi�[.
		tvaddress.setText(getItem(position).getAddress());	// position�Ԗڂ̃A�C�e����getAddress��tvaddress.setText�ŃZ�b�g.
		return convertView;	// convertView��Ԃ�.
		
	}

}