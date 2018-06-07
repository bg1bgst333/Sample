package com.bgstation0.android.sample.activity_;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        
    	super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    
        // システム共通の検索ダイアログを表示.
        startSearch("ABC", false, null, false);	// startSearchで検索.(ローカル検索)
        
    }
    
}