package com.bgstation0.android.sample.resources_;

import android.app.Activity;
import android.content.res.Resources;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.TextView;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // Resourcesから文字列を取得してTextViewにセット.
        Resources res = getResources();	// getResourcesでresを取得.
        String strTextView1 = res.getString(R.string.textview1_text);	// res.getStringでR.string.textview1_textに定義されている文字列を取得.
        TextView textView1 = (TextView)findViewById(R.id.textview1);	// textView1を取得.
        textView1.setText(strTextView1);	// textView1.setTextでstrTextView1をセット.
        String strTextView2 = res.getString(R.string.textview2_text);	// res.getStringでR.string.textview2_textに定義されている文字列を取得.
        TextView textView2 = (TextView)findViewById(R.id.textview2);	// textView2を取得.
        textView2.setText(strTextView2);	// textView2.setTextでstrTextView2をセット.
        String strTextView3 = res.getString(R.string.textview3_text);	// res.getStringでR.string.textview3_textに定義されている文字列を取得.
        TextView textView3 = (TextView)findViewById(R.id.textview3);	// textView3を取得.
        textView3.setText(strTextView3);	// textView3.setTextでstrTextView3をセット.
        
    }
}
