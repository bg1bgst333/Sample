package com.bgstation0.android.sample.fragment_;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;

public class SubActivity extends Activity {

	 @Override
	 protected void onCreate(Bundle savedInstanceState) {
	        super.onCreate(savedInstanceState);
	        setContentView(R.layout.activity_sub);
	 }
	 
	 // バックキーが押された時.
	 @Override
	 public void onBackPressed(){
		 Intent data = new Intent();	// dataインテント生成.
		 data.putExtra("message", "ABCDE");	// "ABCDE".
		 setResult(RESULT_OK, data);	// OK.
		 finish();	// 終了.
		 super.onBackPressed();
	 }
	 
}