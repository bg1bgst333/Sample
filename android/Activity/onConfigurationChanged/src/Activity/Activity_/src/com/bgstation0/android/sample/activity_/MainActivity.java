package com.bgstation0.android.sample.activity_;

import android.app.Activity;
import android.content.res.Configuration;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.Toast;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // "onCreate"に来たらトースト表示.
        Toast.makeText(this, "onCreate", Toast.LENGTH_LONG).show();	// "onCreate"と表示.
        
    }
    
    // 設定変更が発生した時.(回転など.)
    @Override
    public void onConfigurationChanged(Configuration newConfig){
    	
    	// 親クラスの既定処理.
    	super.onConfigurationChanged(newConfig);	// super.onConfigurationChangedにnewConfigを渡す.
    	
    	// "onConfigurationChanged"に来たらトースト表示.
    	Toast.makeText(this, "onConfigurationChanged", Toast.LENGTH_LONG).show();	// "onConfigurationChanged"と表示.
    	
    }
    
}