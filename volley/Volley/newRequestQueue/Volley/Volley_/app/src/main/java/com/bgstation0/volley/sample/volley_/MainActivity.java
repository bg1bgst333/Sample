package com.bgstation0.volley.sample.volley_;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

import com.android.volley.Request;
import com.android.volley.RequestQueue;
import com.android.volley.Response;
import com.android.volley.VolleyError;
import com.android.volley.toolbox.StringRequest;
import com.android.volley.toolbox.Volley;

public class MainActivity extends AppCompatActivity {

    // メンバフィールドの定義.
    final String TAG = getClass().getName();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // リクエストキューの作成.
        RequestQueue queue = Volley.newRequestQueue(this);  // queueの作成.

        // textView1の取得.
        final TextView textView1 = findViewById(R.id.textview1);  // textView1を取得.

        // 文字列リクエストの作成.
        StringRequest request = new StringRequest(Request.Method.GET, "http://bgstation0.com/", new Response.Listener<String>() {
            @Override
            public void onResponse(String response) {
                textView1.setText(response);    // textView1にセット.
            }
        },
        new Response.ErrorListener() {
            @Override
            public void onErrorResponse(VolleyError error) {    // エラー処理
                Log.d(TAG, error.getMessage()); // エラーメッセージをログ出力.
            }
        });

        // queueにrequestを追加.
        queue.add(request); // queueにrequestを追加.

    }

}