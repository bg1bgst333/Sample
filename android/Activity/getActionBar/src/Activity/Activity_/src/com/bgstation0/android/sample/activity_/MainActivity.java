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
        
        // アクションバーのタイトルを取得してタイトルをトースト表示.
        Toast.makeText(this, "getActionBar().getTitle() = " + getActionBar().getTitle(), Toast.LENGTH_LONG).show();	// getActionBar().getTitle()で取得したタイトルを表示.
        
    }
}
