package com.bgstation0.android.sample.view_;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.TextView;

//メインアクティビティ
public class MainActivity extends Activity {

	// メンバフィールド
	static final String TAG = "MainActivity";	// TAGを"MainActivity"で初期化.
	
	// 生成時
    @Override
    protected void onCreate(Bundle savedInstanceState) {
    	
    	// 既定の処理.
    	super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // textview1の親のViewを取得.
        TextView textview1 = (TextView)findViewById(R.id.textview1);	// textview1を取得.
        View view = (View)textview1.getParent();	// 親のviewを取得.
        if (view != null){	// nullでない.
        	if (view.getId() == R.id.layout_main){	// IDがlayout_mainなら.
        		Log.d(TAG, "layout_main!");	// "layout_main!"とログ出力.
        	}
        }
        
    }
    
}
