package com.bgstation0.android.sample.webview_;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.webkit.WebView;
import android.widget.Button;
import android.widget.EditText;

public class MainActivity extends Activity implements OnClickListener{	// View.OnClickListenerを実装.

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // navigateButtonを取得し, OnClickListenerとして自身をセット.
        Button navigateButton = (Button)findViewById(R.id.navigatebutton);	// R.id.navigatebuttonを取得.
        navigateButton.setOnClickListener(this);	// navigateButton.setOnClickListenerでthis(自身)をセット.        
    }
    
    // View.OnClickListenerインタフェースのオーバーライドメソッドを実装.
    public void onClick(View v){	// onClickをオーバーライド.
    	// ボタンのidをごとに処理を振り分ける.
    	switch (v.getId()) {	// v.getIdでView(Button)のidを取得.
    		case R.id.navigatebutton:	// R.id.navigatebuttonの時.
    			
    			// navigateButtonブロック
    			{
    				
    				// urlBarのurlを取得.
    				EditText urlBar = (EditText)findViewById(R.id.urlbar);	// findViewByIdでurlBarを取得.
    				String url = urlBar.getText().toString();	// urlBar.getText().toString()でurlを取得.
    				
    				// WebViewオブジェクトwebViewでurlのサイトを表示.
    				WebView webView = (WebView)findViewById(R.id.webview);	// findViewByIdでwebViewを取得.
    				webView.loadUrl(url);	// webView.loadUrlでurlのサイトを表示.
    				
    				// 抜ける.
    				break;	// breakで抜ける.
    				
    			}
    			
    	}
    }
}
