package com.bgstation0.android.sample.alarmmanager_;

import java.util.Calendar;

import android.app.Activity;
import android.app.AlarmManager;
import android.app.PendingIntent;
import android.content.Intent;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;

public class MainActivity extends Activity {

	// メンバフィールドの定義
	CustomReceiver customReceiver;	// CustomReceiver型レシーバーcustomReceiver.
	
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
 
        // customReceiverの作成.
        customReceiver = new CustomReceiver();	// CustomReceiverオブジェクトcustomReceiverの作成.
        
        // SubActivtyを起動するIntentの作成.
        Intent intent = new Intent(getApplicationContext(), SubActivity.class);	// SubActivityを起動するintentを作成.
        
        // intentを遅れて実行するPendingIntentの作成.
        PendingIntent pendingIntent = PendingIntent.getActivity(this, 0, intent, 0);	// PendingIntent.getActivityでintentに指定したアクティビティを遅れて実行するpendingIntentを作成.
        
        // Calendarに5秒後の時刻をセット.
        Calendar calendar = Calendar.getInstance();	// Calendar.getInstanceでインスタンスcalendarを取得.
        calendar.setTimeInMillis(System.currentTimeMillis());	// System.currentTimeMillis()で現在時刻を取得し, それをcalendar.setTimeInMillisでcalendarにセット.
        calendar.add(Calendar.SECOND, 5);	// calendar.addで5秒後にセット.
        
        // AlarmManagerにpendingIntentとcalendarをセット.
        AlarmManager alarmManager = (AlarmManager)getSystemService(ALARM_SERVICE);	// getSystemService(ALARM_SERVICE)でalarmManagerを取得.
        alarmManager.set(AlarmManager.RTC, calendar.getTimeInMillis(), pendingIntent);	// alarmManager.setでcalendar.getTimeInMillisとpendingIntentをセットし, これでアラームセット完了.
        
    }
}
