package com.bgstation0.android.sample.actionbar_;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // �Ǝ��̃A�C�R�����Z�b�g.
        getActionBar().setIcon(R.drawable.icon1);	// icon1���Z�b�g.
        
    }
    
}