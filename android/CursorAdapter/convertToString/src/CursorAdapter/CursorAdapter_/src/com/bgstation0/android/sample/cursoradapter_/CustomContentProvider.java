package com.bgstation0.android.sample.cursoradapter_;

import android.content.SearchRecentSuggestionsProvider;

public class CustomContentProvider extends SearchRecentSuggestionsProvider {

	// メンバフィールドの定義.
	public final static String AUTHORITY = "com.bgstation0.android.sample.cursoradapter_.CustomContentProvider";
	public final static int MODE =  DATABASE_MODE_QUERIES | DATABASE_MODE_2LINES;	// DATABASE_MODE_2LINESを追加.
	
	// コンストラクタ
	public CustomContentProvider(){
		
		// 初期化処理.
		super();	// 親クラスのコンストラクタを呼ぶ.
		setupSuggestions(AUTHORITY, MODE);	// setupSuggestionsでAUTHORITYとMODEをセットして, セットアップ.
		
	}
	
}