package com.bgstation0.android.sample.activity_;

import android.app.Activity;
import android.content.SharedPreferences;
import android.content.SharedPreferences.Editor;
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
        
        // button_save_prefを取得し, OnClickListenerとして自身をセット.
        Button saveButton = (Button)findViewById(R.id.button_save_pref);	// findViewByIdでR.id.button_save_prefを取得.
        saveButton.setOnClickListener(this);	// saveButton.setOnClickListenerでthis(自身)をセット. 
    }
    
    // View.OnClickListenerインタフェースのオーバーライドメソッドを実装.
    public void onClick(View v){	// onClickをオーバーライド.
    	// エディットテキストの文字列を取得.
    	EditText editPref = (EditText)findViewById(R.id.edit_pref);	// findViewByIdでR.id.edit_prefを取得し, editPrefに格納.
    	CharSequence str = editPref.getText();	// editPref.getTextでエディットテキストの文字列を取得し, CharSequenceのstrに格納.(実際には, EditTextの親クラスのTextViewのgetTextを呼び出している.)
    	// プリファレンスを取得し, それに入力値を保存.
    	SharedPreferences prefs = getPreferences(MODE_PRIVATE);	// getPreferencesでSharedPreferencesを取得.
    	Editor editor = prefs.edit();	// prefs.editでEditorオブジェクトeditor取得.
    	editor.putString("Key", str.toString());	// putStringでキーが"Key", 値がstrで書き込み.
    	editor.commit();	// commitで確定.
    }
}
