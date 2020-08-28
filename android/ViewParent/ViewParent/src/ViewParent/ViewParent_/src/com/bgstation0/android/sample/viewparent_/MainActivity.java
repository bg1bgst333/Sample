package com.bgstation0.android.sample.viewparent_;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewParent;
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
		
		// textview1の親の親のViewを取得.
        TextView textview1 = (TextView)findViewById(R.id.textview1);	// textview1を取得.
        ViewParent viewParent1 = textview1.getParent();	// 親のviewParent1を取得.
        if (viewParent1 != null){	// nullでない.
        	View view1 = (View)viewParent1;	// Viewのview1にキャスト.
        	if (view1.getId() == R.id.layout_sub){	// IDがlayout_subなら.
        		Log.d(TAG, "layout_sub!");	// "layout_sub!"とログ出力.
        		ViewParent viewParent2 = viewParent1.getParent();	// さらに親のviewParent2を取得.
        		if (viewParent2 != null){	// nullでない.
        			View view2 = (View)viewParent2;	// view2を取得.
        			if (view2.getId() == R.id.layout_main){	// IDがlayout_mainなら.
        				Log.d(TAG, "layout_main!");	// "layout_main!"とログ出力.
        			}
        		}
        	}
        }
        
	}
    
}
