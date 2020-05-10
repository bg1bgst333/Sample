package com.bgstation0.okhttp.sample.ohc_;

import android.app.Activity;
import android.content.Context;
import android.os.AsyncTask;
import android.widget.TextView;

import okhttp3.OkHttpClient;
import okhttp3.Request;
import okhttp3.Response;

// カスタムアシンクタスク
public class CustomAsyncTask extends AsyncTask<String, Void, String> {  // 非同期処理CustomAsyncTask.

    // メンバフィールドの定義
    final String TAG = getClass().getName();	// クラス名をタグにする.
    Context mContext = null;	// mContextをnullで初期化.

    // コンストラクタ
    public CustomAsyncTask(Context context){
        mContext = context;	// mContextにcontextをセット.
    }

    // 非同期処理
    @Override
    protected String doInBackground(String... params) {

        // tryで囲む
        try {

            // リクエストの作成.
            Request request = new Request.Builder().url(params[0]).get().build();    // requestを作成.

            // クライアントの作成.
            OkHttpClient client = new OkHttpClient();    // clientを作成.

            // レスポンスの取得.
            Response response = client.newCall(request).execute();    // requestを投げて, responseの取得.

            // レスポンスを返す.
            return response.body().string();

        }
        catch (Exception ex){   // 例外をキャッチ.

            return "";  // 空で返す.

        }

    }

    // UIスレッドの更新
    @Override
    protected void onPostExecute(String result){
        // textview1の更新
        Activity activity = (Activity)mContext;	// mContextをactivityにキャスト.
        TextView textView1 = (TextView)activity.findViewById(R.id.textview1);	// textview1を取得.
        textView1.setText(result);	// textview1.setTextにresultをセット.
    }

}