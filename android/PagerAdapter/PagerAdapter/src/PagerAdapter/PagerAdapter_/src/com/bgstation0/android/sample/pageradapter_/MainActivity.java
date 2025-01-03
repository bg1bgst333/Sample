package com.bgstation0.android.sample.pageradapter_;

import android.app.Activity;
import android.os.Bundle;
import android.support.v4.view.ViewPager;
import android.view.Menu;
import android.view.MenuItem;

public class MainActivity extends Activity {

	// メンバフィールドの定義.
	ViewPager viewpager = null;	// ViewPagerオブジェクトviewpagerをnullに初期化.
	
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // CustomPagerAdapterを生成.
        CustomPagerAdapter adapter = new CustomPagerAdapter(this);	// CustomPagerAdapterオブジェクトadapterを生成.
        PageItem item1 = new PageItem();	// PageItemオブジェクトitem1を生成.
        item1.name = "Taro";	// "Taro"
        item1.num = 10;	// 10
        PageItem item2 = new PageItem();	// PageItemオブジェクトitem2を生成.
        item2.name = "Jiro";	// "Jiro"
        item2.num = 20;	// 20
        PageItem item3 = new PageItem();	// PageItemオブジェクトitem3を生成.
        item3.name = "Saburo";	// "Saburo"
        item3.num = 30;	// 30
        adapter.add(item1);	// adapterにitem1を追加.
        adapter.add(item2);	// adapterにitem2を追加.
        adapter.add(item3);	// adapterにitem3を追加.
        
        // ViewPagerに反映.
        viewpager = (ViewPager)this.findViewById(R.id.viewpager);	// viewpagerを取得.
        viewpager.setAdapter(adapter);	// viewpager.setAdapterでadapterをセット.
        
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
    	
    		// menu_item_removeの時.
    		case R.id.menu_item_remove:
    			
    			// menu_item_removeブロック
    			{
    				
    				// アダプタを取得し, そこからアイテムを削除.
    				CustomPagerAdapter adapter = (CustomPagerAdapter)viewpager.getAdapter();	// viewpager.getAdapterでadapterを取得.
    				adapter.remove(viewpager.getCurrentItem());	// viewpager.getCurrentItemで現在表示しているアイテムの位置をインデックスを取得し, それをadapter.removeに指定することで現在のアイテムを削除.
    				adapter.notifyDataSetChanged();	// 更新.
    				
    			}
    		
    			// 抜ける.
    			break;	// breakで抜ける.
    		
    	}
    	
    	return super.onOptionsItemSelected(item);	// 親クラス既定処理
    	
    }
    
}