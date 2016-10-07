package com.bgstation0.android.sample.downloadmanager_;

import android.app.Activity;
import android.app.DownloadManager;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.database.Cursor;
import android.widget.Toast;


public class DownloadReceiver extends BroadcastReceiver {

	// メンバフィールドの定義
	private MainActivity mainActivity = null;	// MainActivity型mainActivityをnullにセット.
	
	// コンストラクタ
	public DownloadReceiver(MainActivity mainActivity){
		this.mainActivity = mainActivity;	// mainActivityをthis.mainActivityに格納.
	}
	
	// ブロードキャストインテントを受け取った時.
	@Override
	public void onReceive(Context context, Intent intent) {
		// TODO Auto-generated method stub
		// アクションを取得し, アクション文字列ごとに処理を分ける.
		String action = intent.getAction();	// intent.getActionでactionを取得.
		if (action.equals(DownloadManager.ACTION_DOWNLOAD_COMPLETE)){	// actionがダウンロード完了なら.
			long id = intent.getLongExtra(DownloadManager.EXTRA_DOWNLOAD_ID, -1);	// intentからダウンロードIDを取得.
			DownloadManager.Query query = new DownloadManager.Query();	// DownloadManager.Queryオブジェクトquery作成.
			query.setFilterById(id);	// query.setFilterByIdでダウンロードIDをセットし, このIDでフィルタリング.
			Cursor c = this.mainActivity.downloadManager.query(query);	// this.mainActivity.downloadManager.queryにqueryをセットして, Cursor型cを取得.
			if (c.moveToFirst()){	// カーソルの最初に移動.
				int status = c.getInt(c.getColumnIndex(DownloadManager.COLUMN_STATUS));	// ステータスを取得.
				// ステータスが成功ならトースト表示.
				if (status == DownloadManager.STATUS_SUCCESSFUL){	// 成功なら.
					Toast.makeText(this.mainActivity, "STATUS_SUCCESSFUL", Toast.LENGTH_LONG).show();	// "STATUS_SUCCESSFUL"と表示.
				}
			}
			c.close();
		}
	}
}
