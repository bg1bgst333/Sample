package com.bgstation0.android.sample.activity_;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.MotionEvent;
import android.widget.Toast;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }
    
    // タッチイベントが発生した時.
    @Override
    public boolean onTouchEvent(MotionEvent event){
    
    	// "onTouchEvent"の表示.
        Toast.makeText(this, "onTouchEvent", Toast.LENGTH_LONG).show();	// Toastで"onTouchEvent"を表示.
        return true;	// 処理したのでtrueを返す.
        
    }
    
}