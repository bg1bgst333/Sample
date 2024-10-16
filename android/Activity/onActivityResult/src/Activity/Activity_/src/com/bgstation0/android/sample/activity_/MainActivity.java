package com.bgstation0.android.sample.activity_;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.Toast;

public class MainActivity extends Activity implements OnClickListener{	// View.OnClickListenerを実装.

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // button1を取得し, OnClickListenerとして自身をセット.
        Button button1 = (Button)findViewById(R.id.button1);	// findViewByIdでR.id.button1を取得.
        button1.setOnClickListener(this);	// button1.setOnClickListenerでthis(自身)をセット.
    }
    
    // View.OnClickListenerインタフェースのオーバーライドメソッドを実装.
    public void onClick(View v){	// onClickをオーバーライド.
    	
    	// ボタンのIDごとに振り分ける.
    	switch (v.getId()){	// v.getIdごとに振り分ける.
    	
    		// button1の時.
    		case R.id.button1:
    			
    			// R.id.button1ブロック
    			{
    				
    				// アクティビティの起動
    				Intent intent = new Intent(this, SubActivity.class);	// SubActivityを起動するintentの作成.
    				startActivityForResult(intent, 1);	// startActivityForResultでintentをリクエストコード1で起動.
    			}
    			
    			// 抜ける.
    			break;	// breakで抜ける.
    			
    	}
    	
    }
    
    // アクティビティの結果が返ってきたとき.
    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data){
    	
    	// 結果に対する処理.
    	super.onActivityResult(requestCode, resultCode, data);	// まず親クラスonActivityResult.
    	
    	// キャンセルなら終了.
    	if (resultCode == RESULT_CANCELED){	// RESULT_CANCELEDの場合.
    		Toast.makeText(this, "RESULT_CANCELED", Toast.LENGTH_LONG).show();	// "RESULT_CANCELED"と表示.
    		return;	// 何もせず終了.
    	}
    	
    	// キャンセルでなければ振り分け.
    	switch (requestCode){	// requestCodeで振り分け.
    		
    		// requestCodeが1.
    		case 1:	// 1の時.
    			
    			// requestCode = 1.
    			{
    				
    				String message = data.getStringExtra("message");	// 引数のキー"message"からdata.getStringExtraで値を取得.
    				Toast.makeText(this, message, Toast.LENGTH_LONG).show();	// Toastでmessageを表示.
    				
    			}
    			
    			// 抜ける.
    			break;	// breakで抜ける.
    			
    	}
    	
    }
    
}
