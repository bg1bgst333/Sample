package com.bgstation0.android.sample.scrollview_;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.ScrollView;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
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
    	
    		// Up
    		case R.id.menu_scrollup:
    			
    			// Upブロック
				{
					
					// 上にスクロール.
					ScrollView scrollView = (ScrollView)findViewById(R.id.scrollview);	// scrollViewを取得.
					scrollView.scrollTo(0, scrollView.getTop());	// scrollView.scrollToで上にスクロール.
					
				}
				
				break;
				
    		case R.id.menu_scrolldown:
    			
    			// Downブロック
				{
					
					// 下にスクロール.
					ScrollView scrollView = (ScrollView)findViewById(R.id.scrollview);	// scrollViewを取得.
					scrollView.scrollTo(0, scrollView.getBottom());	// scrollView.scrollToで下にスクロール.
				
				}
			
				break;
    
    	}
    	return super.onOptionsItemSelected(item);	// 親クラス既定処理
    	
    }
    
}