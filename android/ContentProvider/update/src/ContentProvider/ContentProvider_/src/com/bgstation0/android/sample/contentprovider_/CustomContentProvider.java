package com.bgstation0.android.sample.contentprovider_;

import android.content.ContentProvider;
import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;
import android.net.Uri;
import android.util.Log;
import android.widget.Toast;

public class CustomContentProvider extends ContentProvider {
	
	// 内部スタティッククラスとしてCustomDBHelperを定義.
	private static class CustomDBHelper extends SQLiteOpenHelper{
		
		// メンバフィールドの定義.
		private static final String CREATE_TABLE = "create table custom ( _id integer primary key, name string, content string);";	// CREATE_TABLE文.
		private static final String DROP_TABLE = "drop table custom;";	// DROP_TABLE文.
		
		// コンストラクタ
		CustomDBHelper(Context context){
			super(context, "custom.db", null, 1);	// 親コンストラクタにcontext, DB名"custom.db", DBバージョン1などを渡す.
		}
		
		// DBの作成時.
		public void onCreate(SQLiteDatabase db){
			db.execSQL(CREATE_TABLE);	// db.execSQLでテーブル作成.
		}
		
		// アップグレード時.
		@Override
        public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
            db.execSQL(DROP_TABLE);	// db.execSQLでテーブル削除.
            onCreate(db);	// onCreateで再びテーブル作成.
        }
		
	}
	
	// メンバの定義.
	private CustomDBHelper customDBHelper;	// DBヘルパーのインスタンス.
	
	// 作成された時.
	@Override
	public boolean onCreate() {
		// TODO Auto-generated method stub
		// 表示.
		Log.d("CustomContentProvider", "onCreate");	// Log.dで"onCreate"を表示.
		// DBヘルパーの作成.
		customDBHelper = new CustomDBHelper(getContext());	// customDBHelperを生成.
		Log.d("CustomContentProvider", "customDBHelper.toString() = " + customDBHelper.toString());	// customDBHelper.toString()を表示.
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
		// 問い合わせ.
		SQLiteDatabase db = customDBHelper.getReadableDatabase();	// 読み込み専用データベースdbを取得.
		Cursor c = db.query("custom", projection, selection, selectionArgs, null, null, null);	// db.queryで"custom"内を問い合わせる.
		if (c != null){	// cがnullでなければ成功.
			return c;	// cを返す.
		}
		else{
			return null;	// nullを返す.
		}
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
		// 行の挿入.
		SQLiteDatabase db = customDBHelper.getWritableDatabase();	// 書き込み可能データベースdbを取得.
		long rowId = db.insert("custom", null, values);	// db.insertで挿入してrowIdを取得.
		Log.d("CustomContentProvider", "rowId = " + rowId);	// rowIdを表示.
		if (rowId > 0){	// 0より大きいなら成功.
			return uri;	// uriを返す.
		}
		else{
			return null;	// nullを返す.
		}
	}

	// 更新する時.
	@Override
	public int update(Uri uri, ContentValues values, String selection,
			String[] selectionArgs) {
		// TODO Auto-generated method stub
		// 表示.
		Log.d("CustomContentProvider", "update");	// Log.dで"update"を表示.
		// 行の更新.
		SQLiteDatabase db = customDBHelper.getWritableDatabase();	// 書き込み可能データベースdbを取得.
		int count = db.update("custom", values, selection, selectionArgs);	// db.updateで更新してcountを取得.
		return count;	// countを返す.
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