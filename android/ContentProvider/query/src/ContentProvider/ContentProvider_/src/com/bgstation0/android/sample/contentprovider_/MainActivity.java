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
        
        // URIのパース.
        Uri uri = Uri.parse("content://com.bgstation0.android.sample.customcontentprovider/");	// "content://com.bgstation0.android.sample.customcontentprovider/"をパースして, uriにする.
        
        // insertを呼び出す.
        ContentValues values = new ContentValues();	// valuesの作成.
        values.put("name", "test1");	// キーは"name", 値は"test1".
        values.put("content", "ABCDE");	// キーは"content", 値は"ABCDE".
        Uri res1 = mContentResolver.insert(uri, values);	// mContentResolver.insertでvaluesを挿入.
        if (res1 != null){	// res1がnullでない時.
        	Toast.makeText(this, "insert success! res1.toString() = " + res1.toString(), Toast.LENGTH_LONG).show();	// 成功なら, res1を文字列として表示.
        }
        else{
        	Toast.makeText(this, "insert failure! res1 == null", Toast.LENGTH_LONG).show();	// "res1 == null"を表示.
        }
        
        // queryを呼び出す.
        String[] projection = {	// 取り出すカラム名リスト.
        		"name",
        		"content"
        };
        Cursor cursor = mContentResolver.query(uri, projection, null, null, null);	// mContentResolver.queryで問い合わせて, cursorを取得.
        if (cursor != null){	// nullでなければ成功.
        	while (cursor.moveToNext()){	// cursor.moveToNext()がfalseになるまで繰り返す.
        		String name = cursor.getString(cursor.getColumnIndex("name"));	// nameを取得.
        		String content = cursor.getString(cursor.getColumnIndex("content"));	// contentを取得.
        		Toast.makeText(this, "query success! name = " + name + ", content = " + content, Toast.LENGTH_LONG).show();	// nameとcontentを表示.
        	}
        	cursor.close();	// cursor.closeで閉じる.
        }
        else{
        	Toast.makeText(this, "query failure!", Toast.LENGTH_LONG).show();	// "query failure!"と表示.
        }
        
    }
    
}