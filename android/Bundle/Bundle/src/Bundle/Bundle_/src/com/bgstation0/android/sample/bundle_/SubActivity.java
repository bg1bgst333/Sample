package com.bgstation0.android.sample.bundle_;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.widget.TextView;

public class SubActivity extends Activity {

	// Activityが生成されたとき.
	@Override
	protected void onCreate(Bundle savedInstanceState) {	// onCreateの定義
		super.onCreate(savedInstanceState);
		
		// 渡されたIntent情報を取得.
		Intent intent = getIntent();	// getIntentで渡されたintentを取得.
		Bundle args = intent.getExtras();	// intent.getExtrasでBundle型argsを取得.
		String str = args.getString("str");	// args.getStringで"str"をキーとする値を取得.
		int num = args.getInt("num");	// args.getIntで"num"をキーとする値を取得.
		boolean bool = args.getBoolean("bool");	// args.getBooleanで"bool"をキーとする値を取得.
		
		// SubActivityに渡された値を表示.
		TextView tv = new TextView(this);	// TextViewオブジェクトtvの生成.
		String tvStr = "";	// 表示する文字列tvStrを""で初期化.
		tvStr = tvStr + "str = ";	// "str = "を連結.
		tvStr = tvStr + str;	// strを連結.
		tvStr = tvStr + ", ";	// ", "を連結.
		tvStr = tvStr + "num = ";	// "num = "を連結.
		tvStr = tvStr + num;	// numを連結.
		tvStr = tvStr + ", ";	// ", "を連結.
		tvStr = tvStr + "bool = ";	// "bool = "を連結.
		if (bool){
			tvStr = tvStr + "true";	// "true"を連結.
		}
		else{
			tvStr = tvStr + "false";	// "false"を連結.
		}
		tv.setText(tvStr);	// tv.setTextでtvStrをセット.
		setContentView(tv);	// setContentViewでtvを表示.
	}
}
