package com.bgstation0.android.sample.accountmanager_;

import android.accounts.AccountManager;
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
        
        // AccountManagerオブジェクトを取得して, それを表示.
        Toast.makeText(this, AccountManager.get(this).toString(), Toast.LENGTH_LONG).show();	// AccountManager.get(this)をトースト表示.
        
    }
    
}