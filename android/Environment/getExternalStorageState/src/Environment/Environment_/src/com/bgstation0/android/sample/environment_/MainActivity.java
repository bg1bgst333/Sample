package com.bgstation0.android.sample.environment_;

import android.app.Activity;
import android.os.Bundle;
import android.os.Environment;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.Toast;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // 内部ストレージの状態を取得する.
        String state = Environment.getExternalStorageState();	// Environment.getExternalStorageStateで内部ストレージの状態を取得.
        Toast.makeText(this, state, Toast.LENGTH_LONG).show();	// Toastでstateを表示.        
    }
}
