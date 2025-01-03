package com.bgstation0.android.sample.typedarray_;

import android.app.Activity;
import android.content.res.Resources;
import android.content.res.TypedArray;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;

//メインアクティビティクラスMainActivityの定義.
public class MainActivity extends Activity {

    // メンバフィールドの定義
    static final String TAG = "MainActivity";	// TAGを"MainActivity"で初期化.

    // アクティビティ生成時
    @Override
    protected void onCreate(Bundle savedInstanceState) {
	
        // 既定の処理
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
      
        // 型付き配列の取得.
        Resources res = getResources();	// resを取得.
        TypedArray mixedarray = res.obtainTypedArray(R.array.mixedarray);	// mixedarrayの取得.
        Log.d(TAG, mixedarray.toString());	// mixedarrayを出力.
      
    }
  
}

