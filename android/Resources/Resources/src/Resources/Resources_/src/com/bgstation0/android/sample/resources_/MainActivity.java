package com.bgstation0.android.sample.resources_;

import android.app.Activity;
import android.content.res.Resources;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.Toast;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // Resources‚©‚çhello_world‚ðŽæ“¾‚µ‚ÄToast‚Å•\Ž¦.
        Resources res = getResources();	// getResources‚Åres‚ðŽæ“¾.
        String strHello = res.getString(R.string.hello_world);	// res.getString‚ÅR.string.hello_world‚É’è‹`‚³‚ê‚Ä‚¢‚é•¶Žš—ñ‚ðŽæ“¾.
        Toast.makeText(this, strHello, Toast.LENGTH_LONG).show();	// strHello‚ðToast‚Å•\Ž¦.
        
    }
}
