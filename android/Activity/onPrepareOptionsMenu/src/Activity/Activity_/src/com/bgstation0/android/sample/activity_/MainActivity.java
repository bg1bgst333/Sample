package com.bgstation0.android.sample.activity_;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;

public class MainActivity extends Activity {

	// メンバフィールドの定義.
	final int MENU_TYPE_A = 0;	// 定数MENU_TYPE_Aを0とする.
	final int MENU_TYPE_B = 1;	// 定数MENU_TYPE_Bを1とする.
	int menuType = MENU_TYPE_A;	// menuTypeをMENU_TYPE_Aで初期化.
	
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }
    
    // メニューが作成された時.
    @Override
    public boolean onCreateOptionsMenu(Menu menu){
    	
    	// メニューの作成
    	getMenuInflater().inflate(R.menu.main, menu);	// getMenuInflaterでMenuItemを取得し, そのままinflateで指定されたR.menu.mainを元にmenuを作成.
    	
    	// 最初は"Change"と"A1"～"A3"だけ表示であとは非表示.
    	MenuItem itemB1 = menu.findItem(R.id.menu_item_b1);	// menu.findItemでitemB1を取得.
    	itemB1.setVisible(false);	// itemB1.setVisibleで非表示にする.
    	MenuItem itemB2 = menu.findItem(R.id.menu_item_b2);	// menu.findItemでitemB2を取得.
    	itemB2.setVisible(false);	// itemB2.setVisibleで非表示にする.
    	MenuItem itemB3 = menu.findItem(R.id.menu_item_b3);	// menu.findItemでitemB3を取得.
    	itemB3.setVisible(false);	// itemB3.setVisibleで非表示にする.
    	
    	// trueを返す.
    	return true;	// trueを返す.
    	
    }
    
    // メニューの表示のための準備が行われた時.
    @Override
    public boolean onPrepareOptionsMenu(Menu menu) {
    
    	// menuTypeによって表示を切り替え.
    	if (menuType == MENU_TYPE_A){	// MENU_TYPE_Aなら.
    		MenuItem itemB1 = menu.findItem(R.id.menu_item_b1);	// menu.findItemでitemB1を取得.
        	itemB1.setVisible(false);	// itemB1.setVisibleで非表示にする.
        	MenuItem itemB2 = menu.findItem(R.id.menu_item_b2);	// menu.findItemでitemB2を取得.
        	itemB2.setVisible(false);	// itemB2.setVisibleで非表示にする.
        	MenuItem itemB3 = menu.findItem(R.id.menu_item_b3);	// menu.findItemでitemB3を取得.
        	itemB3.setVisible(false);	// itemB3.setVisibleで非表示にする.
    		MenuItem itemA1 = menu.findItem(R.id.menu_item_a1);	// menu.findItemでitemA1を取得.
        	itemA1.setVisible(true);	// itemA1.setVisibleで表示にする.
        	MenuItem itemA2 = menu.findItem(R.id.menu_item_a2);	// menu.findItemでitemA2を取得.
        	itemA2.setVisible(true);	// itemA2.setVisibleで表示にする.
        	MenuItem itemA3 = menu.findItem(R.id.menu_item_a3);	// menu.findItemでitemA3を取得.
        	itemA3.setVisible(true);	// itemA3.setVisibleで表示にする.
    	}
    	else{	// MENU_TYPE_Bなら.
    		MenuItem itemA1 = menu.findItem(R.id.menu_item_a1);	// menu.findItemでitemA1を取得.
        	itemA1.setVisible(false);	// itemA1.setVisibleで非表示にする.
        	MenuItem itemA2 = menu.findItem(R.id.menu_item_a2);	// menu.findItemでitemA2を取得.
        	itemA2.setVisible(false);	// itemA2.setVisibleで非表示にする.
        	MenuItem itemA3 = menu.findItem(R.id.menu_item_a3);	// menu.findItemでitemA3を取得.
        	itemA3.setVisible(false);	// itemA3.setVisibleで非表示にする.
        	MenuItem itemB1 = menu.findItem(R.id.menu_item_b1);	// menu.findItemでitemB1を取得.
        	itemB1.setVisible(true);	// itemB1.setVisibleで表示にする.
        	MenuItem itemB2 = menu.findItem(R.id.menu_item_b2);	// menu.findItemでitemB2を取得.
        	itemB2.setVisible(true);	// itemB2.setVisibleで表示にする.
        	MenuItem itemB3 = menu.findItem(R.id.menu_item_b3);	// menu.findItemでitemB3を取得.
        	itemB3.setVisible(true);	// itemB3.setVisibleで表示にする.
    	}
    	
    	// trueを返す.
    	return true;	// trueを返す.
    	
    }
    
    // メニューアイテムが選択された時.
    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
    	
    	// itemがmenu_changeなら, menuTypeを切り替える.
    	if (item.getItemId() == R.id.menu_change){	// R.id.menu_changeなら.
	    	if (menuType == MENU_TYPE_A){	// MENU_TYPE_Aなら.
	    		menuType = MENU_TYPE_B;	// menuTypeにMENU_TYPE_Bを代入.
	    	}
	    	else{	// MENU_TYPE_Bなら.
	    		menuType = MENU_TYPE_A;	// menuTypeにMENU_TYPE_Aを代入.
	    	}
    	}
    	
    	// trueを返す.
    	return true;	// trueを返す.
    	
    }
    
}