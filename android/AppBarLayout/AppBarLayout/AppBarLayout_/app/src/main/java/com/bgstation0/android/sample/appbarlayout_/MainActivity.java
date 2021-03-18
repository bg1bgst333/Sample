package com.bgstation0.android.sample.appbarlayout_;

import android.app.Activity;
import android.content.Context;
import android.graphics.Color;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;
import android.widget.Toolbar;

public class MainActivity extends /*AppCompatActivity*/ Activity {

    // メンバフィールドの定義.
    Context mContext = null;    // mContextをnullで初期化.

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // ツールバーのセット.
        Toolbar toolbar1 = findViewById(R.id.toolbar1); // toolbar1を取得.
        toolbar1.setLogo(R.mipmap.logo1);   // logo1をセット.
        toolbar1.setTitle(R.string.title_string);   // title_stringをセット.
        toolbar1.setSubtitle(R.string.subtitle_string); // subtitle_stringをセット.
        setActionBar(toolbar1); // setActionBarでtoolbar1をセット.

        // ボタンの初期化.
        mContext = this;    // mContextにthisをセット.
        Button button1 = findViewById(R.id.button1);    // button1を取得.
        button1.setOnClickListener(new View.OnClickListener() { // クリックリスナーのセット.
            @Override
            public void onClick(View v) {
                Toast.makeText(mContext, "Button1 Clicked!", Toast.LENGTH_LONG).show(); // "Button1 Clicked!"を表示.
            }
        });

    }

}