package com.bgstation0.android.sample.defaulthttpclient_;

import java.io.ByteArrayOutputStream;

import org.apache.http.HttpResponse;
import org.apache.http.HttpStatus;
import org.apache.http.client.HttpClient;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.impl.client.DefaultHttpClient;

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
		ByteArrayOutputStream stream = null;	// バイト列出力ストリームstreamをnullに.
		// tryで囲む.
    	try{
    		//　HTTPリクエスト
    		HttpClient httpClient = new DefaultHttpClient();	// DefaultHttpClientでhttpClient取得.
    		HttpGet httpGetReq = new HttpGet(url);	// urlを渡してHTTP GETなリクエスト取得.
    		HttpResponse httpRes = httpClient.execute(httpGetReq);	// リクエストを実行し, レスポンスを取得.
    		int status = httpRes.getStatusLine().getStatusCode();	// HTTPステータスコード取得.
    		if (status == HttpStatus.SC_OK){	// HTTP 200 OK
    			stream = new ByteArrayOutputStream();	// バイト列出力ストリーム生成.
    			httpRes.getEntity().writeTo(stream);	// レスポンスのボディをstreamに書き込む.
    			ret = stream.toString();	// streamを文字列にしたものをretに格納.
    		}
    	}
    	catch (Exception ex){
    		ret = ex.toString();	// retにexの内容をセット.
    	}
    	finally{
    		if (stream != null){
    			try{
    				stream.close();	// streamを閉じる.
    				stream = null;	// streamをnullに.
    			}
    			catch (Exception ex){
    	    		ret = ex.toString();	// retにexの内容をセット.
    	    	}
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
