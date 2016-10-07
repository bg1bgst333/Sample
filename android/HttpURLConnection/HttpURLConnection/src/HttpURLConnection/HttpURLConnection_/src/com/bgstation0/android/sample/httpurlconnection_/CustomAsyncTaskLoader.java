package com.bgstation0.android.sample.httpurlconnection_;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;
import java.util.Iterator;
import java.util.Map;

import android.content.AsyncTaskLoader;
import android.content.Context;

public class CustomAsyncTaskLoader extends AsyncTaskLoader<String> {	// 非同期処理の結果がStringのCustomAsyncTaskLoader.

	// メンバフィールドの定義
	Context context;	// Context型context
	String url;	// String型url
	
	// コンストラクタ
	public CustomAsyncTaskLoader(Context context, String url){
		super(context);	// 親クラスのコンストラクタを呼ぶ.
		this.context = context;	// this.contextメンバに格納.
		this.url = url;	// this.urlメンバに格納.
	}
	
	// 非同期処理
	@Override
	public String loadInBackground(){
		// オブジェクトの宣言
		String ret = "";	// 戻り値の文字列retに""をセット.
		HttpURLConnection connection = null;	// HttpURLConnection型connectionをnullにセット.
		BufferedReader reader = null;	// BufferedReader型readerをnullにセット.
		// tryで囲む.
		try{
			// リクエスト作成と接続
			URL url = new URL(this.url);	// newでURLオブジェクトurlを生成, このときthis.urlを渡す.(ややこしいがurlがローカルURLオブジェクト, this.urlがString型メンバ.)
			connection = (HttpURLConnection)url.openConnection();	// url.openConnectionでコネクションを開くと, URLConnectionオブジェクトが返るので, HttpURLConnectionにキャストしてconnectionに格納.
			connection.setRequestMethod("GET");	// connection.setRequestMethodで"GET"を指定.
			connection.setInstanceFollowRedirects(true);	// connection.setInstanceFollowRedirectsでtrueにすることで自動リダイレクト.
			connection.connect();	// connection.connectで接続.
			//　受信, レスポンスボディ取得.
			reader = new BufferedReader(new InputStreamReader(connection.getInputStream()));	// connection.getInputStreamからBufferedReaderオブジェクトreaderを作成.
			String inputLine;	// 取得できたストリーム文字列.
			while ((inputLine = reader.readLine()) != null){	// nullでなければ.
				ret += inputLine;	// retにinputLineを追加.
			}
		}
		catch (Exception ex){
			ret = ex.toString();	// retにexの内容をセット.
		}
		finally{
			try{
				if (reader != null){
					reader.close();	// readerを閉じる.
					reader = null;	// readerをnullに.
				}
				if (connection != null){
					connection.disconnect();	// connection切断.
					connection = null;	// connectionをnullに.
				}
			}
			catch (Exception ex){
				ret = ex.toString();	// retにexの内容をセット.
			}
		}
		return ret;
	}
	
	// Loaderの開始時
    @Override
    protected void onStartLoading(){
    	forceLoad();	// 強制的にロード開始.
    }
}
