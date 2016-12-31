package com.bgstation0.android.sample.color_;

import android.app.Activity;
import android.graphics.Color;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.Button;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // Buttonに赤緑青をセット.
        Button button1 = (Button)findViewById(R.id.button1);	// button1を取得.
        button1.setBackgroundColor(Color.RED);	// button1.setBackgroundColorでColor.REDをセット.
        Button button2 = (Button)findViewById(R.id.button2);	// button2を取得.
        button2.setBackgroundColor(Color.GREEN);	// button2.setBackgroundColorでColor.GREENをセット.
        Button button3 = (Button)findViewById(R.id.button3);	// button3を取得.
        button3.setBackgroundColor(Color.BLUE);	// button3.setBackgroundColorでColor.BLUEをセット.
    }
}
