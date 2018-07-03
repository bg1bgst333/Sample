package com.bgstation0.android.sample.resources_;

import android.app.Activity;
import android.content.res.Resources;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.TextView;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // リソース名(フル)を取得して, TextViewにセット.
        Resources resources = getResources();	// resourcesを取得.
        TextView tv1 = (TextView)findViewById(R.id.textview1);	// tv1を取得.
        String entryName1 = resources.getResourceEntryName(R.id.textview1);	// resources.getResourceEntryNameでR.id.textview1のエントリ名を取得.
        tv1.setText("tv1: " + entryName1);	// entryName1をセット.
        TextView tv2 = (TextView)findViewById(R.id.textview2);	// tv2を取得.
        String entryName2 = resources.getResourceEntryName(android.R.id.text1);	// resources.getResourceEntryNameでandroid.R.id.text1のエントリ名を取得.
        tv2.setText("tv2: " + entryName2);	// entryName2をセット.
        
    }
}