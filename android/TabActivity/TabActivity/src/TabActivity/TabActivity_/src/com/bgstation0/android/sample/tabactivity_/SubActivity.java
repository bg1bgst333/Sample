package com.bgstation0.android.sample.tabactivity_;

import android.app.Activity;
import android.os.Bundle;
import android.widget.TextView;

public class SubActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_sub);
        
        // Bundleをチェック.
        Bundle args = getIntent().getExtras();	// args取得.
        if (args != null){	// nullでない.
	        String tag = args.getString("tag");	// tag取得.
	        if (tag.equals("Activity3")){	// "Activity3"の時.
	        	TextView tv = (TextView)findViewById(R.id.textview_sub);	// tv取得.
	        	tv.setText("Activity3 Text.");	// "Activity3 Text."をセット.
	        }
        }
    }
    
}
