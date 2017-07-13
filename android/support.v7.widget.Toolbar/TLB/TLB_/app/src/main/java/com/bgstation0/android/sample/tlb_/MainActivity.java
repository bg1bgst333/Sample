package com.bgstation0.android.sample.tlb_;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.support.v7.widget.Toolbar;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // ツールバーをアクションバーとしてセット.
        Toolbar toolbar = (Toolbar)findViewById(R.id.toolbar);  // toolbarを取得.
        setSupportActionBar(toolbar);   // setSupportActionBarでtoolbarをセット.
    }
}
