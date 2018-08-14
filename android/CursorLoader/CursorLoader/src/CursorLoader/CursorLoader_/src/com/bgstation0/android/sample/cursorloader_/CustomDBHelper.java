package com.bgstation0.android.sample.cursorloader_;

import android.content.Context;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

import android.net.Uri;
import android.util.Log;

public class CustomDBHelper extends SQLiteOpenHelper {

	// メンバフィールドの定義.
	public static final String AUTHORITY = "com.bgstation0.android.sample.cursorloader_.customcontentprovider";	// AUTHORITYの定義.
	public static final Uri CONTENT_URI = Uri.parse("content://" + AUTHORITY);	// CONTENT_URIの定義.
	public static final String DB_NAME = "custom.db";	// DATABASE_NAMEの定義.
	public static final int DB_VERSION = 1;	// DB_VERSIONの定義.
	public static final String TABLE_NAME = "custom_table";	// TABLE_NAMEの定義.
	public static final String CREATE_TABLE = "create table " + TABLE_NAME + " ( _id integer primary key, text1 string, text2 string);";	// CREATE_TABLE文の定義.
	public static final String DROP_TABLE = "drop table " + TABLE_NAME + ";";	// DROP_TABLE文の定義.
	
	// コンストラクタ
	public CustomDBHelper(Context context){
		super(context, DB_NAME, null, DB_VERSION);	// 親コンストラクタに渡す.
	}
	
	// メンバメソッドの定義.
	// DB作成時.
	public void onCreate(SQLiteDatabase db){
		// テーブル作成の実行.
		try{	// tryで囲む.
			db.execSQL(CREATE_TABLE);	// db.execSQLでCREATE_TABLEを実行.
		}
		catch(Exception ex){	// 例外キャッチ.
			Log.e("CustomLoader_", ex.toString());	// ex.toStringをLogに出力.
		}
	}
	
	// DBバージョンアップグレード時.
	public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion){
		// テーブル再作成.
		db.execSQL(DROP_TABLE);	// いったんドロップ.
		onCreate(db);	// 再作成.
	}
	
}