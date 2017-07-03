package com.bgstation0.android.sample.context_;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.EditText;

public class MainActivity extends Activity implements OnClickListener{	// View.OnClickListenerを実装.

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // getButtonを取得し, OnClickListenerとして自身をセット.
        Button getButton = (Button)findViewById(R.id.button_get);	// getButtonを取得.
        getButton.setOnClickListener(this);	// getButton.setOnClickListenerでthisをセット.
    }
    
    // View.OnClickListenerインタフェースのオーバーライドメソッドを実装.
    public void onClick(View v){	// onClickをオーバーライド.
    	
    	// ボタンのidをごとに処理を振り分ける.
    	switch (v.getId()) {	// v.getIdでView(Button)のidを取得.
    		
    		// button_getの場合.
    		case R.id.button_get:	// R.id.button_getの時.
    
    			// パスを取得.
    			String dir = getFilesDir().getPath();	// getFilesDir().getPath()でアプリケーションフォルダ内のfilesフォルダのパスを取得.
    			EditText edittext = (EditText)findViewById(R.id.edittext_path);	// edittextを取得.
    			edittext.setText(dir);	// edittext.setTextでdirをセット.
    			
    			// 抜ける.
				break;	// breakで抜ける.
    			
    	}
    	
    }
    
}
