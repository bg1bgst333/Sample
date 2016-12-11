package com.bgstation0.android.sample.contactscontract_;

import java.util.List;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.TextView;

//ListItem用アダプターListItemAdapter
public class ListItemAdapter extends ArrayAdapter<ListItem> {	// ArrayAdapter<ListItem>を継承したListItemAdapterの定義.
	
	// インフレーターの定義.
	LayoutInflater inflater;	// インフレーターinflater.
	
	// コンストラクタ
	public ListItemAdapter(Context context, int resource, List<ListItem> objects){
		super(context, resource, objects);
		inflater = (LayoutInflater)context.getSystemService(context.LAYOUT_INFLATER_SERVICE);	// inflaterの取得.
	}
	
	// アイテム表示のカスタマイズ
	@Override
	public View getView(int position, View convertView, ViewGroup parent){
		// convertViewがnullの時.
		if (convertView == null){
			convertView = inflater.inflate(R.layout.list_item, null);	// convertViewがnullならinflater.inflateで取得.
		}
		TextView tvname = (TextView)convertView.findViewById(R.id.list_item_name);	// convertView.findViewByIdでR.id.list_item_nameをtvnameに格納.
		tvname.setText(getItem(position).name);	// position番目のアイテムのnameをtvname.setTextでセット.
		TextView tvphonenumber = (TextView)convertView.findViewById(R.id.list_item_phonenumber);	// convertView.findViewByIdでR.id.list_item_phonenumberをtvphonenumberに格納.
		tvphonenumber.setText(getItem(position).phoneNumber);	// position番目のアイテムのphoneNumberをtvphonenumber.setTextでセット.
		TextView tvemailaddress = (TextView)convertView.findViewById(R.id.list_item_emailaddress);	// convertView.findViewByIdでR.id.list_item_emailaddressをtvemailaddressに格納.
		tvemailaddress.setText(getItem(position).emailAddress);	// position番目のアイテムのemailAddressをtvemailaddress.setTextでセット.
		return convertView;	// convertViewを返す.
	}

}