package com.bgstation0.android.sample.dialogfragment_;

import android.app.Activity;
import android.app.DialogFragment;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;

//メインアクティビティ.
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
    
    // クリック時.
   	@Override
   	public void onClick(View v) {
   		// TODO Auto-generated method stub
   		// ダイアログの表示.
   		DialogFragment dialogFragment = new DialogFragment();	// DialogFragmentオブジェクトdialogFragmentの生成.
   		dialogFragment.show(getFragmentManager(), "DialogFragment");	// dialogFragment.showで表示.
   	}
   	
}