package com.bgstation0.android.sample.baseadapter_;

import java.util.ArrayList;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.TextView;

public class CustomAdapter extends BaseAdapter {

	// メンバフィールド
	ArrayList<String> mNames = null;
	ArrayList<String> mAddresses = null;
	LayoutInflater mInflater = null;
	int mCount = 0;
	
	// コンストラクタ
	CustomAdapter(Context context, String[] names, String[] addresses){
	
		// インフレータ
		mInflater = (LayoutInflater)context.getSystemService(context.LAYOUT_INFLATER_SERVICE);
		
		// 少ないほうに合わせる.
		if (names.length > addresses.length){
			mCount = addresses.length;
		}
		else{
			mCount = names.length;
		}
		mNames = new ArrayList<String>();
		mAddresses = new ArrayList<String>();
		for (int i = 0; i < mCount; i++){
			mNames.add(names[i]);
			mAddresses.add(addresses[i]);
		}
		
	}
	
	@Override
	public int getCount() {
		// TODO Auto-generated method stub
		return mNames.size();	// ここではmNamesの数を返す.
	}

	@Override
	public Object getItem(int position) {
		// TODO Auto-generated method stub
		return position;
	}

	@Override
	public long getItemId(int position) {
		// TODO Auto-generated method stub
		return position;
	}

	@Override
	public View getView(int position, View convertView, ViewGroup parent) {
		// TODO Auto-generated method stub
		if (convertView == null){
			convertView = mInflater.inflate(R.layout.list_item, null);
		}
		TextView tvName = (TextView)convertView.findViewById(R.id.list_item_name);
		tvName.setText(mNames.get(position));
		TextView tvAddress = (TextView)convertView.findViewById(R.id.list_item_address);
		tvAddress.setText(mAddresses.get(position));
		return convertView;
	}

}