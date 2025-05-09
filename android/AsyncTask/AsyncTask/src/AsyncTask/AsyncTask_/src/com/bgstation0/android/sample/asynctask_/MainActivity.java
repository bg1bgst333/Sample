package com.bgstation0.android.sample.asynctask_;

import android.app.Activity;
import android.os.AsyncTask;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;

public class MainActivity extends Activity implements OnClickListener{	// View.OnClickListenerを実装.

	// メンバフィールドの定義
	CustomAsyncTask task = null;	// CustomAsyncTaskオブジェクトtaskをnullに.
	
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // button1を取得し, OnClickListenerとして自身をセット.
        Button button1 = (Button)findViewById(R.id.button1);	// findViewByIdでR.id.button1を取得.
        button1.setOnClickListener(this);	// button1.setOnClickListenerでthis(自身)をセット.
    }
    
    // View.OnClickListenerインタフェースのオーバーライドメソッドを実装.
    public void onClick(View v){	// onClickをオーバーライド.
    	// CustomAsyncTaskによる非同期処理を生成し, 実行.
    	task = new CustomAsyncTask(this);	// CustomAsyncTaskオブジェクトを作成し, taskに格納.
    	task.execute(10);	// task.executeに10を渡して実行.
    }
}
