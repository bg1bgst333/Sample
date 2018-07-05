package com.bgstation0.android.sample.wv.wvt_;

import android.app.Activity;
import android.content.Context;
import android.webkit.WebView;
import android.webkit.WebViewClient;

public class CustomWebViewClient extends WebViewClient {

	// メンバフィールドの定義
	private Context mContext;	// Context型mContext
	private MainActivity mMainActivity;	// mMainActivity.
		
	// コンストラクタ
	public CustomWebViewClient(Context context, Activity mainActivity){
		
		// メンバの初期化
		mContext = context;	// 引数のcontextをメンバのmContextにセット.
		mMainActivity = (MainActivity)mainActivity;	// mainActivityをセット.
		
	}
	
	// ロードするURLが変わった時.
	@Override
	public boolean shouldOverrideUrlLoading(WebView view, String url){
		
		// falseを返すと, 必ずこのWebViewで処理するようになる.
		return false;	// falseを返す.
		
	}
		
}