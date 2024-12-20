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
        
        // updateを呼び出す.
        ContentValues values2 = new ContentValues();	// values2の作成.
        values2.put("name", "test2");	// キーは"name", 値は"test2".
        values2.put("content", "VWXYZ");	// キーは"content", 値は"VWXYZ".
        int count = mContentResolver.update(uri, values2, "name = ?", new String[]{"test1"});	// mContentResolver.updateで"name = test1"なら更新.
        if (count > 0){	// 0より大きいなら成功.
        	Toast.makeText(this, "update success!", Toast.LENGTH_LONG).show();	// "update success!"と表示.
        }
        else{
        	Toast.makeText(this, "update failure!", Toast.LENGTH_LONG).show();	// "update failure!"と表示.
        }
        
        // 再びqueryを呼び出す.
        Cursor cursor2 = mContentResolver.query(uri, projection, null, null, null);	// mContentResolver.queryで問い合わせて, cursor2を取得.
        if (cursor2 != null){	// nullでなければ成功.
        	while (cursor2.moveToNext()){	// cursor2.moveToNext()がfalseになるまで繰り返す.
        		String name = cursor2.getString(cursor2.getColumnIndex("name"));	// nameを取得.
        		String content = cursor2.getString(cursor2.getColumnIndex("content"));	// contentを取得.
        		Toast.makeText(this, "query success! name = " + name + ", content = " + content, Toast.LENGTH_LONG).show();	// nameとcontentを表示.
        	}
        	cursor2.close();	// cursor2.closeで閉じる.
        }
        else{
        	Toast.makeText(this, "query failure!", Toast.LENGTH_LONG).show();	// "query failure!"と表示.
        }
        
        // deleteを呼び出す.
        int count2 = mContentResolver.delete(uri, "name = ?", new String[]{"test2"});	// mContentResolver.deleteで"name = test2"なら削除.
        if (count2 > 0){	// 0より大きいなら成功.
        	Toast.makeText(this, "delete success!", Toast.LENGTH_LONG).show();	// "delete success!"と表示.
        }
        else{
        	Toast.makeText(this, "delete failure!", Toast.LENGTH_LONG).show();	// "delete failure!"と表示.
        }
        
        // 再びqueryを呼び出す.
        Cursor cursor3 = mContentResolver.query(uri, projection, null, null, null);	// mContentResolver.queryで問い合わせて, cursor3を取得.
        if (cursor3 != null){	// nullでなければ成功.
        	if (cursor3.getCount() == 0){	// cursor3.getCount()が0なら.
        		Toast.makeText(this, "cursor3.getCount() == 0", Toast.LENGTH_LONG).show();	// "cursor3.getCount() == 0"と表示.
        	}
        	else{
	        	while (cursor3.moveToNext()){	// cursor3.moveToNext()がfalseになるまで繰り返す.
	        		String name = cursor3.getString(cursor3.getColumnIndex("name"));	// nameを取得.
	        		String content = cursor3.getString(cursor3.getColumnIndex("content"));	// contentを取得.
	        		Toast.makeText(this, "query success! name = " + name + ", content = " + content, Toast.LENGTH_LONG).show();	// nameとcontentを表示.
	        	}
        	}
        	cursor3.close();	// cursor3.closeで閉じる.
        }
        else{
        	Toast.makeText(this, "query failure!", Toast.LENGTH_LONG).show();	// "query failure!"と表示.
        }
        
    }
    
}