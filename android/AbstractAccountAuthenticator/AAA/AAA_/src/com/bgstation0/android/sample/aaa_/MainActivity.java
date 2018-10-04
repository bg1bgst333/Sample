package com.bgstation0.android.sample.aaa_;

import android.accounts.Account;
import android.accounts.AccountManager;
import android.app.Activity;
import android.content.Context;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

public class MainActivity extends Activity {

	// メンバフィールドの定義.
	Context mContext = null;	// mContextをnullで初期化.
	
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // mContextの初期化.
        mContext = this;	// mContextをthisで初期化.
        
        // アカウント名とパスワードの取得.
        final EditText etName = (EditText)findViewById(R.id.edittext1);	// etNameを取得.
        final EditText etPassword = (EditText)findViewById(R.id.edittext2);	// etPasswordを取得.
        Button button = (Button)findViewById(R.id.button1);	// buttonを取得.
        button.setOnClickListener(new View.OnClickListener() {
			
			@Override
			public void onClick(View v) {
				// TODO Auto-generated method stub
				String name = etName.getText().toString();	// nameを取得.
				String password = etPassword.getText().toString();	// passwordを取得.
				// アカウントの保存.
				Account account = new Account(name, "com.bgstation0.android.sample");	// account生成.
				AccountManager accountManager = AccountManager.get(mContext);	// accountManagerを取得.
				accountManager.addAccountExplicitly(account, password, null);	// addAccountExplicitlyで保存.
				// 認証画面を閉じる.
				setResult(RESULT_OK);	// RESULT_OK
				finish();	// 終了.
			}
			
		});
        
    }
    
}