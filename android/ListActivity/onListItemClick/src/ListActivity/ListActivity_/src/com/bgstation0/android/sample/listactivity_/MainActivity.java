package com.bgstation0.android.sample.listactivity_;

import android.app.Activity;
import android.app.ListActivity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.Toast;

// ListActivtyを継承したMainActivity.
public class MainActivity extends ListActivity {

	// メンバフィールド.
	private String[] mNames = {"Taro", "Jiro", "Saburo", "Shiro", "Goro"};	// mNamesの初期化.
	
	// 生成時.
    @Override
    protected void onCreate(Bundle savedInstanceState) {
    	
    	// 既定の処理.
        super.onCreate(savedInstanceState);
        //setContentView(R.layout.activity_main);	// コンテンツビューのセットも不要.
    	
    	// ArrayAdapterの生成.
    	ArrayAdapter<String> arrayAdapter = new ArrayAdapter<String>(this, android.R.layout.simple_list_item_1, mNames);	// アイテムのレイアウトは既定のandroid.R.layout.simple_list_item_1を使う.
    	
    	// アダプタのセット.
    	setListAdapter(arrayAdapter);	// setListAdapterでarrayAdapterをセット.
    	
    }
    
    // リストのアイテムがクリックされた時.
    @Override
    protected void onListItemClick(ListView l, View v, int position, long id){
    	
    	// 既定の処理.
    	super.onListItemClick(l, v, position, id);	// 親クラスのonListItemClickを呼ぶ.
    	
    	// 選択されたアイテム(文字列)を表示.
    	Toast.makeText(this, (String)l.getItemAtPosition(position), Toast.LENGTH_LONG).show();	// l.getItemAtPosition(position)で選択されたアイテムを取得し, Toast表示.
    	
    }
    
}