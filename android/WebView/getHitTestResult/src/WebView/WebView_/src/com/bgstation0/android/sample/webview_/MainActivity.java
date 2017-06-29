package com.bgstation0.android.sample.webview_;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.View.OnLongClickListener;
import android.webkit.WebSettings;
import android.webkit.WebView;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class MainActivity extends Activity implements OnClickListener, OnLongClickListener{	// View.OnClickListener, View.OnLongClickListenerを実装.

	// メンバフィールドの定義
	public WebView webView;	// WebViewオブジェクトwebView
	public CustomWebViewClient customWVC;	// CustomWebViewClientオブジェクトcustomWVC
	public CustomWebChromeClient customWCC;	// CustomWebChromeClientオブジェクトcustomWCC
	public WebSettings webSettings;			// WebSettingsオブジェクトwebSettings
	
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // loadbuttonを取得し, OnClickListenerとして自身をセット.
        Button loadButton = (Button)findViewById(R.id.loadbutton);	// loadButtonを取得.
        loadButton.setOnClickListener(this);	// loadButton.setOnClickListenerでthisをセット.
        
        // WebViewの初期設定.
        webView = (WebView)findViewById(R.id.webview);	// webViewを取得.
        webView.setOnLongClickListener(this);	// webView.setOnLongClickListenerでthisをセット.
        customWVC = new CustomWebViewClient(this);	// CustomWebViewClientオブジェクトcustomWVCを作成.
        webView.setWebViewClient(customWVC);	// webView.setWebViewClientでcustomWVCをセット.
        customWCC = new CustomWebChromeClient(this);	// CustomWebChromeClientオブジェクトcustomWCCを作成.
        webView.setWebChromeClient(customWCC);	// webView.setWebChromeClientでcustomWCCをセット.
        webSettings = webView.getSettings();	// webView.getSettingsでwebSettingsを取得.
        webSettings.setJavaScriptEnabled(true);	// webSettings.setJavaScriptEnabledでJavaScriptを有効にする.
        
    }
    
    // メニューが作成された時.
    @Override
    public boolean onCreateOptionsMenu(Menu menu){
    	
    	// メニューの作成
    	getMenuInflater().inflate(R.menu.main, menu);	// getMenuInflaterでMenuItemを取得し, そのままinflateで指定されたR.menu.mainを元にmenuを作成.
    	return true;	// trueを返す.
    	
    }
    
    // メニューが選択された時.
    @Override
    public boolean onOptionsItemSelected(MenuItem item){
    
    	// どのメニューが選択されたか.
    	switch (item.getItemId()){	// アイテムIDごとに振り分け.
    	
    		// GoBack
    		case R.id.menu_goback:
    			
    			// GoBackブロック
    			{
    				
    				// 戻れるなら戻る, 戻れなかったら"戻れません!"と表示.
    				if (webView.canGoBack()){	// canGoBackで前に戻れるかチェック.
    					
    					// 1つ前のページに戻る.
    					webView.goBack();	// webView.goBackで1つ前のページに戻る.

    				}
    				else{
    					
    					// "戻れません!"と表示.
    					Toast.makeText(this, "戻れません!", Toast.LENGTH_LONG).show();	// Toastで"戻れません!"と表示.
    					
    				}
    				
    			}
    			
    			break;
    			
    	}
    	
    	return super.onOptionsItemSelected(item);	// 親クラス既定処理
    	
    }
    
    // View.OnClickListenerインタフェースのオーバーライドメソッドを実装.
    public void onClick(View v){	// onClickをオーバーライド.
    	
    	// ボタンのidをごとに処理を振り分ける.
    	switch (v.getId()) {	// v.getIdでView(Button)のidを取得.
    		
    		case R.id.loadbutton:	// R.id.loadbuttonの時.
    			
    			// navigateButtonブロック
				{
					
					// urlBarのurlを取得.
    				EditText urlBar = (EditText)findViewById(R.id.urlbar);	// urlBarを取得.
    				String url = urlBar.getText().toString();	// urlBar.getText().toString()でurlを取得.
  
    				// webViewでurlのサイトを表示.
    				webView.loadUrl(url);	// webView.loadUrlでurlのサイトを表示.
    				
    				// 抜ける.
    				break;	// breakで抜ける.
    				
				}
				
    	}
    	
    }
    
    // View.OnLongClickListenerインタフェースのオーバーライドメソッドを実装.
    public boolean onLongClick(View v){	// onLongClickをオーバーライド.
    
    	// 長押しされた部分の情報を取得.
    	WebView wv = (WebView)v;	// vをWebViewのwvにキャスト.
    	WebView.HitTestResult hr = wv.getHitTestResult();	// wv.getHitTestResultでWebView.HitTestResult型hrを取得.
    	if (hr.getType() == WebView.HitTestResult.IMAGE_TYPE){	// 長押し部分が単純な画像のみの場合.
    		Toast.makeText(this, "IMAGE_TYPE", Toast.LENGTH_LONG).show();	// Toastで"IMAGE_TYPE"と表示.
    	}
    	else{	// それ以外.
    		Toast.makeText(this, "Not IMAGE_TYPE", Toast.LENGTH_LONG).show();	// Toastで"Not IMAGE_TYPE"と表示.
    	}
    	
    	return true;	// trueを返すと, OnClickは発生しない.
    	
    }
    
}