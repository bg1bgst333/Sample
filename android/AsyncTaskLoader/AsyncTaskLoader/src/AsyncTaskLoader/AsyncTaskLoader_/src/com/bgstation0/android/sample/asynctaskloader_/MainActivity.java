package com.bgstation0.android.sample.asynctaskloader_;

import android.app.Activity;
import android.app.LoaderManager.LoaderCallbacks;
import android.content.Loader;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.TextView;

public class MainActivity extends Activity implements OnClickListener, LoaderCallbacks<String>{	// View.OnClickListener, LoaderCallbacksを実装.
    
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
    	// Loaderの初期化
        Bundle args = new Bundle();	// Bundle型
        args.putInt("param", 10);	// args.putIntでキーを"param", 値を10として引数を渡す.
        getLoaderManager().initLoader(0, args, this);	// initLoaderでLoader初期化.(事実上の開始.)
    }
    
    // Loaderの作成時
    @Override
    public Loader<String> onCreateLoader(int id, Bundle args){
    	// argsから引数を取り出し, CustomAsyncTaskLoaderに渡して生成.
    	int param = args.getInt("param");	// キー"param"の値をparamに格納.
    	return new CustomAsyncTaskLoader(this, param);	// newでthisとparamをCustomAsyncTaskLoaderに渡して生成, returnで返す.
    }
    
    // Loaderの終了時
    @Override
    public void onLoadFinished(Loader<String> loader, String data){
    	// textview1に非同期処理の結果dataをセット.
    	TextView textview1 = (TextView)findViewById(R.id.textview1);	// textview1を取得.
		textview1.setText(data);	// textview1.setTextにdataをセット.
    }
    
    // Loaderのリセット時
    @Override
    public void onLoaderReset(Loader<String> loader){
    	
    }
}