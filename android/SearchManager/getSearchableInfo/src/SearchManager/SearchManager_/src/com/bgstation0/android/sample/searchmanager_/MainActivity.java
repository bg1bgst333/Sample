package com.bgstation0.android.sample.searchmanager_;

import android.app.Activity;
import android.app.SearchManager;
import android.app.SearchableInfo;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.text.InputType;
import android.view.Menu;
import android.view.MenuItem;
import android.view.inputmethod.EditorInfo;
import android.widget.Toast;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        
    	super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // SearchManagerの取得.
        SearchManager searchManager = (SearchManager)getSystemService(Context.SEARCH_SERVICE);	// searchManagerを取得.
        SearchableInfo searchableInfo = searchManager.getSearchableInfo(getComponentName());	// searchManager.getSearchableInfoでsearchableInfoを取得.
        
        // SearchableInfoの取得.
        Toast.makeText(this, "hint = " + getString(searchableInfo.getHintId()), Toast.LENGTH_LONG).show();	// searchableInfo.getHintId()で取得したhintのIDからhintの文字列を取得して表示.
        int inputType = searchableInfo.getInputType();	// searchableInfo.getInputType()で入力タイプを取得.
        if (inputType == InputType.TYPE_CLASS_TEXT){	// TYPE_CLASS_TEXTなら.
        	Toast.makeText(this, "inputType = TYPE_CLASS_TEXT", Toast.LENGTH_LONG).show();	// "inputType = TYPE_CLASS_TEXT"を表示.
        }
        int imeOptions = searchableInfo.getImeOptions();	// searchableInfo.getImeOptions()でIMEオプションを取得.
        if (imeOptions == EditorInfo.IME_ACTION_SEARCH){	// IME_ACTION_SEARCHなら.
        	Toast.makeText(this, "imeOptions = IME_ACTION_SEARCH", Toast.LENGTH_LONG).show();	// "imeOptions = IME_ACTION_SEARCH"を表示.
        }
        
        // 検索ダイアログ表示.
        onSearchRequested();	// 親クラスのonSearchRequestedを呼ぶ.
        
    }
    
    @Override
    protected void onNewIntent(Intent intent){
    	
    	super.onNewIntent(intent);
    	
    	// 検索クエリの取得.
        if (intent != null){	// intentがnullでない時.
        	String action = intent.getAction();	// actionを取得.
        	if (action != null){	// actionがnullでない時.
        		if (action.equals(Intent.ACTION_SEARCH)){	// actionがIntent.ACTION_SEARCHの時.
        			String query = intent.getStringExtra(SearchManager.QUERY);	// queryを取得.
        			Toast.makeText(this, "query = " + query, Toast.LENGTH_LONG).show();	// queryを表示.
        		}
        	}
        }
        
    }
    
}