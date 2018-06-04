package com.bgstation0.android.sample.webview_;

import android.content.Context;
import android.webkit.WebView;
import android.webkit.WebViewClient;

public class CustomWebViewClient extends WebViewClient {

	// メンバフィールドの定義
	private Context mContext;	// Context型mContext

	// コンストラクタ
	public CustomWebViewClient(Context context){
			
			// メンバの初期化
			mContext = context;	// 引数のcontextをメンバのmContextにセット.
			
	}
	
	// ロードするURLが変わった時.
	@Override
	public boolean shouldOverrideUrlLoading(WebView view, String url){
		
		// falseを返すと, 必ずこのWebViewで処理するようになる.
		return false;	// falseを返す.
		
	}
	
}
