package com.bgstation0.android.sample.contentprovider_;

import android.content.ContentProvider;
import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.net.Uri;
import android.util.Log;
import android.widget.Toast;

public class CustomContentProvider extends ContentProvider {
	
	// 作成された時.
	@Override
	public boolean onCreate() {
		// TODO Auto-generated method stub
		// 表示.
		Log.d("CustomContentProvider", "onCreate");	// Log.dで"onCreate"を表示.
		//return false;
		return true;	// trueを返す.
	}

	// 問い合わせ時.
	@Override
	public Cursor query(Uri uri, String[] projection, String selection,
			String[] selectionArgs, String sortOrder) {
		// TODO Auto-generated method stub
		// 表示.
		Log.d("CustomContentProvider", "query");	// Log.dで"query"を表示.
		return null;
	}

	// 型の取得時.
	@Override
	public String getType(Uri uri) {
		// TODO Auto-generated method stub
		// 表示.
		Log.d("CustomContentProvider", "getType");	// Log.dで"getType"を表示.
		return null;
	}

	// 挿入する時.
	@Override
	public Uri insert(Uri uri, ContentValues values) {
		// TODO Auto-generated method stub
		// 表示.
		Log.d("CustomContentProvider", "insert");	// Log.dで"insert"を表示.
		return null;
	}

	// 更新する時.
	@Override
	public int update(Uri uri, ContentValues values, String selection,
			String[] selectionArgs) {
		// TODO Auto-generated method stub
		// 表示.
		Log.d("CustomContentProvider", "update");	// Log.dで"update"を表示.
		return 1;	// 1を返す.
	}
	
	// 削除する時.
	@Override
	public int delete(Uri uri, String selection, String[] selectionArgs) {
		// TODO Auto-generated method stub
		// 表示.
		Log.d("CustomContentProvider", "delete");	// Log.dで"delete"を表示.
		//return 0;
		return -1;	// -1を返す.
	}

}