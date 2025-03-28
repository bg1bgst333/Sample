package com.bgstation0.android.sample.accountmanager_;

import android.accounts.Account;
import android.accounts.AccountManager;
import android.accounts.AccountManagerCallback;
import android.accounts.AccountManagerFuture;
import android.app.Activity;
import android.content.Context;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class MainActivity extends Activity implements OnClickListener{

	// メンバフィールドの定義.
	Context mContext = null;	// mContextをnullで初期化.
	String mToken = "";	// mTokenを""で初期化.
	
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    
        // mContextの初期化.
        mContext = this;	// mContextにthisをセット.
        
        // button1の取得.
        Button button1 = (Button)findViewById(R.id.button1);	// button1を取得.
        button1.setOnClickListener(this);	// リスナーにthisをセット.
        // button2の取得.
        Button button2 = (Button)findViewById(R.id.button2);	// button2を取得.
        button2.setOnClickListener(this);	// リスナーにthisをセット.
        // button3の取得.
        Button button3 = (Button)findViewById(R.id.button3);	// button3を習得.
        button3.setOnClickListener(this);	// リスナーにthisをセット.
        
    }
    
    // クリックされた時.
 	@Override
 	public void onClick(View v) {	// onClickの定義(オーバーライド)
 		// TODO Auto-generated method stub
 		if (v.getId() == R.id.button1){	// button1が押された時.
	 		AccountManager accountManager = AccountManager.get(this);	// accountManager取得.
	 		EditText edittext1 = (EditText)findViewById(R.id.edittext1);	// edittext1を取得.
	 		Account target = new Account(edittext1.getText().toString(), "com.google");	// targetを生成.
	 		accountManager.getAuthToken(target, "mail", null, this, new AccountManagerCallback<Bundle>(){
	
				@Override
				public void run(AccountManagerFuture<Bundle> future) {
					// TODO Auto-generated method stub
					try{
						Bundle bundle = future.getResult();	// bundleを取得.
						mToken = bundle.getString(AccountManager.KEY_AUTHTOKEN);	// tokenを取得.
						Toast.makeText(mContext, "token = " + mToken, Toast.LENGTH_LONG).show();	// mTokenを表示.
					}
					catch (Exception ex){
						Toast.makeText(mContext, "ex = " + ex.toString(), Toast.LENGTH_LONG).show();	// exを表示.
					}
				}
			
	 		}, null);	// トークンの取得.
 		}
 		else if (v.getId() == R.id.button2){	// button2が押された時.
 			AccountManager accountManager = AccountManager.get(this);	// accountManager取得.
 			accountManager.invalidateAuthToken("com.google", mToken);	// mTokenを無効にする.
 			Toast.makeText(mContext, "invalidate token = " + mToken, Toast.LENGTH_LONG).show();	// 無効化されたことを表示.
 		}
 		else if (v.getId() == R.id.button3){	// button3の押された時.
 			AccountManager accountManager = AccountManager.get(this);	// accountManager取得.
 			EditText edittext1 = (EditText)findViewById(R.id.edittext1);	// edittext1を取得.
 			Account target = new Account(edittext1.getText().toString(), "com.google");	// targetを生成.
 			accountManager.clearPassword(target);	// パスワードをクリアすることでアカウントを無効化.
 		}
 		
 	}
 	
}