package com.bgstation0.android.sample.listactivity_;

import java.util.ArrayList;

import android.app.Activity;
import android.app.ListActivity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.ArrayAdapter;

// ListActivtyを継承したMainActivity.
public class MainActivity extends ListActivity {

	// メンバフィールド.
	private ArrayList<ListItem> mListItems = null;	// mListItemsはnull.
	
	// 生成時.
    @Override
    protected void onCreate(Bundle savedInstanceState) {
    	
    	// 既定の処理.
        super.onCreate(savedInstanceState);
        //setContentView(R.layout.activity_main);	// コンテンツビューのセットも不要.
    	
    	// CustomAdapterの生成.
    	//ArrayAdapter<String> arrayAdapter = new ArrayAdapter<String>(this, android.R.layout.simple_list_item_1, mNames);	// アイテムのレイアウトは既定のandroid.R.layout.simple_list_item_1を使う.
        mListItems = new ArrayList<ListItem>();	// mListItemsを生成.
        ListItem item1 = new ListItem();
        item1.name = "Taro";
        item1.address = "Tokyo";
        mListItems.add(item1);
        ListItem item2 = new ListItem();
        item2.name = "Jiro";
        item2.address = "Osaka";
        mListItems.add(item2);
        ListItem item3 = new ListItem();
        item3.name = "Saburo";
        item3.address = "Nagoya";
        mListItems.add(item3);
    	CustomAdapter customAdapter = new CustomAdapter(this, R.layout.list_item, mListItems);	// customAdapterを生成.
    	
    	// アダプタのセット.
    	setListAdapter(customAdapter);	// setListAdapterでcustomAdapterをセット.
    	
    }
    
}