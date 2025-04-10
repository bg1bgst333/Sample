package com.bgstation0.android.sample.th.tcf_;

import android.app.Activity;
import android.app.TabActivity;
import android.content.Context;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.TabHost;
import android.widget.TextView;

public class MainActivity extends TabActivity {

	// メンバフィールドの定義.
	Context mContext = null;	// mContextをnullで初期化.
	
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    
        // コンテキストのセット.
        mContext = this;	// mContextにthisをセット.
        
        // tabHostの取得.
        TabHost tabHost = getTabHost();	// getTabHostでtabHostを取得.
        
        // tabSpec1の作成.
        TabHost.TabSpec tabSpec1 = tabHost.newTabSpec("Tab1");	// tabSpec1を作成.
        // テキストのセット.
        tabSpec1.setIndicator("Tab1");	// テキストは"Tab1".
        // コンテンツのセット.
        tabSpec1.setContent(new TabHost.TabContentFactory() {	// TabContentFactoryのインスタンスをセット.
			
			@Override
			public View createTabContent(String tag) {
				// TODO Auto-generated method stub
				TextView tv = new TextView(mContext);	// tvを生成.
				tv.setText(tag);	// tag(tabHost.newTabSpecで指定したタブ名なので"Tab1")をセット.
				return tv;	// tvを返す.
			}
			
		});
        // タブの追加.
        tabHost.addTab(tabSpec1);	// tabHost.addTabでtabSpec1を追加.
        
        // tabSpec2の作成.
        TabHost.TabSpec tabSpec2 = tabHost.newTabSpec("Tab2");	// tabSpec2を作成.
        // テキストのセット.
        tabSpec2.setIndicator("Tab2");	// テキストは"Tab2".
        // コンテンツのセット.
        tabSpec2.setContent(new TabHost.TabContentFactory() {	// TabContentFactoryのインスタンスをセット.
			
			@Override
			public View createTabContent(String tag) {
				// TODO Auto-generated method stub
				TextView tv = new TextView(mContext);	// tvを生成.
				tv.setText(tag);	// tag(tabHost.newTabSpecで指定したタブ名なので"Tab2")をセット.
				return tv;	// tvを返す.
			}
			
		});
        // タブの追加.
        tabHost.addTab(tabSpec2);	// tabHost.addTabでtabSpec2を追加.
        
    }
    
}