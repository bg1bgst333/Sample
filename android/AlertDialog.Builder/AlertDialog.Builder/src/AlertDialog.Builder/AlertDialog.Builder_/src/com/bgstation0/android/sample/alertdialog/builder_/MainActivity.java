package com.bgstation0.android.sample.alertdialog.builder_;

import android.app.Activity;
import android.app.AlertDialog;
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
		
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        //button1を取得し, OnClickListenerとして自身をセット.
        Button button1 = (Button)findViewById(R.id.button1);	// findViewByIdでR.id.button1を取得.
        button1.setOnClickListener(this);	// button1.setOnClickListenerでthis(自身)をセット.
    }
    
    // View.OnClickListenerインタフェースのオーバーライドメソッドを実装.
    public void onClick(View v){	// onClickをオーバーライド.
    	
    	// アラートダイアログビルダーの生成
    	AlertDialog.Builder builder = new AlertDialog.Builder(this);	// AlertDialog.Builerのインスタンスbuilderの生成.
    	
    	// アラートダイアログの設定
    	builder.setTitle("AlertDialog.Builder");	// setTitleでタイトル"AlertDialog.Builder"をセット.
    	builder.setMessage("AlertDialog.Builder");	// setMessageで本文"AlertDialog.Builder"をセット.

    	// ポジティブボタンの設定
    	builder.setPositiveButton("OK", new DialogInterface.OnClickListener() {	// builder.setPositiveButtonでポジティブボタン"OK"のDialogInterface.OnClickListenerをセット. 
			
			@Override
			public void onClick(DialogInterface dialog, int which) {
				// TODO Auto-generated method stub
				Log.v(TAG, "AlertDialog OK onClick!");	// Log.vで"AlertDialog OK onClick!"を表示.
			}
		});

    	// アラートダイアログの表示
    	builder.show();	// builder.showでアラートダイアログを表示
    }
}
