package com.bgstation0.android.sample.sqliteopenhelper_;

import android.content.Context;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;
import android.util.Log;

// クラスListItemDBHelper
public class ListItemDBHelper extends SQLiteOpenHelper{	// SQLiteOpenHelperの派生クラス.

	// メンバフィールドの定義.
	static final String DB = "list_item.db";	// DB名は"list_item.db".
	static final int DB_VERSION = 1;	// DBバージョン1.
	static final String CREATE_TABLE = "create table listitem ( _id integer primary key autoincrement, name string, age integer, address string);";	// CREATE_TABLE文.
	static final String DROP_TABLE = "drop table listitem;";	// DROP_TABLE文.
	
	// コンストラクタ
	public ListItemDBHelper(Context context){
		super(context, DB, null, DB_VERSION);	// 親クラスコンストラクタに任せる.
	}
	
	// メンバメソッドの定義.
	// DB作成時.
	public void onCreate(SQLiteDatabase db){
		// テーブル作成の実行.
		try{	// tryで囲む.
			db.execSQL(CREATE_TABLE);	// db.execSQLでCREATE_TABLEを実行.
		}
		catch(Exception ex){	// 例外キャッチ.
			Log.e("SQLiteOpenHelper_", ex.toString());	// ex.toStringをLogに出力.
		}
	}
	
	// DBバージョンアップグレード時.
	public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion){
		// テーブル再作成.
		db.execSQL(DROP_TABLE);	// いったんドロップ.
		onCreate(db);	// 再作成.
	}
}
