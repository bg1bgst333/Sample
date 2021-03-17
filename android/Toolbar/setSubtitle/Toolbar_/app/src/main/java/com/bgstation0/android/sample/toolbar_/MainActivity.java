package com.bgstation0.android.sample.toolbar_;

import android.app.Activity;
import android.graphics.Color;
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
        toolbar1.setTitle(R.string.title_string);   // title_stringをセット.
        toolbar1.setTitleTextColor(Color.RED);  // タイトルカラーは赤.
        toolbar1.setSubtitle(R.string.subtitle_string); // subtitle_stringをセット.
        setActionBar(toolbar1); // setActionBarでtoolbar1をセット.
    }
}
