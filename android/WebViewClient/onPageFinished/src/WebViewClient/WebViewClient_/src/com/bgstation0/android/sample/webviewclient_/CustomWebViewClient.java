package com.bgstation0.android.sample.webviewclient_;

import android.app.Activity;
import android.content.Context;
import android.graphics.Bitmap;
import android.opengl.Visibility;
import android.view.View;
import android.webkit.WebView;
import android.webkit.WebViewClient;
import android.widget.EditText;
import android.widget.TextView;

public class CustomWebViewClient extends WebViewClient {

	// メンバフィールドの定義
	private Context context;	// Context型context
	private EditText urlBar;	// EditText型urlBar
	private TextView progressTextView;	// TextView型progressTextView
	
	// コンストラクタ
	public CustomWebViewClient(Context context){
		
		// メンバの初期化
		this.context = context;	// 引数のcontextをメンバのcontextにセット.
		Activity activity = (Activity)context;	// contextをActivity型のactivityにキャスト.
		urlBar = (EditText)activity.findViewById(R.id.urlbar);	// urlBarを取得.
		progressTextView = (TextView)activity.findViewById(R.id.progresstextview);	// progressTextViewを取得.
		progressTextView.setVisibility(View.INVISIBLE);	// progressTextView.setVisibilityでINVISIBLEにセット.
		
	}
	
	// ロードするURLが変わった時.
	@Override
	public boolean shouldOverrideUrlLoading(WebView view, String url){
		
		// falseを返すと, 必ずこのWebViewで処理するようになる.
		return false;	// falseを返す.
		
	}
	
	// ページのロードが開始された時.
	@Override
    public void onPageStarted(WebView view, String url, Bitmap favicon){
		
		// 進捗状況(プログレステキスト)の表示.
		progressTextView.setVisibility(View.VISIBLE);	// progressTextView.setVisibilityでVISIBLEにセット.
		
		// URLの更新
		urlBar.setText(url);	// urlBar.setTextでurlをセット.
				
	}
	
	// ページのロードが終了した時.
	@Override
	public void onPageFinished (WebView view, String url){
		
		// 進捗状況(プログレステキスト)の非表示.
		progressTextView.setVisibility(View.INVISIBLE);	// progressTextView.setVisibilityでINVISIBLEにセット.
				
	}
	
}