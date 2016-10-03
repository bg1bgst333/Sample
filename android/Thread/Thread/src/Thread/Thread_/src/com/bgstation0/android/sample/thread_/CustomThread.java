package com.bgstation0.android.sample.thread_;

import android.util.Log;

public class CustomThread extends Thread {
	
	// メンバフィールドの定義.
	private final String TAG = "Thread_";	// TAG"Thread_"の定義.
	
	public void run(){
		
		// Thread.sleepで擬似的に重たい処理を実行.
    	// tryで囲まないといけない.
    	try{
    		Log.d(TAG, "Thread.sleep before");	// Log.dで"Thread.sleep before"とログ出力.
    		Thread.sleep(10000);	// Thread.sleepで10秒休止.
    		Log.d(TAG, "Thread.sleep after");	// Log.dで"Thread.sleep after"とログ出力.
    	}
    	catch(Exception ex){
    		Log.d(TAG, "ex = " + ex.toString());	// Log.dでexを出力.
    	}
		
	}

}
