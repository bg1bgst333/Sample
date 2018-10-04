package com.bgstation0.android.sample.aaa_;

import android.app.Service;
import android.content.Intent;
import android.os.IBinder;

public class AuthenticationService extends Service {

	// メンバフィールドの定義.
	private CustomAuthenticator mCustomAuthenticator = null;	// mCustomAuthenticatorをnullで初期化.
	
	// サービスの生成.
	@Override
	public void onCreate(){
		super.onCreate();	// 親クラスの生成.
		mCustomAuthenticator = new CustomAuthenticator(this);	// mCustomAuthenticatorを生成.
	}
	
	// バインド.
	@Override
	public IBinder onBind(Intent intent) {
		// TODO Auto-generated method stub
		return mCustomAuthenticator.getIBinder();	// mCustomAuthenticator.getIBinderの戻り値を返す.
	}

}