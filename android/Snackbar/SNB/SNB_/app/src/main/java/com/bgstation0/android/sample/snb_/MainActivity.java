package com.bgstation0.android.sample.snb_;

import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.RelativeLayout;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {	// View.OnClickListenerを実装.

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // button1を取得し, OnClickListenerとして自身をセット.
        Button button1 = (Button)findViewById(R.id.button1);	// button1を取得.
        button1.setOnClickListener(this);	// button1.setOnClickListenerでthisをセット.
    }

    // View.OnClickListenerインタフェースのオーバーライドメソッドを実装.
    public void onClick(View v) {    // onClickをオーバーライド.

        // ボタンのidをごとに処理を振り分ける.
        switch (v.getId()) {    // v.getIdでView(Button)のidを取得.

            case R.id.button1:    // R.id.button1の時.

                // スナックバーを表示.
                RelativeLayout rl = (RelativeLayout) findViewById(R.id.activity_main);   // RelativeLayoutオブジェクトrlを取得.
                Snackbar.make(rl, "Snackbar", Snackbar.LENGTH_LONG).show(); // Snackbarで"Snackbar"と表示.

                // 抜ける.
                break;    // breakで抜ける.

        }

    }

}