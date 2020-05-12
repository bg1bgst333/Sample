package com.bgstation0.icepick.sample.ip_;

import android.app.Activity;
import android.content.Context;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import icepick.Icepick;
import icepick.State;

public class MainActivity extends Activity {

    // メンバフィールドの定義
    @State
    String mText = null;    // mTextをnullで初期化.

    @Override
    public void onCreate(Bundle savedInstanceState) {

        // 既定の処理.
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Icepick.restoreInstanceState(this, savedInstanceState);

        // Buttonにリスナーをセット.
        Button button1 = findViewById(R.id.button1);    // button1を取得.
        button1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                mText = new String("ABCDE");    // mTextに"ABCDE"をセット.
            }
        });

        // mTextがあれば出力/.
        if (mText != null) {
            Toast.makeText(this, mText, Toast.LENGTH_LONG).show();
        }

    }

    @Override
    public void onSaveInstanceState(Bundle outState) {

        // 既定の処理.
        super.onSaveInstanceState(outState);

        // セーブ.
        Icepick.saveInstanceState(this, outState);

    }

}