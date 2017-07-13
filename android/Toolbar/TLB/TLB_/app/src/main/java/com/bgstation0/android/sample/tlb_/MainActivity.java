package com.bgstation0.android.sample.tlb_;

import android.app.Activity;
import android.os.Bundle;
import android.widget.Toolbar;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // ツールバーをアクションバーとしてセット.
        Toolbar toolbar = (Toolbar)findViewById(R.id.toolbar);  // toolbarを取得.
        setActionBar(toolbar);  // setActionBarでtoolbarをセット.
    }
}