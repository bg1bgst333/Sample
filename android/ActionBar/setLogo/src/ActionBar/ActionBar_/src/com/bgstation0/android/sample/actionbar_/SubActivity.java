package com.bgstation0.android.sample.actionbar_;

import android.app.ActionBar;
import android.app.Activity;
import android.os.Bundle;

public class SubActivity extends Activity {

	@Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_sub);
        
        // �A�C�R�����Z�b�g.
        ActionBar actionBar = getActionBar();	// actionBar���擾.
        actionBar.setIcon(R.drawable.icon1);	// icon1���Z�b�g.
        
    }
	
}