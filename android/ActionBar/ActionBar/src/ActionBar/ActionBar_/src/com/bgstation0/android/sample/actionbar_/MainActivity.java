package com.bgstation0.android.sample.actionbar_;

import android.app.ActionBar;
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
        
        // ActionBarを取得.
        ActionBar actionBar = getActionBar();	// getActionBarでActionBarオブジェクトactionBarを取得.
        if (actionBar == null){	// actionBarがnullなら.
        	// "actionBar is null!"と表示.
        	Toast.makeText(this, "actionBar is null!", Toast.LENGTH_SHORT).show();	// Toastで"actionBar is null!"を表示.
        }
        else{	// 取得できた場合.
        	actionBar.setTitle("Exist actionBar!!");	// actionBar.setTitleでタイトルを"Exist actionBar!!"に変更.
        }
    }
}
