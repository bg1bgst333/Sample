package com.bgstation0.android.sample.av.oicl_;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.Toast;

public class MainActivity extends Activity implements AdapterView.OnItemClickListener {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // String配列で追加する要素を定義.
        String[] items = new String[3];	// String配列items(要素数3)
        items[0] = "item1";	// item1
        items[1] = "item2";	// item2
        items[2] = "item3";	// item3
        
        // ListViewオブジェクトを取得.
        ListView listview1 = (ListView)findViewById(R.id.listview1);	// findViewByIdでlistview1を取得.
        
        // ArrayAdapter<String>のadapterを生成して, listview1とadapterとitemsを紐付ける.
        ArrayAdapter<String> adapter = new ArrayAdapter<String>(this, R.layout.list_item, items);	// ArrayAdapter<String>コンストラクタにListViewのアイテムテンプレートのlist_itemとリストデータのitemsをセット.(list_itemは単体のTextViewじゃないといけないことに注意.)
        listview1.setAdapter(adapter);	// listview1.setAdapterにadapterをセットして, ListViewとAdapterを紐付ける.
        listview1.setOnItemClickListener(this);	// listview1.setOnItemClickListenerにthisをセット.
    }

    // アイテムがクリックされた時.
	@Override
	public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
		// TODO Auto-generated method stub
		// 選択された位置positionを表示.
		Toast.makeText(this, "position = " + position, Toast.LENGTH_LONG).show();	// positionをToast表示.
	}
	
}