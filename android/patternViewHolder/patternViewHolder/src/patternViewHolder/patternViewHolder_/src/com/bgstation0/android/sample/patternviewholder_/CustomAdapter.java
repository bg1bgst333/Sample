package com.bgstation0.android.sample.patternviewholder_;

import java.util.List;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.TextView;

//カスタムアダプタ
public class CustomAdapter extends ArrayAdapter<ListItem> {

	// メンバフィールドの定義.
	private final LayoutInflater mInflater;	// インフレータmInflater.
	
	// コンストラクタ.
	public CustomAdapter(Context context, int textViewResourceId, List<ListItem> objects) {
		super(context, textViewResourceId, objects);
		// TODO Auto-generated constructor stub
		mInflater = (LayoutInflater)context.getSystemService(Context.LAYOUT_INFLATER_SERVICE);	// mInflaterを生成.
	}

	// アイテム表示のカスタマイズ
	@Override
	public View getView(int position, View convertView, ViewGroup parent) {
		
		// ViewHolderを準備.
		ViewHolder viewHolder = null;	// viewHolderをnullで初期化.
	
		// convertViewがnullの時.
		if (convertView == null){
			viewHolder = new ViewHolder();	// 生成.
			convertView = mInflater.inflate(R.layout.list_item, null);	// convertViewがnullならinflater.inflateで取得.(ここは難しいのでひとまずこういうものだと捉えておく.)
			viewHolder.tvName = (TextView)convertView.findViewById(R.id.list_item_name_textview);	// viewHolder.tvNameを取得.
			viewHolder.tvAddress = (TextView)convertView.findViewById(R.id.list_item_address_textview);	// viewHolder.tvAddressを取得.
			convertView.setTag(viewHolder);	// 
		}
		else{	// nullでない時.
			viewHolder = (ViewHolder)convertView.getTag();	// viewHolderを取得.
		}
		
		// アイテムのセット.
		ListItem item = getItem(position);	// item取得.
		viewHolder.tvName.setText(item.name);	// nameセット.
		viewHolder.tvAddress.setText(item.address);	// addressセット.
		return convertView;	// convertViewを返す.
	
	}
	
}