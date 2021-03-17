package com.bgstation0.android.sample.toolbar_;

import android.app.Activity;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.Toolbar;

public class MainActivity extends /*AppCompatActivity*/ Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // ツールバーのセット.
        Toolbar toolbar1 = findViewById(R.id.toolbar1); // toolbar1を取得.
        toolbar1.setLogo(R.mipmap.logo1);   // logo1をセット.
        setActionBar(toolbar1); // setActionBarでtoolbar1をセット.
    }
}
