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
 		EditText edittext1 = (EditText)findViewById(R.id.edittext1);	// edittext1を取得.
 		Account target = new Account(edittext1.getText().toString(), "com.google");	// targetを生成.
 		accountManager.removeAccount(target, new AccountManagerCallback<Boolean>(){

			@Override
			public void run(AccountManagerFuture<Boolean> future) {
				// TODO Auto-generated method stub
				try{
					boolean res = future.getResult();	// resを取得.
					if (res){	// resがtrue.
						Toast.makeText(mContext, "remove success!", Toast.LENGTH_LONG).show();	// "remove success!".
					}
					else{	// resがfalse.
						Toast.makeText(mContext, "remove failure!", Toast.LENGTH_LONG).show();	// "remove failure!".
					}
				}
				catch (Exception ex){
					Toast.makeText(mContext, "ex = " + ex.toString(), Toast.LENGTH_LONG).show();	// exを表示.
				}
			}
 		}, null);	// アカウントの削除.
    
 	}
 	
}