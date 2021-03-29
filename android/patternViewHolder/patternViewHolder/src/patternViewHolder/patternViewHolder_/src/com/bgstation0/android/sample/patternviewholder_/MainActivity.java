package com.bgstation0.android.sample.patternviewholder_;

import java.util.ArrayList;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.ListView;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // ArrayListで追加する要素を定義.
        ArrayList<ListItem> listItems = new ArrayList<ListItem>();	// listItems生成.
        for (int i = 0; i < 10000; i++){	// アイテム追加.
        	ListItem item = new ListItem();	// item生成.
        	item.name = "Name" + Integer.toString(i);	// アイテムに表示する文字列をセット.
        	item.address = "Address" + Integer.toString(i);	// アイテムに表示する文字列をセット.
        	listItems.add(item);	// itemを追加.
        }
        
        // ListViewオブジェクトを取得.
        ListView listview1 = (ListView)findViewById(R.id.listview1);	// findViewByIdでlistview1を取得.
        
        // アダプタのセット.
        CustomAdapter adapter = new CustomAdapter(this, R.layout.list_item, listItems);	// adapterを生成.
        listview1.setAdapter(adapter);	// adapterをセット.
        
    }
    
}