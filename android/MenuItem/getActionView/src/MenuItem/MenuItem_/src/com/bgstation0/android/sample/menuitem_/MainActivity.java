package com.bgstation0.android.sample.menuitem_;

import android.app.ActionBar;
import android.app.Activity;
import android.content.Context;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.LinearLayout;
import android.widget.Toast;

public class MainActivity extends Activity {

	// メンバフィールドの定義.
	Context mContext = null;	// mContextをnullに初期化.
		
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        mContext = this;	// mContextにthisをセット.
    }
    
    // メニューが作成された時.
    @Override
    public boolean onCreateOptionsMenu(Menu menu){
    	
    	// メニューの作成
    	getMenuInflater().inflate(R.menu.main, menu);	// getMenuInflaterでMenuItemを取得し, そのままinflateで指定されたR.menu.mainを元にmenuを作成.
    	ActionBar actionBar = getActionBar();	// getActionBarでactionBarを取得.
    	actionBar.setDisplayShowTitleEnabled(false);	// actionBar.setDisplayShowTitleEnabledをfalseにしてタイトルを非表示.
    	actionBar.setDisplayShowHomeEnabled(false);	// actionBar.setDisplayShowHomeEnabledをfalseにしてアイコンも非表示.
    	
    	// アクションビューの取得.
    	MenuItem menuItemSearch = menu.findItem(R.id.menu_item_search_layout);	// menuItemSearchの取得.
    	LinearLayout searchRoot = (LinearLayout)menuItemSearch.getActionView();	// getActionViewでsearchRoot取得.
    	Button closeButton = (Button)searchRoot.findViewById(R.id.search_close_button);	// closeButton取得.
    	closeButton.setOnClickListener(new OnClickListener(){
    		@Override
    		public void onClick(View v){
    			Toast.makeText(mContext, "Close Clicked!", Toast.LENGTH_LONG).show();	// "Close Clicked!"を表示.
    		}
    	});
    	return true;
    	
    }
    
}