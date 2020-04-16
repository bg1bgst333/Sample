package com.bgstation0.android.sample.dialogfragment_;

import android.app.Activity;
import android.app.AlertDialog;
import android.app.Dialog;
import android.app.DialogFragment;
import android.content.DialogInterface;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;

// メインアクティビティ
public class MainActivity extends Activity {

	// タグの定義.
    private final String TAG = "MainActivity";	// TAGは"MainActivity".
    
    // アクティビティ作成時.
    protected void onCreate(Bundle savedInstanceState) {
    	
    	// ビューのセット.
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // button1を取得し, 新しいOnClickListenerをセット.
        Button button1 = (Button)findViewById(R.id.button1);	// findViewByIdでR.id.button1を取得.
        button1.setOnClickListener(new View.OnClickListener() {	// button1.setOnClickListenerに新しいView.OnClickListenerをセット.
			
        	// クリック時.
			@Override
			public void onClick(View v) {
				// TODO Auto-generated method stub
				
				// DialogFragmentの作成.
				DialogFragment dialogFragment = new DialogFragment(){	// 匿名クラス定義.
					
					// ダイアログ作成時.
					@Override
					public Dialog onCreateDialog(Bundle savedInstanceState){
						
						// アラートダイアログビルダーの設定.
						AlertDialog.Builder builder = new AlertDialog.Builder(getActivity());	// builderの生成.
						builder.setTitle("DialogFragment");	// タイトル"DialogFragment".
						builder.setMessage("DialogFragment");	// メッセージ""DialogFragment".
						builder.setPositiveButton("OK", new DialogInterface.OnClickListener() {	// ポジティブボタン"OK".
							@Override
							public void onClick(DialogInterface dialog, int which) {
								// TODO Auto-generated method stub

							}
						});
						
						// アラートダイアログの作成.
						return builder.create();	// builder.createで生成.
						
					}
					
				};
				
				// DialogFragmentの表示.
				dialogFragment.show(getFragmentManager(), TAG);
				
			}
			
		});
        
    }
    
}