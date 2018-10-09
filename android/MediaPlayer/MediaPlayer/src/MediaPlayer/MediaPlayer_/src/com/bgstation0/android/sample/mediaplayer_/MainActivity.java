package com.bgstation0.android.sample.mediaplayer_;

import android.app.Activity;
import android.media.MediaPlayer;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;

public class MainActivity extends Activity {
	
	// メンバフィールドの定義.
	MediaPlayer mMediaPlayer = null;	// mMediaPlayerをnullで初期化.
	
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // button1の初期化.
        Button button1 = (Button)findViewById(R.id.button1);	// button1を取得.
        button1.setOnClickListener(new OnClickListener(){

			@Override
			public void onClick(View v) {
				// TODO Auto-generated method stub
				if (v.getId() == R.id.button1){
					mMediaPlayer.start();	// 再生.
				}
			}
			
		});
        
        // メディアをリソースからロード.
        mMediaPlayer = MediaPlayer.create(this, R.raw.eine);	// eineをロード.
        
    }
    
}