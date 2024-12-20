package com.bgstation0.android.sample.searchrecentsuggestions_;

import android.app.Activity;
import android.app.SearchManager;
import android.app.SearchableInfo;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.provider.SearchRecentSuggestions;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.SearchView;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
    	
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // SearchManagerの取得.
        SearchManager searchManager = (SearchManager)getSystemService(Context.SEARCH_SERVICE);	// searchManagerを取得.
        // searchableInfoの取得.
        SearchableInfo searchableInfo = searchManager.getSearchableInfo(getComponentName());	// searchManager.getSearchableInfoでsearchableInfoを取得.
        
        // SearchViewの取得.
        SearchView searchView = (SearchView)findViewById(R.id.searchview);	// searchviewを取得.
        // searchableInfoのセット.
        searchView.setSearchableInfo(searchableInfo);	// searchView.setSearchableInfoでsearchViewにsearchableInfoをセット.
        
    }
    
    @Override
    protected void onNewIntent(Intent intent){
    	
    	super.onNewIntent(intent);
    	
    	// 検索クエリの取得.
        if (intent != null){	// intentがnullでない時.
        	String action = intent.getAction();	// actionを取得.
        	if (action != null){	// actionがnullでない時.
        		if (action.equals(Intent.ACTION_SEARCH)){	// actionがIntent.ACTION_SEARCHの時.
        			
        			// クエリの表示.
        			String query = intent.getStringExtra(SearchManager.QUERY);	// queryを取得.
        			
        			// クエリの登録.
        			SearchRecentSuggestions suggestions = new SearchRecentSuggestions(this, CustomContentProvider.AUTHORITY, CustomContentProvider.MODE);	// SearchRecentSuggestionsオブジェクトsuggestionsの生成.
        			suggestions.saveRecentQuery(query, "line2 = " + query);	// suggestions.saveRecentQueryでクエリを保存.(第2引数に"line2 = " + query)を渡す.
        			
        		}
        	}
        }
        
    }
    
}