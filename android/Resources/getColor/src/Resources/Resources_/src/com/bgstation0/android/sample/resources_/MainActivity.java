package com.bgstation0.android.sample.resources_;

import android.app.Activity;
import android.content.res.Resources;
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
        
        // colors.xmlから色を取得して, Buttonの背景にセット.
        Resources res = getResources();	// getResourcesでresを取得.
        int red = res.getColor(R.color.red);	// res.getColorでR.color.redの色情報を取得.
        Button button1 = (Button)findViewById(R.id.button1);	// button1を取得.
        button1.setBackgroundColor(red);	// setBackgroundColorでredをセット.
        int green = res.getColor(R.color.green);	// res.getColorでR.color.greenの色情報を取得.
        Button button2 = (Button)findViewById(R.id.button2);	// button2を取得.
        button2.setBackgroundColor(green);	// setBackgroundColorでgreenをセット.
        int blue = res.getColor(R.color.blue);	// res.getColorでR.color.blueの色情報を取得.
        Button button3 = (Button)findViewById(R.id.button3);	// button3を取得.
        button3.setBackgroundColor(blue);	// setBackgroundColorでblueをセット.       
    }
}
