package com.bgstation0.android.sample.accountmanager_;

import android.accounts.AccountManager;
import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.Toast;

public class MainActivity extends Activity implements OnClickListener{

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // button1の取得.
        Button button1 = (Button)findViewById(R.id.button1);	// button1を取得.
        button1.setOnClickListener(this);	// リスナーにthisをセット.
        
    }
    
    // クリックされた時.
 	@Override
 	public void onClick(View v) {	// onClickの定義(オーバーライド)
 		// TODO Auto-generated method stub
 		AccountManager accountManager = AccountManager.get(this);	// accountManager取得.
 		Intent intent = accountManager.newChooseAccountIntent(null, null, new String[]{"com.google"}, false, null, null, null, null);	// アカウント選択ダイアログのインテント取得.
 		startActivityForResult(intent, 101);	// intentを起動.
 	}
 	
 	// アクティビティの結果が返ってきたとき.
    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data){
    	
    	// 結果に対する処理.
    	super.onActivityResult(requestCode, resultCode, data);	// まず親クラスonActivityResult
    	
    	// 101でOKの場合.
    	if (requestCode == 101 && resultCode == Activity.RESULT_OK){
    		String name = data.getStringExtra(AccountManager.KEY_ACCOUNT_NAME);	// nameを取得.
    		Toast.makeText(this, "name = " + name, Toast.LENGTH_LONG).show();	// nameを表示.
    	}
    	
    }
    
}