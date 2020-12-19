package com.bgstation0.android.sample.bluetoothsocket_;

import java.util.ArrayList;

import android.bluetooth.BluetoothDevice;
import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.TextView;

//カスタムアダプタ
public class CustomAdapter extends ArrayAdapter<BluetoothDevice> {
	
	// インフレーターの定義.
	LayoutInflater mInflater;	// インフレーターmInflater.

	// コンストラクタ
	public CustomAdapter(Context context, int resource, ArrayList<BluetoothDevice> objects) {
		
		// 既定の処理.
		super(context, resource, objects);
		
		// TODO Auto-generated constructor stub
		// インフレータ取得.
		mInflater = (LayoutInflater)context.getSystemService(context.LAYOUT_INFLATER_SERVICE);	// インフレーターの取得.(ここは難しいのでひとまずこういうものだと捉えておく.)
		
	}
	
	// アイテム表示のカスタマイズ
	@Override
	public View getView(int position, View convertView, ViewGroup parent) {
		
		// convertViewがnullの時.
		if (convertView == null){
			convertView = mInflater.inflate(R.layout.list_item, null);	// convertViewがnullならmInflater.inflateで取得.(ここは難しいのでひとまずこういうものだと捉えておく.)
		}
		TextView tvname = (TextView)convertView.findViewById(R.id.list_item_name);	// convertView.findViewByIdでR.id.list_item_nameをtvnameに格納.
		tvname.setText(getItem(position).getName());	// position番目のアイテムのgetNameをtvname.setTextでセット.
		TextView tvaddress = (TextView)convertView.findViewById(R.id.list_item_address);	// convertView.findViewByIdでR.id.list_item_addressをtvaddressに格納.
		tvaddress.setText(getItem(position).getAddress());	// position番目のアイテムのgetAddressをtvaddress.setTextでセット.
		return convertView;	// convertViewを返す.
		
	}

}