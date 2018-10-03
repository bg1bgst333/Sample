package com.bgstation0.android.sample.accountmanager_;

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
import android.widget.Toast;

public class MainActivity extends Activity implements OnClickListener{

	// メンバフィールドの定義.
	Context mContext = null;	// mContextをnullで初期化.
	
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    
        // mContextの初期化.
        mContext = this;	// mContextにthisをセット.
        
        // button1の取得.
        Button button1 = (Button)findViewById(R.id.button1);	// button1を取得.
        button1.setOnClickListener(this);	// リスナーにthisをセット.
        
    }
    
    // クリックされた時.
 	@Override
 	public void onClick(View v) {	// onClickの定義(オーバーライド)
 		// TODO Auto-generated method stub
 		AccountManager accountManager = AccountManager.get(this);	// accountManager取得.
 		accountManager.addAccount("com.google", "mail", null, null, this, new AccountManagerCallback<Bundle>(){

			@Override
			public void run(AccountManagerFuture<Bundle> future) {
				// TODO Auto-generated method stub
				try{
					Bundle bundle = future.getResult();	// bundleを取得.
					String name = bundle.getString(AccountManager.KEY_ACCOUNT_NAME);
					Toast.makeText(mContext, "add name = " + name, Toast.LENGTH_LONG).show();	// 追加したnameを表示.
				}
				catch (Exception ex){
					Toast.makeText(mContext, "ex = " + ex.toString(), Toast.LENGTH_LONG).show();	// exを表示.
				}
			}
 			
 		}, null);	// アカウントの追加.
 	}
    
}