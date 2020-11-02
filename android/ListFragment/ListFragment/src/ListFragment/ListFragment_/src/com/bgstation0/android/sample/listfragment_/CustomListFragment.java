package com.bgstation0.android.sample.listfragment_;

import android.app.ListFragment;
import android.os.Bundle;
import android.widget.ArrayAdapter;

// ListFragmentを継承したCustomListFragment.
public class CustomListFragment extends ListFragment {

	// メンバフィールド.
	private String[] mNames = {"Taro", "Jiro", "Saburo", "Shiro", "Goro"};	// mNamesの初期化.
	
	// アクティビティ生成時.
	@Override
	public void onActivityCreated(Bundle savedInstanceState){
		
		// 既定の処理.
		super.onActivityCreated(savedInstanceState);
		
		// ArrayAdapterの生成.
    	ArrayAdapter<String> arrayAdapter = new ArrayAdapter<String>(getActivity(), android.R.layout.simple_list_item_1, mNames);	// アイテムのレイアウトは既定のandroid.R.layout.simple_list_item_1を使う.
    	
    	// アダプタのセット.
    	setListAdapter(arrayAdapter);	// setListAdapterでarrayAdapterをセット.
		
	}
	
}