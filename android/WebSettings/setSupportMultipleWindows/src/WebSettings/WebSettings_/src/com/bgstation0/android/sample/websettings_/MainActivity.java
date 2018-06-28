package com.bgstation0.android.sample.websettings_;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.webkit.WebSettings;
import android.webkit.WebView;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class MainActivity extends Activity implements OnClickListener{	// View.OnClickListenerを実装.

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
        customWVC = new CustomWebViewClient(this);	// CustomWebViewClientオブジェクトcustomWVCを作成.
        webView.setWebViewClient(customWVC);	// webView.setWebViewClientでcustomWVCをセット.
        customWCC = new CustomWebChromeClient(this);	// CustomWebChromeClientオブジェクトcustomWCCを作成.
        webView.setWebChromeClient(customWCC);	// webView.setWebChromeClientでcustomWCCをセット.
        webSettings = webView.getSettings();	// webView.getSettingsでwebSettingsを取得.
        webSettings.setJavaScriptEnabled(true);	// webSettings.setJavaScriptEnabledでJavaScriptを有効にする.
        webSettings.setUserAgentString("Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/56.0.2924.87 Safari/537.36");	// webSettings.setUserAgentStringでWindows版Chromeのユーザエージェントをセット.
        webSettings.setBuiltInZoomControls(true);	// webSettings.setBuiltInZoomControls(true)で, 組み込みズーム機能(ピンチジェスチャー, ズームコントロール)を有効にする.
        webSettings.setDisplayZoomControls(true);	// webSettings.setDisplayZoomControls(true)で, ズームコントロールを表示にする.
        webSettings.setSupportZoom(false);	// webSettings.setSupportZoom(false)とする.
        webSettings.setSupportMultipleWindows(true);	// webSettings.setSupportMultipleWindows(true)で, 新しいウィンドウを開くイベントに対応する.
        
        // test.htmlをロード.
        webView.loadUrl("file:///android_asset/test.html");	// "file:///android_asset/test.html"をロード.
        
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
					
						// バックキーの既定の動作.
						super.onBackPressed();	// 既定の動作.(このActivityを閉じる.)
					
					}
				
				}
    			
    			break;
    			
    			// ZoomIn
    		case R.id.menu_zoomin:
    			
    			// ZoomInブロック
    			{
    				
    				// ズームインする.
    				webView.zoomIn();	// webView.zoomInでズームインする.
    				
    			}
    			
    			break;
    			
    		// ZoomOut
    		case R.id.menu_zoomout:
    			
    			// ZoomOutブロック
    			{
    		
    				// ズームアウトする.
    				webView.zoomOut();	// webView.zoomOutでズームアウトする.
    				
    			}
    			
    			break;
   			 
    	}
    	
    	return super.onOptionsItemSelected(item);	// 親クラス既定処理
    	
    }
    
    // バックキーが押された時.
    @Override
    public void onBackPressed(){
    	
    	// WebViewが戻れるなら戻す.
    	if (webView.canGoBack()){	// trueなら
    		webView.goBack();	// webViewを1つ前のページに戻す.
    	}
    	else{	// falseなら.
    		super.onBackPressed();	// 既定の動作.(このActivityを閉じる.)
    	}
    	
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
    
}