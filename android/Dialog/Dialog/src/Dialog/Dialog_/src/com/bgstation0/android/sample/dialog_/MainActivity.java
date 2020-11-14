package com.bgstation0.android.sample.dialog_;

import android.app.Activity;
import android.app.Dialog;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;

// メインアクティビティ.
public class MainActivity extends Activity implements OnClickListener{

	// メンバフィールド.
	private final int DIALOG_ID_1 = 1;	// DIALOG_ID_1を1にする.
	
	// アクティビティ生成時.
    @Override
    protected void onCreate(Bundle savedInstanceState) {
    	
    	// 既定の処理.
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // button1を取得し, OnClickListenerとして自身をセット.
        Button button1 = (Button)findViewById(R.id.button1);	// findViewByIdでR.id.button1を取得.
        button1.setOnClickListener(this);	// button1.setOnClickListenerでthis(自身)をセット.
      
    }
    
    // onCreateDialogでダイアログ作成.
    @Override
    protected Dialog onCreateDialog(int id){
    	//　Dialogの生成.
    	Dialog dialog = new Dialog(this);	// Dialogオブジェクトdialogを生成.
    	return dialog;	// dialogを返す.
    }

    // クリック時.
	@Override
	public void onClick(View v) {
		// TODO Auto-generated method stub
		// ダイアログの表示.
		showDialog(DIALOG_ID_1);	// showDialogでDIALOG_ID_1のダイアログを表示.
	}
	
}