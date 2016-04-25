package com.bgstation0.android.sample.arrayadapter_;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.TextView;

// ListItem用アダプターListItemAdapter
public class ListItemAdapter extends ArrayAdapter<ListItem> {	// ArrayAdapter<ListItem>を継承したListItemAdapterの定義.
	
	// インフレーターの定義.
	LayoutInflater inflater;	// インフレーターinflater.

	// コンストラクタ
	public ListItemAdapter(Context context, int resource, ListItem[] objects) {
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
		TextView tvage = (TextView)convertView.findViewById(R.id.list_item_age);	// convertView.findViewByIdでR.id.list_item_ageをtvageに格納.
		tvage.setText(Integer.toString(getItem(position).age));	// position番目のアイテムのageをtvage.setTextでセット.(Integer.toStringで文字列変換.)
		TextView tvaddress = (TextView)convertView.findViewById(R.id.list_item_address);	// convertView.findViewByIdでR.id.list_item_addressをtvaddressに格納.
		tvaddress.setText(getItem(position).address);	// position番目のアイテムのaddressをtvaddress.setTextでセット.
		return convertView;	// convertViewを返す.
	}
	
}
