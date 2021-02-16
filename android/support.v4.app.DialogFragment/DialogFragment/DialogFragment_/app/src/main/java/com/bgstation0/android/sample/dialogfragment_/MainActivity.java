package com.bgstation0.android.sample.dialogfragment_;

import android.content.Context;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

// メインアクティビティクラスMainActivity(View.OnClickListenerを実装.)
public class MainActivity extends AppCompatActivity implements View.OnClickListener {

    // メンバフィールドの定義
    private Context mContext = null;    // mContextをnullで初期化.
    public static final int CUSTOM_DIALOG_FRAGMENT_ID_1 = 1;    // CUSTOM_DIALOG_FRAGMENT_ID_1を1とする.
    public static final int CUSTOM_DIALOG_FRAGMENT_ID_2 = 2;    // CUSTOM_DIALOG_FRAGMENT_ID_2を12とする.

    // アクティビティ生成時
    @Override
    protected void onCreate(Bundle savedInstanceState) {

        // 既定の処理
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // mContextに自身をセット.
        mContext = this;    // mContextにthisを格納.

        // button1の初期化.
        Button button1 = (Button) findViewById(R.id.button1);    // button1を取得.
        button1.setOnClickListener(this);    // thisをセット.

    }

    // クリック時
    @Override
    public void onClick(View v) {

        // CustomDialogFragmentの表示.
        // CUSTOM_DIALOG_FRAGMENT_ID_1
        /*
        CustomDialogFragment customDialogFragment1 = new CustomDialogFragment(); // customDialogFragment1を生成.
        Bundle args1 = new Bundle(); // args1を用意.
        args1.putString("title", "title1");  // "title1"
        args1.putString("message", "message1");  // "message1"
        args1.putInt("id", CUSTOM_DIALOG_FRAGMENT_ID_1); // CUSTOM_DIALOG_FRAGMENT_ID_1
        customDialogFragment1.setArguments(args1);  // args1をセット.
        customDialogFragment1.show(getSupportFragmentManager(), "dialog1");   //  customDialogFragment1.showで表示.
        */
        // CUSTOM_DIALOG_FRAGMENT_ID_2
        CustomDialogFragment customDialogFragment2 = new CustomDialogFragment(); // customDialogFragment2を生成.
        Bundle args2 = new Bundle(); // args2を用意.
        args2.putString("title", "title2");  // "title2"
        args2.putString("message", "message2");  // "message2"
        args2.putInt("id", CUSTOM_DIALOG_FRAGMENT_ID_2); // CUSTOM_DIALOG_FRAGMENT_ID_2
        customDialogFragment2.setArguments(args2);  // args2をセット.
        customDialogFragment2.show(getSupportFragmentManager(), "dialog2");   //  customDialogFragment2.showで表示.

    }

    // フラグメントから呼ぶ関数.
    public void func(int id){

        // idごとに処理を振り分け.
        if (id == CUSTOM_DIALOG_FRAGMENT_ID_1){
            Toast.makeText(this, "CUSTOM_DIALOG_FRAGMENT_ID_1", Toast.LENGTH_LONG).show();  // "CUSTOM_DIALOG_FRAGMENT_ID_1"
        }
        else if (id == CUSTOM_DIALOG_FRAGMENT_ID_2){
            Toast.makeText(this, "CUSTOM_DIALOG_FRAGMENT_ID_2", Toast.LENGTH_LONG).show();  // "CUSTOM_DIALOG_FRAGMENT_ID_2"
        }

    }

}