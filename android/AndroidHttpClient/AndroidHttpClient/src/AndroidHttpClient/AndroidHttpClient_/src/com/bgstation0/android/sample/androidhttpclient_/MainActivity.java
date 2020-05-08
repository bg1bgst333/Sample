package com.bgstation0.android.sample.androidhttpclient_;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.TextView;

// メインアクティビティ
public class MainActivity extends Activity {

	// メンバフィールドの定義
	CustomAsyncTask mTask = null;	// CustomAsyncTaskオブジェクトmTaskをnullで初期化.
		
	// アクティビティ生成時.
    @Override
    protected void onCreate(Bundle savedInstanceState) {
    	
    	// 既定の処理
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // CustomAsyncTaskの生成と実行.
        mTask = new CustomAsyncTask(this);	// CustomAsyncTaskオブジェクトを作成しmTaskに格納.
        mTask.execute("http://bgstation0.com/");	// "http://bgstation0.com/"を渡して実行.
        
    }
    
}