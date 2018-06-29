package com.bgstation0.android.sample.activitygroup_;

import android.app.Activity;
import android.app.ActivityGroup;
import android.app.LocalActivityManager;
import android.content.Intent;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.Window;
import android.widget.FrameLayout;
import android.widget.TextView;

public class MainActivity extends ActivityGroup {

	// メンバフィールドの定義.
	LocalActivityManager lam = null;
	FrameLayout fl = null;
	
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // LocalActivityManagerの取得.
        lam = getLocalActivityManager();	// lamの取得.
        
        // FrameLayoutの取得.
        fl = (FrameLayout)findViewById(R.id.frame_main);	// flの取得.
        
        // SubActivityのIntent作成.
        Intent intent1 = new Intent(this, SubActivity.class);	// intent1作成.
        // Windowの取得.
        Window window1 = lam.startActivity("test1", intent1);	// intent1を渡して, window1の取得.
        // Viewの取得.
        View view1 = window1.getDecorView();	// view1を取得.
        // TextViewにテキストをセット.
        TextView tv1 = (TextView)view1.findViewById(R.id.textview1);	// tv1を取得.
        tv1.setText("TV1");	// "TV1"をセット.
        // Viewの追加.
        fl.addView(view1);	// fl.addViewでflにview1を追加.
        
    }
    
    // メニューが作成された時.
    @Override
    public boolean onCreateOptionsMenu(Menu menu){
    	
    	// メニューの作成
    	getMenuInflater().inflate(R.menu.main, menu);	// getMenuInflaterでMenuItemを取得し, そのままinflateで指定されたR.menu.mainを元にmenuを作成.
    	return true;	// trueを返す.
    	
    }
    
    // メニューが選択された時.
    @Override
    public boolean onOptionsItemSelected(MenuItem item){
    
    	// どのメニューが選択されたか.
    	switch (item.getItemId()){	// アイテムIDごとに振り分け.
    	
    		// TextView1
    		case R.id.menu_textview1:
    			
    			// TextView1ブロック
				{
					
					// flのビューを削除.
					fl.removeAllViews();	// fl.removeAllViewsでビューの全削除.
					// SubActivityのIntent作成.
			        Intent intent1 = new Intent(this, SubActivity.class);	// intent1作成.
			        // Windowの取得.
			        Window window1 = lam.startActivity("test1", intent1);	// intent1を渡して, window1の取得.
			        // Viewの取得.
			        View view1 = window1.getDecorView();	// view1を取得.
			        // TextViewにテキストをセット.
			        TextView tv1 = (TextView)view1.findViewById(R.id.textview1);	// tv1を取得.
			        tv1.setText("TV1");	// "TV1"をセット.
			        // Viewの追加.
			        fl.addView(view1);	// fl.addViewでflにview1を追加.
			        
				}
				
				break;
			
			// TextView1
    		case R.id.menu_textview2:
    			
    			// TextView2ブロック
				{
	
					// flのビューを削除.
					fl.removeAllViews();	// fl.removeAllViewsでビューの全削除.
					// SubActivityのIntent作成.
			        Intent intent2 = new Intent(this, SubActivity.class);	// intent2作成.
			        // Windowの取得.
			        Window window2 = lam.startActivity("test2", intent2);	// intent2を渡して, window2の取得.
			        // Viewの取得.
			        View view2 = window2.getDecorView();	// view2を取得.
			        // TextViewにテキストをセット.
			        TextView tv2 = (TextView)view2.findViewById(R.id.textview1);	// tv2を取得.
			        tv2.setText("TV2");	// "TV2"をセット.
			        // Viewの追加.
			        fl.addView(view2);	// fl.addViewでflにview2を追加.
					
				}
				
				break;
				
    	}
    	return super.onOptionsItemSelected(item);	// 親クラス既定処理
    	
    }
    
}