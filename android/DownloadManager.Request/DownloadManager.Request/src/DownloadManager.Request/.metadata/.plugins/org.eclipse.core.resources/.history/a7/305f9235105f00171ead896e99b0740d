package com.bgstation0.android.sample.downloadmanager.query_;

import android.app.Activity;
import android.content.Context;
import android.webkit.WebChromeClient;
import android.webkit.WebView;
import android.widget.TextView;

public class CustomWebChromeClient extends WebChromeClient {

	// メンバフィールドの定義
	private Context context;	// Context型context
	private TextView progressTextView;	// TextView型progressTextView
	
	// コンストラクタ
	public CustomWebChromeClient(Context context){
		
		// メンバの初期化
		this.context = context;	// 引数のcontextをメンバのcontextにセット.
		Activity activity = (Activity)context;	// contextをActivity型のactivityにキャスト.
		progressTextView = (TextView)activity.findViewById(R.id.progresstextview);	// progressTextViewを取得.
		
	}
	
	// ロードの進捗が変化した時.
	@Override
	public void onProgressChanged(WebView view, int newProgress){
		
		// 進捗の更新.
		progressTextView.setText(newProgress + "%");	// progressTextView.setTextでnewProgressを"%"を付けて表示.
		
	}
	
}