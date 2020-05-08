package com.bgstation0.android.sample.androidhttpclient_;

import java.io.BufferedReader;
import java.io.InputStreamReader;

import org.apache.http.HttpResponse;
import org.apache.http.client.methods.HttpGet;

import android.app.Activity;
import android.content.Context;
import android.net.http.AndroidHttpClient;
import android.os.AsyncTask;
import android.util.Log;
import android.widget.TextView;

// カスタムアシンクタスク
public class CustomAsyncTask extends AsyncTask<String, Void, String> {	// 非同期処理CustomAsyncTask.

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
		
		// TODO Auto-generated method stub
		// リクエスト作成とレスポンスの取得.
		try{
			String url = params[0];	// 0番目の文字列はURL.
			AndroidHttpClient httpClient = AndroidHttpClient.newInstance("bgst");	// インスタンス生成.
			HttpResponse httpResponse = httpClient.execute(new HttpGet(url));	// urlを渡したHttpGetをexecuteで実行.
			BufferedReader reader = new BufferedReader(new InputStreamReader(httpResponse.getEntity().getContent(), "UTF-8"));	// reader取得.
			StringBuffer sb = new StringBuffer();	// バッファ生成.
			String line = null;	// lineはnullで初期化.
			while ((line = reader.readLine()) != null){	// 行読み込みを繰り返す.
				sb.append(line + "\n");	// 行を追加.
			}
			return sb.toString();	// 文字列にして返す.
		}
		catch (Exception ex){	// 例外をキャッチ.
			Log.d(TAG, ex.getMessage());	// エラーログ出力.
			return "";	// ""を返す.
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