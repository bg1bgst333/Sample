package com.bgstation0.android.sample.asynctaskloader_;

import android.content.AsyncTaskLoader;
import android.content.Context;

public class CustomAsyncTaskLoader extends AsyncTaskLoader<String> {	// 非同期処理の結果がStringのCustomAsyncTaskLoader.

    // メンバフィールドの定義
    Context context;	// Context型context
    int param;	// int型param
    
    // コンストラクタ
    public CustomAsyncTaskLoader(Context context, int param){
    	super(context);	// 親クラスのコンストラクタを呼ぶ.
        this.context = context;	// this.contextメンバに格納.
        this.param = param;	// this.paramメンバに格納.
	}
    
    // 非同期処理
    @Override
    public String loadInBackground(){
    	// オブジェクトの宣言
    	String ret = "";	// 戻り値の文字列retに""をセット.
    	// tryで囲む.
    	try{
    		Thread.sleep(10000);	// 10秒休止
    		ret = "param = " + param;	// retにparamの値.
    	}
    	catch (Exception ex){
    		ret = "exception";	// retにexception.
    	}
    	return ret;
    }
    
    // Loaderの開始時
    @Override
    protected void onStartLoading(){
    	forceLoad();	// 強制的にロード開始.
    }
    
}
