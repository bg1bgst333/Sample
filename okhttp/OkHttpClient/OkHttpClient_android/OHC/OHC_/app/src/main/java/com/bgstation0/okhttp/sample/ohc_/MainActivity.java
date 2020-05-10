package com.bgstation0.okhttp.sample.ohc_;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;

public class MainActivity extends AppCompatActivity {

    // メンバフィールドの定義
    CustomAsyncTask mTask = null;	// CustomAsyncTaskオブジェクトmTaskをnullで初期化.

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // CustomAsyncTaskの生成と実行.
        mTask = new CustomAsyncTask(this);	// CustomAsyncTaskオブジェクトを作成しmTaskに格納.
        mTask.execute("http://bgstation0.com/");	// "http://bgstation0.com/"を渡して実行.

    }

}