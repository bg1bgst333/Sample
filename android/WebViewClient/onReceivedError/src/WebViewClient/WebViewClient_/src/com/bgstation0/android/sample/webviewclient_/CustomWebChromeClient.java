package com.bgstation0.android.sample.webviewclient_;

import android.app.Activity;
import android.content.Context;
import android.webkit.WebChromeClient;
import android.webkit.WebView;
import android.widget.ProgressBar;
import android.widget.TextView;

public class CustomWebChromeClient extends WebChromeClient {

	// メンバフィールドの定義
	private Context context;	// Context型context
	private TextView progressTextView;	// TextView型progressTextView
	private ProgressBar progressBar;	// ProgressBar型progressBar.
	
	// コンストラクタ
	public CustomWebChromeClient(Context context){
		
		// メンバの初期化
		this.context = context;	// 引数のcontextをメンバのcontextにセット.
		Activity activity = (Activity)context;	// contextをActivity型のactivityにキャスト.
		progressTextView = (TextView)activity.findViewById(R.id.progresstextview);	// progressTextViewを取得.
		progressBar = (ProgressBar)activity.findViewById(R.id.progressbar);	// findViewByIdでR.id.progressbarを取得し, progressBarに格納.
		
	}
	
	// ロードの進捗が変化した時.
	@Override
	public void onProgressChanged(WebView view, int newProgress){
		
		// 進捗の更新.
		progressTextView.setText(newProgress + "%");	// progressTextView.setTextでnewProgressを"%"を付けて表示.
		progressBar.setProgress(newProgress);	// progressBar.setProgressで進捗にnewProgressをセット.
		
	}
	
}