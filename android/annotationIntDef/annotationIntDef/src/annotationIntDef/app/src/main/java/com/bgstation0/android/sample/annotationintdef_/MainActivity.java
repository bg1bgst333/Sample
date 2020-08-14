package com.bgstation0.android.sample.annotationintdef_;

import android.support.annotation.IntDef;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;

public class MainActivity extends AppCompatActivity {

    // 列挙型
    //public enum THREE{
    //    FIRST, SECOND, THRID
    //}

    // 定数
    //static final int FIRST = 1;
    //static final int SECOND = 2;
    //static final int THIRD = 3;

    // @IntDef
    @IntDef({FIRST, SECOND, THIRD})
    @Retention(RetentionPolicy.SOURCE)
    public @interface Three {};
    static final int FIRST = 1;
    static final int SECOND = 2;
    static final int THIRD = 3;

    // 生成時
    @Override
    protected void onCreate(Bundle savedInstanceState) {

        // 既定の処理.
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // 値を取得してセット.
        int num = getThree(10);   // getThreeに10.
        TextView textView1 = findViewById(R.id.textview1);   // textViewを取得.
        String text = Integer.toString(num);    // numをtextに変換.
        textView1.setText(text); // textをセット.

    }

    // 引数に合う値を取得.
    int getThree(@Three int three){
        if (three == FIRST){
            return 1;
        }
        else if (three == SECOND){
            return 2;
        }
        else if (three == THIRD){
            return 3;
        }
        else{
            return -1;
        }
    }

}