package com.bgstation0.android.sample.actionbar_;

import android.app.ActionBar;
import android.app.Activity;
import android.os.Bundle;

public class ThirdActivity extends Activity {

	@Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_third);
        
        // �A�C�R�����Z�b�g.
        ActionBar actionBar = getActionBar();	// actionBar���擾.
        actionBar.setIcon(R.drawable.icon1);	// icon1���Z�b�g.
        actionBar.setLogo(R.drawable.logo1);	// logo1���Z�b�g.
        
    }
	
}