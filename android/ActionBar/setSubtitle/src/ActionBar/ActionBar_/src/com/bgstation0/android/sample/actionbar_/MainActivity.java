package com.bgstation0.android.sample.actionbar_;

import android.app.ActionBar;
import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // アイコン, ロゴ, タイトル, サブタイトルのセット.
        ActionBar actionBar = getActionBar();				// actionBarを取得.
        actionBar.setIcon(R.drawable.icon1);				// icon1をセット.
        actionBar.setLogo(R.drawable.logo1);				// logo1をセット.
        actionBar.setTitle(R.string.title_string);			// title_stringをセット.
        actionBar.setSubtitle(R.string.subtitle_string);	// subtitle_stringをセット.
        
    }
    
}
