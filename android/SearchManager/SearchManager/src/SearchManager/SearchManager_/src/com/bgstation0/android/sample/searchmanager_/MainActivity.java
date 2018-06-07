package com.bgstation0.android.sample.searchmanager_;

import android.app.Activity;
import android.app.SearchManager;
import android.content.Context;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
    	
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // SearchManagerの取得.
        SearchManager searchManager = (SearchManager)getSystemService(Context.SEARCH_SERVICE);	// searchManagerを取得.
        
        // システム共通の検索ダイアログを表示.
        searchManager.startSearch("ABC", false, getComponentName(), null, false);	// searchManager.startSearchで検索ダイアログを表示.
        
    }
    
}