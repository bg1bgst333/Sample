package com.bgstation0.android.sample.listfragment_;

import android.app.ListFragment;
import android.os.Bundle;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.Toast;

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
	
    // リストのアイテムがクリックされた時.
    @Override
    public void onListItemClick(ListView l, View v, int position, long id){
    	
    	// 既定の処理.
    	super.onListItemClick(l, v, position, id);	// 親クラスのonListItemClickを呼ぶ.
    	
    	// 選択されたアイテム(文字列)を表示.
    	Toast.makeText(getActivity(), (String)l.getItemAtPosition(position), Toast.LENGTH_LONG).show();	// l.getItemAtPosition(position)で選択されたアイテムを取得し, Toast表示.
    	
    }
    
}