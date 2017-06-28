package com.bgstation0.android.sample.webview_;

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
		TextView tvurl = (TextView)convertView.findViewById(R.id.list_item_url);	// convertView.findViewByIdでR.id.list_item_urlをtvurlに格納.
		tvurl.setText(getItem(position).url);	// position番目のアイテムのurlをtvurl.setTextでセット.
		return convertView;	// convertViewを返す.
	}
	
}