package com.bgstation0.android.sample.bluetoothadapter_;

import java.util.ArrayList;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.TextView;

// CustomAdapter
public class CustomAdapter extends ArrayAdapter<ListItem> {	// ArrayAdapter<ListItem>を継承したCustomAdapterの定義.
	
	// インフレーターの定義.
	LayoutInflater inflater;	// インフレーターinflater.

	// コンストラクタ
	public CustomAdapter(Context context, int resource, ArrayList<ListItem> objects) {
		super(context, resource, objects);
		
		// TODO Auto-generated constructor stub
		inflater = (LayoutInflater)context.getSystemService(context.LAYOUT_INFLATER_SERVICE);	// インフレーターの取得.(ここは難しいのでひとまずこういうものだと捉えておく.)
	}

	// アイテム表示のカスタマイズ
	@Override
	public View getView(int position, View convertView, ViewGroup parent) {
		// convertViewがnullの時.
		if (convertView == null){
			convertView = inflater.inflate(R.layout.list_item, null);	// convertViewがnullならinflater.inflateで取得.(ここは難しいのでひとまずこういうものだと捉えておく.)
		}
		TextView tvname = (TextView)convertView.findViewById(R.id.list_item_name);	// convertView.findViewByIdでR.id.list_item_nameをtvnameに格納.
		tvname.setText(getItem(position).name);	// position番目のアイテムのnameをtvname.setTextでセット.
		TextView tvaddress = (TextView)convertView.findViewById(R.id.list_item_address);	// convertView.findViewByIdでR.id.list_item_addressをtvaddressに格納.
		tvaddress.setText(getItem(position).address);	// position番目のアイテムのaddressをtvaddress.setTextでセット.
		return convertView;	// convertViewを返す.
	}
	
}
