package com.bgstation0.android.sample.viewgroup_;

import android.app.Activity;
import android.app.ActivityGroup;
import android.app.LocalActivityManager;
import android.content.Intent;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;
import android.view.Window;
import android.widget.Toast;

public class MainActivity extends ActivityGroup {

	// メンバフィールドの定義.
	LocalActivityManager lam = null;
	
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // LocalActivityManagerの取得.
        lam = getLocalActivityManager();	// lamの取得.
        
        // SubActivityのIntent作成.
        Intent intent1 = new Intent(this, SubActivity.class);	// intent1作成.
        intent1.putExtra("tag", "test1");	// キーに"tag", 値に"test1".
        // Windowの取得.
        Window window1 = lam.startActivity("test1", intent1);	// intent1を渡して, window1の取得.
        View decorView1 = window1.getDecorView();	// window1.getDecorViewでdecorView1を取得.
        //Toast.makeText(this, "decorView1 = " + decorView1.toString(), Toast.LENGTH_LONG).show();	// decorView1を出力.
        ViewGroup vg1 = (ViewGroup)decorView1;	// ViewGroupのvg1にキャスト.
        //Toast.makeText(this, "vg1.getChildCount() = " + vg1.getChildCount(), Toast.LENGTH_LONG).show();	// vg1.getChildCountを出力.
        View childView1 = vg1.getChildAt(0);	// vg1.getChildAt(0)で子ビューを取得.
        //Toast.makeText(this, "childView1.toString() = " + childView1.toString(), Toast.LENGTH_LONG).show();	// childView1.toString()を出力.
        ViewGroup vgChild1 = (ViewGroup)childView1;	// ViewGroupのvgChild1にキャスト.
        Toast.makeText(this, "vgChild1.getChildCount() = " + vgChild1.getChildCount(), Toast.LENGTH_LONG).show();	// vgChild1.getChildCount()を出力.
        
        // SubActivityのIntent作成.
        Intent intent2 = new Intent(this, SubActivity.class);	// intent2作成.
        intent2.putExtra("tag", "test2");	// キーに"tag", 値に"test2".
        // Windowの取得.
        Window window2 = lam.startActivity("test2", intent2);	// intent2を渡して, window2の取得.
        View decorView2 = window2.getDecorView();	// window2.getDecorViewでdecorView2を取得.
        //Toast.makeText(this, "decorView2 = " + decorView2.toString(), Toast.LENGTH_LONG).show();	// decorView2を出力.
        ViewGroup vg2 = (ViewGroup)decorView2;	// ViewGroupのvg2にキャスト.
        //Toast.makeText(this, "vg2.getChildCount() = " + vg2.getChildCount(), Toast.LENGTH_LONG).show();	// vg2.getChildCountを出力.
        View childView2 = vg2.getChildAt(0);	// vg2.getChildAt(0)で子ビューを取得.
        //Toast.makeText(this, "childView2.toString() = " + childView2.toString(), Toast.LENGTH_LONG).show();	// childView2.toString()を出力.
        ViewGroup vgChild2 = (ViewGroup)childView2;	// ViewGroupのvgChild2にキャスト.
        Toast.makeText(this, "vgChild2.getChildCount() = " + vgChild2.getChildCount(), Toast.LENGTH_LONG).show();	// vgChild2.getChildCount()を出力.
        
        // SubActivityのIntent作成.
        //Intent intent1b = new Intent(this, SubActivity.class);	// intent1b作成.
        //intent1b.putExtra("tag", "test1");	// キーに"tag", 値に"test1".
        // Windowの取得.
        //Window window1b = lam.startActivity("test1", intent1b);	// intent1bを渡して, window1bの取得.

        // window1とwindow1bが同じかどうかチェック.
        //Toast.makeText(this, "window1.toString() = " + window1.toString(), Toast.LENGTH_LONG).show();	// window1.toStringの出力.
        //Toast.makeText(this, "window1b.toString() = " + window1b.toString(), Toast.LENGTH_LONG).show();	// window1b.toStringの出力.
        //if (window1 == window1b){	// window1とwindow1bが同じなら.
        //	Toast.makeText(this, "window1 == window1b !", Toast.LENGTH_LONG).show();	// 同じなら"window1 == window1b !"を出力.
        //}
        
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
								        
				}
				
				break;
			
			// TextView1
    		case R.id.menu_textview2:
    			
    			// TextView2ブロック
				{
	
				}
				
				break;
				
    	}
    	return super.onOptionsItemSelected(item);	// 親クラス既定処理
    	
    }
    
}