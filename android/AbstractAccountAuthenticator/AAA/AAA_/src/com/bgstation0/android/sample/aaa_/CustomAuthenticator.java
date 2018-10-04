package com.bgstation0.android.sample.aaa_;

import android.accounts.AbstractAccountAuthenticator;
import android.accounts.Account;
import android.accounts.AccountAuthenticatorResponse;
import android.accounts.AccountManager;
import android.accounts.NetworkErrorException;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;

public class CustomAuthenticator extends AbstractAccountAuthenticator {

	// メンバフィールドの定義.
	final Context mContext;	// mContext.
	
	// コンストラクタ
	public CustomAuthenticator(Context context){
		super(context);	// 親コンストラクタにcontextを渡す.
		mContext = context;	// mContextに格納.
	}
	
	@Override
	public Bundle editProperties(AccountAuthenticatorResponse response,
			String accountType) {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public Bundle addAccount(AccountAuthenticatorResponse response,
			String accountType, String authTokenType,
			String[] requiredFeatures, Bundle options)
			throws NetworkErrorException {
		// TODO Auto-generated method stub
		// ログイン画面を起動するインテントの作成.
		Intent intent = new Intent(mContext, MainActivity.class);	// intentの作成.
		intent.putExtra(AccountManager.KEY_ACCOUNT_AUTHENTICATOR_RESPONSE, response);	// responseを登録.
		// intentをbundleに入れて返す.
		Bundle bundle = new Bundle();	// bundleを生成.
		bundle.putParcelable(AccountManager.KEY_INTENT, intent);	// intentを登録.
		return bundle;	// bundleを返す.
	}

	@Override
	public Bundle confirmCredentials(AccountAuthenticatorResponse response,
			Account account, Bundle options) throws NetworkErrorException {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public Bundle getAuthToken(AccountAuthenticatorResponse response,
			Account account, String authTokenType, Bundle options)
			throws NetworkErrorException {
		// TODO Auto-generated method stub
		AccountManager accountManager = AccountManager.get(mContext);	// accountManagerを取得.
		String name = account.name;	// nameを取得.
		String password = accountManager.getPassword(account);	// passwordを取得.
		String token = "TEST_TOKEN";	// tokenを"TEST_TOKEN"とする.
		accountManager.setAuthToken(account, authTokenType, token);	// tokenをセット.
		// bundleで返却.
		Bundle bundle = new Bundle();	// bundleを生成.
		bundle.putString(AccountManager.KEY_ACCOUNT_NAME, name);	// nameを登録.
		bundle.putString(AccountManager.KEY_ACCOUNT_TYPE, "com.bgstation0.android.sample");	// typeを登録.
		bundle.putString(AccountManager.KEY_AUTHTOKEN, token);	// tokenを登録.
		return bundle;	// bundleを返す.
	}

	@Override
	public String getAuthTokenLabel(String authTokenType) {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public Bundle updateCredentials(AccountAuthenticatorResponse response,
			Account account, String authTokenType, Bundle options)
			throws NetworkErrorException {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public Bundle hasFeatures(AccountAuthenticatorResponse response,
			Account account, String[] features) throws NetworkErrorException {
		// TODO Auto-generated method stub
		return null;
	}

}
