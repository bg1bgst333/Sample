package com.bgstation0.android.sample.account_;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.TextView;

//ListItem用アダプターListItemAdapter
public class ListItemAdapter extends ArrayAdapter<ListItem> {

	// メンバフィールドの定義.
	LayoutInflater mInflater = null;	// mInflaterをnullで初期化.
	
	// コンストラクタ
	public ListItemAdapter(Context context, int resource, ListItem[] objects){
		super(context, resource, objects);	// 親コンストラクタ.
		mInflater = (LayoutInflater)context.getSystemService(context.LAYOUT_INFLATER_SERVICE);	// mInflaterの取得.
	}
	
	// アイテム表示のカスタマイズ.
	@Override
	public View getView(int position, View convertView, ViewGroup parent){
		// convertViewがnullの時.
		if (convertView == null){
			convertView = mInflater.inflate(R.layout.list_item, null);	// nullなら生成.
		}
		TextView tvName = (TextView)convertView.findViewById(R.id.list_item_name);	// tvNameを取得.
		tvName.setText(getItem(position).name);	// nameをセット.
		TextView tvType = (TextView)convertView.findViewById(R.id.list_item_type);	// tvTypeを取得.
		tvType.setText(getItem(position).type);	// typeをセット.
		return convertView;	// convertViewを返す.
	}
	
}