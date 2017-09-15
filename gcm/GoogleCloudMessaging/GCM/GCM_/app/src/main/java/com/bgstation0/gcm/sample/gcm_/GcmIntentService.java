package com.bgstation0.gcm.sample.gcm_;

import android.app.IntentService;
import android.content.Intent;
import android.icu.text.LocaleDisplayNames;
import android.os.Bundle;
import android.util.Log;

import com.google.android.gms.gcm.GoogleCloudMessaging;

/**
 * Created by bg1 on 2017/09/15.
 */

public class GcmIntentService extends IntentService {
    private static final String TAG = "GcmIntentService";
    public GcmIntentService() {
        super("GcmIntentService");
    }
    @Override
    protected void onHandleIntent(Intent intent) {
        Bundle extras = intent.getExtras();
        GoogleCloudMessaging gcm = GoogleCloudMessaging.getInstance(this);
        String messageType = gcm.getMessageType(intent);
        if (!extras.isEmpty()) {
            Log.d(TAG, "messageType: " + messageType + ", extras" + extras.toString());
        }
        GcmBroadcastReceiver.completeWakefulIntent(intent);
    }
}
