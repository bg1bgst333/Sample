package com.bgstation0.android.sample.message_;

import android.os.Handler;
import android.os.Message;
import android.util.Log;

public class CustomThread extends Thread {

	// メンバフィールドの定義.
	private Handler mHandler = null;	// mHandlerをnullで初期化.
	private final String TAG = "Handler_";	// TAG"Handler_"の定義.
	private int mWhat = -1;	// mWhatを-1で初期化.
	
	// コンストラクタ
	public CustomThread(Handler handler, int what){
		
		// 引数のhandlerをメンバのmHandlerにセット.
		mHandler = handler;	// mHandlerにhandlerをセット.
		mWhat = what;	// mWhatにwhatをセット.
		
	}
	
	// 実行
	@Override
	public void run(){
		
		// 重い処理(10秒スリープ)
		try{
			Thread.sleep(10000);	// Thread.sleepで10秒休止.
			String strMessage = "finish";	// strMessageを"finish"で初期化.
			Message msg = Message.obtain();	// Message.obtain()でMessageオブジェクトmsg生成.
			msg.obj = strMessage;	// msg.objにstrMessagをセット.
			msg.what = mWhat; // msg.whatにmWhatをセット.
			//mHandler.sendMessage(msg);	// mHandler.sendMessageでmsgを送信.
			msg.setTarget(mHandler);	// ターゲットをmHandlerとする.
			msg.sendToTarget();	// ターゲットにメッセージを送信する.
		}
		catch(Exception ex){
    		Log.d(TAG, "ex = " + ex.toString());	// Log.dでexを出力.
    	}
		
	}
	
}