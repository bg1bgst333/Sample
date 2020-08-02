package com.bgstation0.android.sample.parcelable_;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.TextView;

// メインアクティビティ
public class MainActivity extends Activity implements OnClickListener{

	// メンバフィールドの定義
	final String KEY_PARCELABLE_STRING = "key_parcelable_string";	// 定数KEY_PARCELABLE_STRINGを定義.
	private CustomParcelable mCustomParcelable;	// CustomParcelableオブジェクトmCustomParcelable.
	
	// アクティビティ生成時
    @Override
    protected void onCreate(Bundle savedInstanceState) {
    	
    	// 既定の処理
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    
        // button1の初期化
        Button button1 = (Button)findViewById(R.id.button1);	// button1を取得.
        button1.setOnClickListener(this);	// thisをセット.
        
    }
    
    // クリックされた時.
    @Override
    public void onClick(View v){
    	
    	// textview1からtextview3まで初期化.
        TextView textview1 = (TextView)findViewById(R.id.textview1);	// textview1を取得.
        TextView textview2 = (TextView)findViewById(R.id.textview2);	// textview2を取得.
        TextView textview3 = (TextView)findViewById(R.id.textview3);	// textview3を取得.
        textview1.setText("ABCDE");	// textview1に"ABCDE"をセット.
        textview2.setText("FGHIJ");	// textview2に"FGHIJ"をセット.
        textview3.setText("KLMNO");	// textview3に"KLMNO"をセット.
        
    }
    
    // アクティビティのインスタンスの一時的な保持が要求された時.
 	@Override
 	protected void onSaveInstanceState(Bundle outState){
 		
 		// 既定の処理
 		super.onSaveInstanceState(outState);	// 親クラスのメソッドを呼ぶ.
 		
 		// TextViewからの取得.
 		TextView textview1 = (TextView)findViewById(R.id.textview1);	// textview1を取得.
 		TextView textview2 = (TextView)findViewById(R.id.textview2);	// textview2を取得.
 		TextView textview3 = (TextView)findViewById(R.id.textview3);	// textview3を取得.
 		String str1 = (String)textview1.getText();	// テキストをstr1に格納.
 		String str2 = (String)textview2.getText();	// テキストをstr2に格納.
 		String str3 = (String)textview3.getText();	// テキストをstr3に格納.
 		
 		// カスタムパーセラブルの生成.
 		mCustomParcelable = new CustomParcelable(str1, str2, str3);	// mCustomParcelableにセット.

 		// 状態を保存.
 		outState.putParcelable(KEY_PARCELABLE_STRING, mCustomParcelable);	// outState.putParcelableでmCustomParcelableを保存.
 		
 	}
 	
	// アクティビティのインスタンスの復元が要求された時.
	@Override
	protected void onRestoreInstanceState(Bundle inState){
	
		// 既定の処理
		super.onRestoreInstanceState(inState);	// 親クラスのメソッドを呼ぶ.
		
		// カスタムパーセラブルの取得.
		mCustomParcelable = inState.getParcelable(KEY_PARCELABLE_STRING);	// inState.getParcelableで取得したパーセラブルをmCustomParcelableに格納.
		if (mCustomParcelable != null){	// nullでなければ.
			
			// TextViewへのセット.
			TextView textview1 = (TextView)findViewById(R.id.textview1);	// textview1を取得.
			TextView textview2 = (TextView)findViewById(R.id.textview2);	// textview2を取得.
			TextView textview3 = (TextView)findViewById(R.id.textview3);	// textview3を取得.
			textview1.setText(mCustomParcelable.getStr1());	// textview1.setTextでmCustomParcelable.getStr1()をセット.
			textview2.setText(mCustomParcelable.getStr2());	// textview2.setTextでmCustomParcelable.getStr2()をセット.
			textview3.setText(mCustomParcelable.getStr3());	// textview3.setTextでmCustomParcelable.getStr3()をセット.
			
		}
		
	}
 	
}