package com.bgstation0.android.sample.fragment_;

import android.app.Activity;
import android.app.FragmentManager;
import android.app.FragmentTransaction;
import android.content.Intent;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.Toast;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        if (savedInstanceState == null){
        	
            // フラグメントの追加.
            FragmentManager fragmentManager = getFragmentManager();	// fragmentManagerの取得.
            FragmentTransaction fragmentTransaction = fragmentManager.beginTransaction();	// fragmentTransactionの取得.
            Fragment1 fragment1 = new Fragment1();	// fragment1の生成.
            fragmentTransaction.add(R.id.framelayout1, fragment1);	// fragment1を追加.
            fragmentTransaction.commit();	// 確定.
            
        }
        
    }
    
    // アクティビティの結果が返ってきた時.
    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data){
    	
    	// 既定の処理
    	super.onActivityResult(requestCode, resultCode, data);	// 親クラスのonActivityResultを呼ぶ.
    	
    	// キャンセルなら終了.
    	if (resultCode == Activity.RESULT_CANCELED){	// RESULT_CANCELEDの場合.
    		return;	// 何もせず終了.
    	}
    	
    	// requestCodeの出力.
    	Toast.makeText(this, "MainActivity.requestCode = " + String.valueOf(requestCode), Toast.LENGTH_LONG).show();	// requestCodeをToast表示.
    	
    	// requestCodeが1.
    	if (requestCode == 1){
    		String message = data.getStringExtra("message");	// message取得.
    		Toast.makeText(this, message, Toast.LENGTH_LONG).show();	// messageをToast表示.
    	}
    	
    }
    
}