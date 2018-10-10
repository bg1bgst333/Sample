package com.bgstation0.android.sample.notificationmanager_;

import android.app.Activity;
import android.app.Notification;
import android.app.NotificationManager;
import android.content.Context;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.Toast;

public class MainActivity extends Activity {

	// メンバフィールドの定義.
	NotificationManager mNotificationManager = null;	// mNotificationManagerをnullで初期化.
	int mNumber = 0;	// mNumberを0で初期化.
	Context mContext = null;	// mContextをnullで初期化.
	
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // mContextの初期化.
        mContext = this;	// mContextにthisをセット.
        
        // NotificationManagerの取得.
        mNotificationManager = (NotificationManager)getSystemService(NOTIFICATION_SERVICE);	// mNotificationManagerを取得.

        // button1の初期化.
        Button button1 = (Button)findViewById(R.id.button1);	// button1を取得.
        button1.setOnClickListener(new OnClickListener(){

			@Override
			public void onClick(View v) {
				// TODO Auto-generated method stub
				if (v.getId() == R.id.button1){
					// Notificationを生成.
					Notification notification = new Notification();	// notificationを生成.
					notification.tickerText = "NotificationManager";	// チケットテキストは"NotificationManager".
					notification.icon = R.drawable.ic_launcher;	// アイコンはic_launcher.
					notification.number = mNumber;	// mNumberをセット.
					notification.setLatestEventInfo(getApplicationContext(), "NotificationManager", "notify", null);	// イベント.(これがないと落ちる.しかしdeprecateされてる.今回は実行するintentを指定しない.)
					mNotificationManager.notify(mNumber, notification);	// mNotificationManager.notifyで通知.
					mNumber++;	// mNumberを増やす.					
				}
			}
		});
        
    }
    
}