package com.bgstation0.android.sample.activity_;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.Button;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        
        // Buttonオブジェクトのインスタンスを作成し, それをビューにセット.
        //setContentView(R.layout.activity_main);	// この部分はコメントアウト.
        Button button = new Button(this);	// Buttonオブジェクトのインスタンスをbuttonに格納.
        setContentView(button);	// setContentViewでビューにbuttonをセット.
    }
}
