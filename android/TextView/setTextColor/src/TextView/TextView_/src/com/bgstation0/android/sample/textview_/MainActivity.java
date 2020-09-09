package com.bgstation0.android.sample.textview_;

import android.app.Activity;
import android.graphics.Color;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.TextView;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        // TextViewオブジェクトのインスタンスを作成し, "TextView.setText"とテキストをセットし, それをビューにセット.
        //setContentView(R.layout.activity_main);	// この部分はコメントアウト.
        TextView tv = new TextView(this);	// TextViewオブジェクトのインスタンスをtvに格納.
        tv.setTextColor(Color.RED);	// tv.setTextColorでColor.REDをセット.
        tv.setText("TextView.setText");	// tv.setTextで"TextView.setText"をセット.
        setContentView(tv);	// setContentViewでビューにtvをセット.
    }
}
