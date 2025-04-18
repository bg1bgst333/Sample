package com.bgstation0.android.sample.activity_;

import android.app.Activity;
import android.app.AlertDialog;
import android.app.Dialog;
import android.content.DialogInterface;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.Toast;

public class MainActivity extends Activity implements OnClickListener{	// View.OnClickListenerを実装.

	// タグの定義
	private final String TAG = "MainActivity";	// TAGは"MainActivity"
	private final int DIALOG_ID_1 = 1;	// DIALOG_ID_1を1にする.
	private final int DIALOG_ID_2 = 2;	// DIALOG_ID_2を2にする.
	
	@Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // button1を取得し, OnClickListenerとして自身をセット.
        Button button1 = (Button)findViewById(R.id.button1);	// findViewByIdでR.id.button1を取得.
        button1.setOnClickListener(this);	// button1.setOnClickListenerでthis(自身)をセット.
        
        // button2を利用し, OnClickListenerとして自身をセット.
        Button button2 = (Button)findViewById(R.id.button2);	// findViewByIdでR.id.button2を取得.
        button2.setOnClickListener(this);	// button2.setOnClickListenerでthis(自身)をセット.
        
    }
	
	// View.OnClickListenerインタフェースのオーバーライドメソッドを実装.
    public void onClick(View v){	// onClickをオーバーライド.
    
    	// ボタンのIDごとに分ける.
    	if (v.getId() == R.id.button1){ // button1

    		// DIALOG_ID_1の表示.
    		Bundle args = new Bundle();	// argsの生成.
    		args.putString("title", "dialog1");	// "title"を"dialog1"にセット.
    		args.putString("message", "button1 clicked!");	// "message"を"button1 clicked!"にセット.
    		showDialog(DIALOG_ID_1, args);	// showDialogでDIALOG_ID_1のダイアログ表示.(argsを渡す.)
    		
    	}
    	else if (v.getId() == R.id.button2){ // button2
    		
    		// DIALOG_ID_2の表示.
    		Bundle args = new Bundle();	// argsの生成.
    		args.putString("title", "dialog2");	// "title"を"dialog2"にセット.
    		args.putString("message", "button2 clicked!");	// "message"を"button2 clicked!"にセット.
    		showDialog(DIALOG_ID_2, args);	// showDialogでDIALOG_ID_2のダイアログ表示.(argsを渡す.)
    		
    	}
    	
    }
    
    // onCreateDialogでダイアログ作成.
    @Override
    protected Dialog onCreateDialog(int id, Bundle args){
    	
    	// アラートダイアログビルダーの生成
    	AlertDialog.Builder builder = new AlertDialog.Builder(this);	// AlertDialog.Builerのインスタンスbuilderの生成.
    	
    	// argsで渡された"title"と"message"を取り出す.
    	String title = args.getString("title");	// titleを取得.
    	Toast.makeText(this, "title = " + title, Toast.LENGTH_LONG).show();	// titleを表示.
    	String message = args.getString("message");	// messageを取得.
    	Toast.makeText(this, "message = " + message, Toast.LENGTH_LONG).show();	// messageを表示.
    	
    	// IDごとに変える.
    	if (id == DIALOG_ID_1){	// DIALOG_ID_1
    		
	    	// アラートダイアログの設定
	    	builder.setTitle("Activity.showDialog(1)");	// setTitleでタイトル"Activity.showDialog(1)"をセット.
	    	builder.setMessage("Activity.showDialog(1)");	// setMessageで本文"Activity.showDialog(1)"をセット.
	
	    	// ポジティブボタンの設定
	    	builder.setPositiveButton("OK", new DialogInterface.OnClickListener() {	// builder.setPositiveButtonでポジティブボタン"OK"のDialogInterface.OnClickListenerをセット. 
				
				@Override
				public void onClick(DialogInterface dialog, int which) {
					// TODO Auto-generated method stub
					Log.v(TAG, "Activity.showDialog(1) OK onClick!");	// Log.vで"Activity.showDialog(1) OK onClick!"を表示.
				}
				
			});
    	
    	}
    	else if (id == DIALOG_ID_2){ // DIALOG_ID_2
    		
    		// アラートダイアログの設定
	    	builder.setTitle("Activity.showDialog(2)");	// setTitleでタイトル"Activity.showDialog(2)"をセット.
	    	builder.setMessage("Activity.showDialog(2)");	// setMessageで本文"Activity.showDialog(2)"をセット.
	
	    	// ポジティブボタンの設定
	    	builder.setPositiveButton("OK", new DialogInterface.OnClickListener() {	// builder.setPositiveButtonでポジティブボタン"OK"のDialogInterface.OnClickListenerをセット. 
				
				@Override
				public void onClick(DialogInterface dialog, int which) {
					// TODO Auto-generated method stub
					Log.v(TAG, "Activity.showDialog(2) OK onClick!");	// Log.vで"Activity.showDialog(2) OK onClick!"を表示.
				}
				
			});
    		
    	}

    	// アラートダイアログの作成
    	return builder.create();	// builder.createで作成したDialogオブジェクトを返す.
    	
    }
	
}