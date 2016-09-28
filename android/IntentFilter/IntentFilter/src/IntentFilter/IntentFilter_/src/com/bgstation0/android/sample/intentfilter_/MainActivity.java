package com.bgstation0.android.sample.intentfilter_;

import android.app.Activity;
import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.Toast;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // 送られてきたインテントのUriを表示.
        Intent intent = getIntent();	// getIntentでintentを取得.
        Uri uri = intent.getData();		// intent.getDataでuriを取得.
        Toast.makeText(this, uri.toString(), Toast.LENGTH_LONG).show();	// uriをToastで表示.
        
    }
}
