package com.bgstation0.android.sample.cursorloader_;

import android.content.ContentProvider;
import android.content.ContentUris;
import android.content.ContentValues;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.net.Uri;

public class CustomContentProvider extends ContentProvider {

	// メンバフィールドの定義.
	private CustomDBHelper mHlpr = null;	// mHlprにnullをセット.
	
	@Override
	public boolean onCreate() {
		// TODO Auto-generated method stub
		mHlpr = new CustomDBHelper(getContext());	// mHlprの作成.
		return true;	// true.
	}

	@Override
	public Cursor query(Uri uri, String[] projection, String selection,
			String[] selectionArgs, String sortOrder) {
		// TODO Auto-generated method stub
		SQLiteDatabase sqlite = mHlpr.getReadableDatabase();	// sqliteを読み込み専用で取得.
		Cursor c = sqlite.query(CustomDBHelper.TABLE_NAME, null, null, null, null, null, null);	// queryで問い合わせ.
		return c;	// cを返す.
	}

	@Override
	public String getType(Uri uri) {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public Uri insert(Uri uri, ContentValues values) {
		// TODO Auto-generated method stub
		SQLiteDatabase sqlite = mHlpr.getWritableDatabase();	// 書き込み用で取得.
		long id = sqlite.insert(CustomDBHelper.TABLE_NAME, null, values);	// insertで挿入.
		Uri newUri = ContentUris.withAppendedId(CustomDBHelper.CONTENT_URI, id);	// newUri取得.
		return newUri;	// newUriを返す.
	}

	@Override
	public int delete(Uri uri, String selection, String[] selectionArgs) {
		// TODO Auto-generated method stub
		return 0;
	}

	@Override
	public int update(Uri uri, ContentValues values, String selection,
			String[] selectionArgs) {
		// TODO Auto-generated method stub
		return 0;
	}

}