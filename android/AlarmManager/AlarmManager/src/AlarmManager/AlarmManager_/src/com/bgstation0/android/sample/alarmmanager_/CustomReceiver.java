package com.bgstation0.android.sample.alarmmanager_;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.widget.Toast;

public class CustomReceiver extends BroadcastReceiver {

	// メンバフィールドの定義
	private final String PACKAGE_NAME = getClass().getPackage().getName();	// パッケージ名文字列を取得.
	private final String CLASS_NAME_SUBACTIVITY = SubActivity.class.getName();	// SubActivityのクラス名文字列を取得.
	
	// ブロードキャストインテントを受けた時.
	@Override
	public void onReceive(Context context, Intent intent) {
		// TODO Auto-generated method stub	
		// SubActivityを起動.
		Intent i = new Intent();	// インテントiを作成.
		i.setClassName(PACKAGE_NAME, CLASS_NAME_SUBACTIVITY);	// パッケージ名と起動するアクティビティのクラス名を指定.
		i.setFlags(Intent.FLAG_ACTIVITY_NEW_TASK);	// 既に同じアクティビティがいても新たに生成するフラグ.
		context.startActivity(i);	// context.startActivityでSubActivityを起動.
	}

}
