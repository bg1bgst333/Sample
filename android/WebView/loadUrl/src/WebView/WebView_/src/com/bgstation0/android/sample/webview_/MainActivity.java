package com.bgstation0.android.sample.webview_;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.webkit.WebView;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // WebViewでローカルHTMLファイルを表示.
        WebView webView = (WebView)findViewById(R.id.webview);	// findViewByIdでwebViewを取得.
        webView.loadUrl("file:///android_asset/test.html");	// webView.loadUrlでassetsフォルダのtest.htmlをロード.
    }
}
