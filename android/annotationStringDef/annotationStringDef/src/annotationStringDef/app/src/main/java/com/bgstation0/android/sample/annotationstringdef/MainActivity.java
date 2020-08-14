package com.bgstation0.android.sample.annotationstringdef;

import android.support.annotation.StringDef;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;

public class MainActivity extends AppCompatActivity {

    // @StringDef
    @StringDef({FIRST, SECOND, THIRD})
    @Retention(RetentionPolicy.SOURCE)
    public @interface Three{};
    static final String FIRST = "first";
    static final String SECOND = "second";
    static final String THIRD = "third";

    // 生成時
    @Override
    protected void onCreate(Bundle savedInstanceState) {

        // 既定の処理.
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // 値を取得してセット.
        String str = getThree("hoge");   // getThreeで"hoge".
        TextView textView1 = findViewById(R.id.textview1);   // textViewを取得.
        textView1.setText(str); // strをセット.

    }

    // 引数に合う文字列を取得.
    String getThree(@Three String three){
        if (three == FIRST){
            return "one";
        }
        else if (three == SECOND){
            return "two";
        }
        else if (three == THIRD){
            return "three";
        }
        else{
            return "error";
        }
    }

}