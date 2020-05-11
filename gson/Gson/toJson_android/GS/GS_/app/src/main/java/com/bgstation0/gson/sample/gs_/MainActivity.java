package com.bgstation0.gson.sample.gs_;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

import com.google.gson.Gson;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {

        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // textView1の取得.
        TextView textView1 = findViewById(R.id.textview1);  // textView1を取得.

        // Profileオブジェクトの作成.
        Profile profile = new Profile("Taro", "taro@gmail.com");	// profileを作成し, "Taro"と"taro@gmail.com"をセット.

        // Gsonの生成.
        Gson gson = new Gson();	// gsonを生成.

        // JavaのProfileオブジェクトからJsonに変換してtextView1にセット.
        textView1.setText(gson.toJson(profile));    // gson.toJsonにprofileを渡して, 変換したものをtextView1にセット.

    }

}
