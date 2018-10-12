package com.bgstation0.android.sample.ringtonemanager_;

import android.app.Activity;
import android.content.Context;
import android.media.Ringtone;
import android.media.RingtoneManager;
import android.net.Uri;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;

public class MainActivity extends Activity {

	// メンバフィールドの定義.
	Context mContext = null;	// mContextをnullで初期化.
		
	@Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // mContextの初期化.
        mContext = this;	// mContextにthisをセット.
        
        // button1の初期化.
        Button button1 = (Button)findViewById(R.id.button1);	// button1を取得.
        button1.setOnClickListener(new OnClickListener(){

			@Override
			public void onClick(View v) {
				// TODO Auto-generated method stub
				// デフォルトのURIを取得.
				Uri uri = RingtoneManager.getDefaultUri(RingtoneManager.TYPE_RINGTONE);	// デフォルトのuriを取得.
				// 着信音取得.
				Ringtone ringtone = RingtoneManager.getRingtone(mContext, uri);	// ringtoneを取得.
				// 着信音再生.
				ringtone.play();	// ringtone.playで再生.
			}
			
        });
        
    }
    
}