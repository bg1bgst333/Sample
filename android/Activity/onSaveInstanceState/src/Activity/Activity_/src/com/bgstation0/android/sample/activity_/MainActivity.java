package com.bgstation0.android.sample.activity_;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

// メインアクティビティ
public class MainActivity extends Activity implements OnClickListener{

	// メンバフィールドの定義
	final String KEY_TEXTVIEW1_STRING = "key_textview1_string";	// 定数KEY_TEXTVIEW1_STRを定義.
	
	// アクティビティ生成時
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        
    	// 既定の処理.
    	super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // button1の初期化
        Button button1 = (Button)findViewById(R.id.button1);	// button1を取得.
        button1.setOnClickListener(this);	// thisをセット.
        
    }

    // クリックされた時.
	@Override
	public void onClick(View v) {
		
		// TODO Auto-generated method stub
		// TextViewに"ABCDE"をセット.
		TextView textview1 = (TextView)findViewById(R.id.textview1);	// textview1を取得.
		textview1.setText("ABCDE");	// "ABCDE"をセット.
		
	}
	
	// アクティビティのインスタンスの一時的な保持が要求された時.
	@Override
	protected void onSaveInstanceState(Bundle outState){
		
		// 既定の処理
		super.onSaveInstanceState(outState);	// 親クラスのメソッドを呼ぶ.
		
		// textview1のテキストをoutStateに保存.
		TextView textview1 = (TextView)findViewById(R.id.textview1);	// textview1を取得.
		String text = (String)textview1.getText();	// textview1のテキストを取得.
		outState.putString(KEY_TEXTVIEW1_STRING, text);	// outState.putStringでKEY_TEXTVIEW1_STRINGをキーとしてtextを保存.
		Toast.makeText(this, text, Toast.LENGTH_LONG).show();	// textをトースト表示.
		
	}
    
}