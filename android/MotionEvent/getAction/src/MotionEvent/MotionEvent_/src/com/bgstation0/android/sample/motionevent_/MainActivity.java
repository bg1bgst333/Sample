package com.bgstation0.android.sample.motionevent_;

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
    
    	// イベントのチェック.
    	int action = event.getAction();	// event.getActionでactionを取得.
    	if (action == MotionEvent.ACTION_DOWN){	// 押された時.
    		Toast.makeText(this, "ACTION_DOWN", Toast.LENGTH_LONG).show();	// "ACTION_DOWN"と表示.
    	}
    	else if (action == MotionEvent.ACTION_MOVE){	// 押したまま移動した時.
    		Toast.makeText(this, "ACTION_MOVE", Toast.LENGTH_LONG).show();	// "ACTION_MOVE"と表示.
    	}
    	else if (action == MotionEvent.ACTION_UP){	// 指を離した時.
    		Toast.makeText(this, "ACTION_UP", Toast.LENGTH_LONG).show();	// "ACTION_UP"と表示.
    	}
    	
        return true;	// 処理したのでtrueを返す.
        
    }
    
}
