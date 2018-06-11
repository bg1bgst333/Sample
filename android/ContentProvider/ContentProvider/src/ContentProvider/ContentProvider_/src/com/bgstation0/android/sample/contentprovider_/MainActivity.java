package com.bgstation0.android.sample.contentprovider_;

import android.app.Activity;
import android.content.ContentResolver;
import android.content.ContentValues;
import android.database.Cursor;
import android.net.Uri;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.Toast;

public class MainActivity extends Activity {

	// メンバフィールドの定義.
	ContentResolver mContentResolver = null;	// mContentResolverをnullで初期化.
	
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // ContentResolverの取得.
        mContentResolver = getContentResolver();	// mContentResolverを取得.
        
        // queryを呼び出す.
        Uri uri = Uri.parse("content://com.bgstation0.android.sample.customcontentprovider/");	// "content://com.bgstation0.android.sample.customcontentprovider/"をパースして, uriにする.
        Cursor cursor1 = mContentResolver.query(uri, null, null, null, null);	// mContentResolver.queryでcursor1を取得.
        if (cursor1 == null){	// nullなら.
        	Toast.makeText(this, "cursor1 == null", Toast.LENGTH_LONG).show();	// "cursor1 == null"を表示.
        }
        
        // insertを呼び出す.
        ContentValues values = new ContentValues();	// valuesの作成.
        values.put("key", "value");	// キーは"key", 値は"value".
        Uri res1 = mContentResolver.insert(uri, values);	// mContentResolver.insertでvaluesを挿入.
        if (res1 == null){	// nullなら.
        	Toast.makeText(this, "res1 == null", Toast.LENGTH_LONG).show();	// "res1 == null"を表示.
        }
        
        // updateを呼び出す.
        ContentValues values2 = new ContentValues();	// valuesの作成.
        values.put("key", "newvalue");	// キーは"key", 値は"newvalue".
        int ret1 = mContentResolver.update(uri, values2, "", null);	// mContentResolver.updateでvaluesに更新.
        if (ret1 == 1){	// 1なら.
        	Toast.makeText(this, "ret1 == 1", Toast.LENGTH_LONG).show();	// "ret1 == 1"を表示.
        }
        
        // deleteを呼び出す.
        int count1 = mContentResolver.delete(uri, "", null);	// mContentResolver.deleteで削除.
        if (count1 == -1){	// -1なら.
        	Toast.makeText(this, "count1 == -1", Toast.LENGTH_LONG).show();	// "count1 == -1"を表示.
        }
        
    }
    
}