package com.bgstation0.android.sample.gridview_;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.ImageView;
import android.widget.TextView;

public class GridItemAdapter extends ArrayAdapter<GridItem> {

	// インフレーターの定義.
	LayoutInflater inflater;	// インフレーターinflater.
	
	// コンストラクタ
	public GridItemAdapter(Context context, int resource, GridItem[] objects){
		super(context, resource, objects);
		inflater = (LayoutInflater)context.getSystemService(context.LAYOUT_INFLATER_SERVICE);	// インフレーターの取得.
	}
	
	// アイテム表示のカスタマイズ
	@Override
	public View getView(int position, View convertView, ViewGroup parent){
		// convertViewがnullの時.
		if (convertView == null){
			convertView = inflater.inflate(R.layout.grid_item, null);	// convertViewがnullならinflater.inflateで取得.
		}
		TextView tvname = (TextView)convertView.findViewById(R.id.grid_item_name);	// convertView.findViewByIdでR.id.grid_item_nameをtvnameに格納.
		tvname.setText(getItem(position).name);	// position番目のアイテムのnameをtvname.setTextでセット.
		ImageView ivimage = (ImageView)convertView.findViewById(R.id.grid_item_image);	// convertView.findViewByIdでR.id.grid_item_imageをivimageに格納.
		if (getItem(position).colorno == 0){	// colornoが0(赤).
			ivimage.setBackgroundResource(R.drawable.red);	// ivimage.setBackgroundResourceで背景を赤画像に.
		}
		else{
			ivimage.setBackgroundResource(R.drawable.blue);	// ivimage.setBackgroundResourceで背景を青画像に.
		}
		return convertView;	// convertViewを返す.
	}
	
}
