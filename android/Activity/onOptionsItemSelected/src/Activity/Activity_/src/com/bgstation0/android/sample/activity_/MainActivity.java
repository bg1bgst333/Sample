package com.bgstation0.android.sample.activity_;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.Toast;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }
    
    // オプションメニューが作成される時.
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
    	
    		// Menu1
    		case R.id.menu_menu1:
    			
    			// "Menu1"と表示.
    			Toast.makeText(this, "Menu1", Toast.LENGTH_SHORT).show();	// Toastで"Menu1"を表示.
    			break;
    			
    		// Menu2
    		case R.id.menu_menu2:
    			
    			// "Menu2"と表示.
    			Toast.makeText(this, "Menu2", Toast.LENGTH_SHORT).show();	// Toastで"Menu2"を表示.
    			break;
    			
    		// Menu3
    		case R.id.menu_menu3:
    			
    			// "Menu3"と表示.
    			Toast.makeText(this, "Menu3", Toast.LENGTH_SHORT).show();	// Toastで"Menu3"を表示.
    			break;
    			
    	}
    	return super.onOptionsItemSelected(item);	// 親クラス既定処理
    }
}
