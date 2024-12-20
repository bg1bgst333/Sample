package com.bgstation0.android.sample.websettings_;

import android.app.Activity;
import android.content.Context;
import android.graphics.Bitmap;
import android.net.http.SslError;
import android.opengl.Visibility;
import android.view.View;
import android.webkit.SslErrorHandler;
import android.webkit.WebSettings;
import android.webkit.WebView;
import android.webkit.WebViewClient;
import android.widget.EditText;
import android.widget.ProgressBar;
import android.widget.TextView;
import android.widget.Toast;

public class CustomWebViewClient extends WebViewClient {

	// メンバフィールドの定義
	private Context context;	// Context型context
	private EditText urlBar;	// EditText型urlBar
	private TextView progressTextView;	// TextView型progressTextView
	private ProgressBar progressBar;	// ProgressBar型progressBar.
	
	// コンストラクタ
	public CustomWebViewClient(Context context){
		
		// メンバの初期化
		this.context = context;	// 引数のcontextをメンバのcontextにセット.
		Activity activity = (Activity)context;	// contextをActivity型のactivityにキャスト.
		urlBar = (EditText)activity.findViewById(R.id.urlbar);	// urlBarを取得.
		progressTextView = (TextView)activity.findViewById(R.id.progresstextview);	// progressTextViewを取得.
		progressTextView.setVisibility(View.INVISIBLE);	// progressTextView.setVisibilityでINVISIBLEにセット.
        progressBar = (ProgressBar)activity.findViewById(R.id.progressbar);	// findViewByIdでR.id.progressbarを取得し, progressBarに格納.
        progressBar.setMax(100);	// progressBar.setMaxで最大値を100にセット.
        progressBar.setProgress(0);	// progressBar.setProgressで進捗に0をセット.
        progressBar.setVisibility(View.INVISIBLE);	// progressBar.setVisibilityでINVISIBLEにセット.
        
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
		
		// 進捗状況(プログレスバー)の表示.
		progressBar.setProgress(0);	// progressBar.setProgressで進捗に0をセット.
        progressBar.setVisibility(View.VISIBLE);	// progressBar.setVisibilityでVISIBLEにセット.
        
		// URLの更新
		urlBar.setText(url);	// urlBar.setTextでurlをセット.
				
	}
	
	// ページのロードが終了した時.
	@Override
	public void onPageFinished(WebView view, String url){
		
		// 進捗状況(プログレステキスト)の非表示.
		progressTextView.setVisibility(View.INVISIBLE);	// progressTextView.setVisibilityでINVISIBLEにセット.
		
		// 進捗状況(プログレスバー)の非表示.
		progressBar.setProgress(100);	// progressBar.setProgressで進捗に100をセット.
		progressBar.setVisibility(View.INVISIBLE);	// progressBar.setVisibilityでINVISIBLEにセット.
		
		// ユーザエージェント文字列の表示.
		WebSettings webSettings = view.getSettings();	// view.getSettingsでwebSettingsを取得.
		Toast.makeText(context, webSettings.getUserAgentString(), Toast.LENGTH_LONG).show();	// ToastでwebSettings.getUserAgentStringで取得できるユーザエージェント文字列を表示.
		
	}
	
	// エラーが発生した時.
	@Override
	public void onReceivedError(WebView view, int errorCode, String description, String failingUrl){
		
		// エラーコードと説明の表示.
		Toast.makeText(context, Integer.toString(errorCode) + ":" + description, Toast.LENGTH_LONG).show();	// ToastでerrorCodeとdescriptionを表示.
		
	}
	
	// SSLエラーが発生した時.
	@Override
	public void onReceivedSslError(WebView view, SslErrorHandler handler, SslError error){
		
		// SSLエラーのエラーメッセージを表示.
		Toast.makeText(context, "SSL Error!", Toast.LENGTH_LONG).show();	// Toastで"SSL Error!"を表示.
		
		// 親クラスのonReceivedSslErrorに任せる.
		super.onReceivedSslError(view, handler, error);	// super.onReceivedSslErrorに任せる.
		
	}
	
}