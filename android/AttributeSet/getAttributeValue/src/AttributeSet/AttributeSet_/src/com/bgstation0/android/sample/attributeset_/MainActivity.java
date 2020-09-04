package com.bgstation0.android.sample.attributeset_;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;

// メインアクティビティクラスMainActivityの定義.
public class MainActivity extends Activity {

	// アクティビティ生成時
    @Override
    protected void onCreate(Bundle savedInstanceState) {
    	
    	// 既定の処理
        super.onCreate(savedInstanceState);
        
        // カスタムビューのセット.
        setContentView(R.layout.activity_main);	// setContentViewでR.layout.activity_mainをセット.
        
    }
    
}
