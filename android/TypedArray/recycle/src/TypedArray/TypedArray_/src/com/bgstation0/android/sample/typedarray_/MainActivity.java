package com.bgstation0.android.sample.typedarray_;

import android.app.Activity;
import android.content.res.Resources;
import android.content.res.TypedArray;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.TextView;

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
        int i = mixedarray.getInt(0, -1);	// mixedarray.getIntで0番目の整数を取得.
        Log.d(TAG, "i = " + i);	// iを出力.
        String s = mixedarray.getString(1);	// mixedarray.getStringで1番目の文字列を取得.
        Log.d(TAG, "s = " + s);	// sを出力.
        int c = mixedarray.getColor(2, -1);	// mixedarray.getColorで2番目の色コードを取得.
        Log.d(TAG, "c = " + c);	// cを出力.
        TextView textview1 = (TextView)findViewById(R.id.textview1);	// textview1を取得.
        textview1.setTextColor(c);	// textview1.setTextColorにcをセット.
        Log.d(TAG, "recycle.before");	// before
        mixedarray.recycle();	// mixedarray.recycleで終了処理.
        Log.d(TAG, "recycle.after");	// array
        
    }
  
}
