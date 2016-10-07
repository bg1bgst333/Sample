package com.bgstation0.android.sample.httpurlconnection_;

import android.app.Activity;
import android.app.LoaderManager.LoaderCallbacks;
import android.content.Loader;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.EditText;

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
    	EditText edittext1 = (EditText)findViewById(R.id.edittext1);	// edittext1の取得.
    	String url = edittext1.getText().toString();	// edittext1の内容をurlに代入.
    	args.putString("url", url);	// args.putStringでurlをargsにセット.
    	getLoaderManager().initLoader(0, args, this);	// initLoaderでLoader初期化.(事実上の開始.)
    }
    
    // Loaderの作成時
    @Override
    public Loader<String> onCreateLoader(int id, Bundle args){
    	// argsから引数を取り出し, CustomAsyncTaskLoaderに渡して生成.
    	String url = args.getString("url");	// キー"url"の値をurlに格納.
    	return new CustomAsyncTaskLoader(this, url);	// newでthisとurlをCustomAsyncTaskLoaderに渡して生成, returnで返す.
    }

    // Loaderの終了時
    @Override
    public void onLoadFinished(Loader<String> loader, String data){
    	// edittext1に非同期処理の結果dataをセット.
    	EditText edittext2 = (EditText)findViewById(R.id.edittext2);	// edittext2を取得.
    	edittext2.setText(data);	// edittext2.setTextでdataをセット.
    }
    
    // Loaderのリセット時
    @Override
    public void onLoaderReset(Loader<String> loader){
    	
    }
}