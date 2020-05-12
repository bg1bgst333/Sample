package com.bgstation0.butterknife.sample.bk_;

import android.content.Context;
//import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;
import butterknife.ButterKnife;
import butterknife.OnClick;

public class MainActivity extends AppCompatActivity {

    // メンバフィールドの定義
    Context mContext = null;    // mContextをnullで初期化.

    @Override
    protected void onCreate(Bundle savedInstanceState) {

        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Buttonにリスナーをセット.
        mContext = this;    // mContextにthisをセット.

        // バインド.
        ButterKnife.bind(this); // thisをbind.

    }

    // クリックされた時.
    @OnClick(R.id.button1)
    public void onClick(View v) {
        Toast.makeText(mContext, "Clicked!", Toast.LENGTH_LONG).show();
    }

}