package com.bgstation0.android.sample.activity_;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }
    
    // オプションメニューが作成される時.
    @Override
    public boolean onCreateOptionsMenu(Menu menu){
    	
    	// メニューアイテムの追加.
    	menu.add("Menu1");	// menu.addで"Menu1"を追加.
    	menu.add("Menu2");	// menu.addで"Menu2"を追加.
    	
    	// 親クラスの処理.
    	return super.onCreateOptionsMenu(menu);	// super.onCreateOptionsMenuで親クラスの既定処理.
    	
    }
}
