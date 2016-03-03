package com.bgstation0.android.sample.edittext_;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.EditText;
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
    	// エディットテキストの文字列を取得し, トーストで表示.
    	EditText edittext1 = (EditText)findViewById(R.id.edittext1);	// findViewByIdでR.id.edittext1を取得し, edittext1に格納.
    	CharSequence str = edittext1.getText();	// edittext1.getTextでエディットテキストの文字列を取得し, CharSequenceのstrに格納.(実際には, EditTextの親クラスのTextViewのgetTextを呼び出している.)
    	Toast.makeText(this, str, Toast.LENGTH_SHORT).show();	// Toast.makeTextでstrをセットし,　そのままshowで表示.
    }
}
