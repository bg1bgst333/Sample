package com.bgstation0.android.sample.searchrecentsuggestions_;

import android.content.SearchRecentSuggestionsProvider;

public class CustomContentProvider extends SearchRecentSuggestionsProvider {

	// メンバフィールドの定義.
	public final static String AUTHORITY = "com.bgstation0.android.sample.searchrecentsuggestions_.CustomContentProvider";
	public final static int MODE =  DATABASE_MODE_QUERIES;
	
	// コンストラクタ
	public CustomContentProvider(){
		
		// 初期化処理.
		super();	// 親クラスのコンストラクタを呼ぶ.
		setupSuggestions(AUTHORITY, MODE);	// setupSuggestionsでAUTHORITYとMODEをセットして, セットアップ.
		
	}
	
}
