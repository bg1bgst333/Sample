package com.bgstation0.android.sample.cursoradapter_;

import android.app.Activity;
import android.app.SearchManager;
import android.app.SearchableInfo;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.provider.SearchRecentSuggestions;
import android.view.KeyEvent;
import android.view.Menu;
import android.view.MenuItem;
import android.view.inputmethod.EditorInfo;
import android.widget.AutoCompleteTextView;
import android.widget.TextView;

public class MainActivity extends Activity {

	// メンバフィールドの定義.
	Context mContext = null;	// mContextにnullをセット.
	CustomCursorAdapter mAdapter = null;	// mAdapterにnullをセット.
	SearchRecentSuggestions mSuggestions = null;	// mSuggestionsにnullをセット.
	
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // コンテキストのセット.
        mContext = this;	// mContextにthisをセット.
        
        // AutoCompleteTextViewの取得.
        final AutoCompleteTextView autoCompleteTextView = (AutoCompleteTextView)findViewById(R.id.autocompletetextview1);	// autoCompleteTextViewを取得.
        
        // SearchManagerの取得.
        SearchManager searchManager = (SearchManager)getSystemService(Context.SEARCH_SERVICE);	// searchManagerの取得.
        
        // SearchableInfoの取得.
        SearchableInfo searchableInfo = (SearchableInfo)searchManager.getSearchableInfo(getComponentName());	// searchableInfoの取得.
        
        // CustomCursorAdapterのセット.
        mAdapter = new CustomCursorAdapter(this, true, searchableInfo);	// mAdapterの生成.
        autoCompleteTextView.setAdapter(mAdapter);	// autoCompleteTextViewにセット.
    
        // SearchRecentSuggestionsの生成.
        mSuggestions = new SearchRecentSuggestions(mContext, CustomContentProvider.AUTHORITY, CustomContentProvider.MODE);	// SearchRecentSuggestionsオブジェクトmSuggestionsの生成.
        
        // エディターアクション.
        autoCompleteTextView.setOnEditorActionListener(new TextView.OnEditorActionListener() {
			
			@Override
			public boolean onEditorAction(TextView v, int actionId, KeyEvent event) {
				
				// TODO Auto-generated method stub
				// Enterキー(Done)が押された時.
				if (actionId == EditorInfo.IME_ACTION_DONE){	// IME_ACTION_DONEの時.
					
					// クエリの登録.
        			String query = autoCompleteTextView.getText().toString();	// queryを取得.
        			mSuggestions.saveRecentQuery(query, null);	// mSuggestions.saveRecentQueryでクエリを保存.
        			return true;	// trueを返す.
				
				}
				
				// false.
				return false;	// falseを返す.
				
			}
			
        });
        
    }
    
    // Activityが破棄されたとき.
    protected void onDestroy() {	// onDestroyの定義
    	
    	// 親クラスの処理
    	super.onDestroy();	// super.onDestroyで親クラスの既定処理.
    	
    	// アダプタを閉じる.
    	mAdapter.close();	// mAdapter.closeで閉じる.
    	
    }
    
}