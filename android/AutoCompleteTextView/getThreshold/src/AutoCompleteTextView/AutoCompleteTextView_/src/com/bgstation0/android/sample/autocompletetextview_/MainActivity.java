package com.bgstation0.android.sample.autocompletetextview_;

import android.app.Activity;
import android.app.SearchManager;
import android.app.SearchableInfo;
import android.content.Context;
import android.os.Bundle;
import android.provider.SearchRecentSuggestions;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.AutoCompleteTextView;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

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
        
        // エディットテキストの取得.
        final EditText editText = (EditText)findViewById(R.id.edittext);	// editTextの取得.
        
        // オートコンプリートテキストビューの取得.
        final AutoCompleteTextView autoCompleteTextView = (AutoCompleteTextView)findViewById(R.id.autocompletetextview);	// autoCompleteTextViewの取得.

        // オートコンプリートのサジェスト閾値を取得.
        int threshold = autoCompleteTextView.getThreshold();	// thresholdを取得.
        Toast.makeText(mContext, "autoCompleteTextView threshold = " + String.valueOf(threshold), Toast.LENGTH_LONG).show();	// thresholdを表示.
        
        // ボタンの取得.
        final Button button = (Button)findViewById(R.id.button);	// buttonの取得.
        
        // SearchManagerの取得.
        SearchManager searchManager = (SearchManager)getSystemService(Context.SEARCH_SERVICE);	// searchManagerの取得.
        
        // SearchableInfoの取得.
        SearchableInfo searchableInfo = (SearchableInfo)searchManager.getSearchableInfo(getComponentName());	// searchableInfoの取得.
        
        // CustomCursorAdapterのセット.
        mAdapter = new CustomCursorAdapter(this, true, searchableInfo);	// mAdapterの生成.
        autoCompleteTextView.setAdapter(mAdapter);	// autoCompleteTextViewにセット.
    
        // SearchRecentSuggestionsの生成.
        mSuggestions = new SearchRecentSuggestions(mContext, CustomContentProvider.AUTHORITY, CustomContentProvider.MODE);	// SearchRecentSuggestionsオブジェクトmSuggestionsの生成.
        
        // リスナーのセット.
        button.setOnClickListener(new View.OnClickListener() {	// setOnClickListenerでセット.
			
			@Override
			public void onClick(View v) {
				
				// TODO Auto-generated method stub
				// クエリの保存.
				String line1 = editText.getText().toString();	// line1の取得.
				String line2 = autoCompleteTextView.getText().toString();	// line2の取得.
				mSuggestions.saveRecentQuery(line1, line2);	// line1, line2をともに登録.
				
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