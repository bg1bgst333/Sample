package com.bgstation0.android.sample.actionbar_;

import android.app.ActionBar;
import android.app.Activity;
import android.os.Bundle;

public class SubActivity extends Activity {

	@Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_sub);
        
        // アイコンをセット.
        ActionBar actionBar = getActionBar();	// actionBarを取得.
        actionBar.setIcon(R.drawable.icon1);	// icon1をセット.
        
    }
	
}