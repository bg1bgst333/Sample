package com.bgstation0.android.sample.resources_;

import android.app.Activity;
import android.content.res.Resources;
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
        
        // リソースから文字列配列の取得.
        Resources res = getResources();	// resを取得.
        String[] abcdefghi = res.getStringArray(R.array.abcdefghi);	// abcdefghiを取得.
        for (int i = 0; i < abcdefghi.length; i++){	// 長さの分繰り返す.
        	Log.d(TAG, "abcdefghi[" + i + "] = " + abcdefghi[i]);	// abcdefghi[i]を出力.
        }
        
    }
    
}
