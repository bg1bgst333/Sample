package com.bgstation0.android.sample.audiomanager_;

import android.app.Activity;
import android.content.Context;
import android.media.AudioManager;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.Toast;

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
				// AudioManagerの取得.
				AudioManager audioManager = (AudioManager)mContext.getSystemService(AUDIO_SERVICE);	// audioManagerを取得.
				int vol = audioManager.getStreamVolume(AudioManager.STREAM_MUSIC);	// 音楽のボリュームを取得.
				Toast.makeText(mContext, "vol = " + String.valueOf(vol), Toast.LENGTH_LONG).show();	// volの値を表示.
			}
			
        });
        
    }
    
}