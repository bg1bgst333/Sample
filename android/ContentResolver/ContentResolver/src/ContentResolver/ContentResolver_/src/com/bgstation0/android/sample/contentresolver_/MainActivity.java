package com.bgstation0.android.sample.contentresolver_;

import java.util.ArrayList;
import java.util.List;

import android.app.Activity;
import android.content.ContentResolver;
import android.database.Cursor;
import android.os.Bundle;
import android.provider.ContactsContract;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.ListView;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // ContentResolverで連絡先を取得し, ListViewに追加して表示.
        ContentResolver contentResolver = getContentResolver();	// getContentResolverでcontentResolverを取得.
        List<ListItem> listitems = new ArrayList<ListItem>();	// listitemsを生成.
        Cursor c = contentResolver.query(ContactsContract.Contacts.CONTENT_URI, null, null, null, null);	// contentResolver.queryで連絡先にアクセス.
        if (c.moveToFirst()){	// 最初なら.
        	for (int i = 0; i < c.getCount(); i++){	// c.getCountの数, 繰り返す.
        		String name = c.getString(c.getColumnIndex(ContactsContract.Contacts.DISPLAY_NAME));	// 表示名を取得.
        		ListItem item = new ListItem();	// itemを生成.
        		item.name = name;	// item.nameにnameを代入.
        		listitems.add(item);	// listitems.addでitemを追加.
        		c.moveToNext();	// 次へ.
        	}
        }
        c.close();	// 閉じる.
        ListView listview1 = (ListView)findViewById(R.id.listview1);	// findViewByIdでlistview1を取得.
        ListItemAdapter adapter = new ListItemAdapter(this, R.layout.list_item, listitems);	// ListItemAdapterコンストラクタにListViewのアイテムテンプレートのlist_itemとリストデータのlistitemsをセット.
        listview1.setAdapter(adapter);	// listview1.setAdapterにadapterをセットして, ListViewとAdapterを紐付ける.      
    }
}
