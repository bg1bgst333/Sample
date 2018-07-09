package com.bgstation0.android.sample.recognizerintent_;

import java.util.ArrayList;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.speech.RecognizerIntent;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class MainActivity extends Activity implements View.OnClickListener {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // ボタンにリスナーをセット.
        Button button1 = (Button)findViewById(R.id.button1);	// button1を取得.
        button1.setOnClickListener(this);	// thisをセット.
    }
    
    // クリックされた時.
    @Override
    public void onClick(View v){
    
    	// インテント作成.
    	try{	// tryで囲む.
    		Intent intent = new Intent(RecognizerIntent.ACTION_RECOGNIZE_SPEECH);	// IntentのコンストラクタにRecognizerIntent.ACTION_RECOGNIZE_SPEECHを渡してintent作成.
    		intent.putExtra(RecognizerIntent.EXTRA_LANGUAGE_MODEL, RecognizerIntent.LANGUAGE_MODEL_FREE_FORM);	// 言語モデルはフリーフォーム.
    		intent.putExtra(RecognizerIntent.EXTRA_PROMPT, "RecognizerIntent");	// プロンプト文字列は"RecognizerIntent".
    		startActivityForResult(intent, 100);	// リクエストコード100でintent発行.
    	}
    	catch (Exception ex){
    		Toast.makeText(this, "ex = " + ex.toString(), Toast.LENGTH_LONG).show();	// ex.toString()を出力.
    	}
    	
    }
    
    // アクティビティを起動した結果.
    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {

    	// リザルトコードとリクエストコードで振り分ける.
    	if (resultCode == RESULT_OK){	// RESULT_OKなら.
    		if (requestCode == 100){	// 100なら.
    			// ArrayList<String>で返ってくる.
    			ArrayList<String> aryListStrs = data.getStringArrayListExtra(RecognizerIntent.EXTRA_RESULTS);	// aryListStrsを取得.
    			String result = "";	// resultを""で初期化.
    			for (int i = 0; i < aryListStrs.size() - 1; i++){	// (単語の個数 - 1)回繰り返す.
    				result = result + aryListStrs.get(i);	// resultにi番目を連結.
    				result = result + " ";	// スペースを連結.
    			}
    			result = result + aryListStrs.get(aryListStrs.size() - 1);	// 最後の要素を連結.
    			EditText edittext1 = (EditText)findViewById(R.id.edittext1);
    			edittext1.setText(result);	// edittext1.setTextでresultをセット.
    		}
    	}
    	
    }
    
}