package com.bgstation0.android.sample.contextcompat_;

import android.Manifest;
import android.app.Activity;
import android.content.Context;
import android.content.pm.PackageManager;
import android.os.Bundle;
import android.support.v4.content.ContextCompat;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

// メインアクティビティクラスMainActivity(View.OnClickListenerを実装.)
public class MainActivity extends Activity implements View.OnClickListener {

    // メンバフィールドの定義
    Context mContext = null;	// mContextをnullで初期化.

    // アクティビティ生成時
    @Override
    protected void onCreate(Bundle savedInstanceState) {

        // 既定の処理
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // mContextに自身をセット.
        mContext = this;	// mContextにthisを格納.

        // button1の初期化.
        Button button1 = (Button)findViewById(R.id.button1);	// button1を取得.
        button1.setOnClickListener(this);	// thisをセット.

    }

    // クリック時
    @Override
    public void onClick(View v) {

        // ACCESS_FINE_LOCATIONのパーミッション確認.
        if (ContextCompat.checkSelfPermission(mContext, Manifest.permission.ACCESS_FINE_LOCATION) == PackageManager.PERMISSION_GRANTED){    // 許可.
            Toast.makeText(mContext, "ACCESS_FINE_LOCATION PERMISSION_GRANTED", Toast.LENGTH_LONG).show();  // "ACCESS_FINE_LOCATION PERMISSION_GRANTED"と表示.
        }
        else{   // 拒否.
            Toast.makeText(mContext, "ACCESS_FINE_LOCATION Not PERMISSION_GRANTED", Toast.LENGTH_LONG).show();  // "ACCESS_FINE_LOCATION Not PERMISSION_GRANTED"と表示.
        }

    }

}