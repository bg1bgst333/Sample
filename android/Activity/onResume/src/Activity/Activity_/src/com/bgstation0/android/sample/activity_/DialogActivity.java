package com.bgstation0.android.sample.activity_;

import android.app.Activity;
import android.os.Bundle;
import android.widget.TextView;

//ダイアログ風アクティビティDialogActivity.
public class DialogActivity extends Activity {	// DialogActivityの定義.

	// タグの定義
	private final String TAG = "DialogActivity";	// TAGは"DialogActivity"
	
	// Activityが生成されたとき.
	@Override
	protected void onCreate(Bundle savedInstanceState) {	// onCreateの定義
		
		// 親クラスの処理
		super.onCreate(savedInstanceState);	// super.onCreateで親クラスの既定処理.
		
		// "SubActivity!"の表示.
		TextView tv = new TextView(this);	// TextViewオブジェクトtvの生成.
		tv.setText("DialogActivity!");	// tv.setTextで"DialogActivity!"のセット.
		setContentView(tv);	// setContentViewでtvを表示.
	}
}
