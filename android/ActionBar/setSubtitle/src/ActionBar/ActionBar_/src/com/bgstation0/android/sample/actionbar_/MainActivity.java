package com.bgstation0.android.sample.actionbar_;

import android.app.ActionBar;
import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // �A�C�R��, ���S, �^�C�g��, �T�u�^�C�g���̃Z�b�g.
        ActionBar actionBar = getActionBar();				// actionBar���擾.
        actionBar.setIcon(R.drawable.icon1);				// icon1���Z�b�g.
        actionBar.setLogo(R.drawable.logo1);				// logo1���Z�b�g.
        actionBar.setTitle(R.string.title_string);			// title_string���Z�b�g.
        actionBar.setSubtitle(R.string.subtitle_string);	// subtitle_string���Z�b�g.
        
    }
    
}
