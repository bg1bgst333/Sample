package com.bgstation0.android.sample.pendingintent_;

import java.util.Calendar;

import android.app.Activity;
import android.app.AlarmManager;
import android.app.PendingIntent;
import android.content.Intent;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // "CUSTOM_ACTION"に反応するIntentの作成.
        Intent intent = new Intent("CUSTOM_ACTION");	// "CUSTOM_ACTION"に反応するintentを作成.
        
        // intentを遅れて実行するPendingIntentの作成.
        PendingIntent pendingIntent = PendingIntent.getBroadcast(this, 1, intent, 0);	// PendingIntent.getBroadcastでintentに指定したアクションを遅れて実行するpendingIntentを作成.

        // Calendarに5秒後の時刻をセット.
        Calendar calendar = Calendar.getInstance();	// Calendar.getInstanceでインスタンスcalendarを取得.
        calendar.setTimeInMillis(System.currentTimeMillis());	// System.currentTimeMillis()で現在時刻を取得し, それをcalendar.setTimeInMillisでcalendarにセット.
        calendar.add(Calendar.SECOND, 5);	// calendar.addで5秒後にセット.
        
        // AlarmManagerにpendingIntentとcalendarをセット.
        AlarmManager alarmManager = (AlarmManager)getSystemService(ALARM_SERVICE);	// getSystemService(ALARM_SERVICE)でalarmManagerを取得.
        alarmManager.set(AlarmManager.RTC, calendar.getTimeInMillis(), pendingIntent);	// alarmManager.setでcalendar.getTimeInMillisとpendingIntentをセットし, これでアラームセット完了.
        
    }
}
