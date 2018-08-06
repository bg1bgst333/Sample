package com.bgstation0.android.sample.sca.vb_;

import android.content.Context;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;
import android.util.Log;

public class CustomDBHelper extends SQLiteOpenHelper {

	// メンバフィールドの定義.
	private static final String DB = "custom.db";	// DB名は"custom.db".
	private static final int DB_VERSION = 1;	// DBバージョン1.
	private static final String CREATE_TABLE = "create table custom ( _id integer primary key, name string, age string);";	// CREATE_TABLE文.
	private static final String DROP_TABLE = "drop table custom;";	// DROP_TABLE文.
		
	// コンストラクタ
	public CustomDBHelper(Context context){
		super(context, DB, null, DB_VERSION);	// 親クラスコンストラクタに任せる.
	}
	
	// DB作成時.
	public void onCreate(SQLiteDatabase db){
		// テーブル作成の実行.
		try{	// tryで囲む.
			db.execSQL(CREATE_TABLE);	// db.execSQLでCREATE_TABLEを実行.
		}
		catch(Exception ex){	// 例外キャッチ.
			Log.e("SimpleCursorAdapter_", ex.toString());	// ex.toStringをLogに出力.
		}
	}

	// DBバージョンアップグレード時.
	public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion){
		// テーブル再作成.
		db.execSQL(DROP_TABLE);	// いったんドロップ.
		onCreate(db);	// 再作成.
	}

}