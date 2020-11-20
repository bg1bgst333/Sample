package com.bgstation0.android.sample.fragmentpageradapter_;

import android.os.Bundle;
import android.support.v4.app.FragmentActivity;
import android.support.v4.view.ViewPager;
import android.view.Menu;
import android.view.MenuItem;

public class MainActivity extends FragmentActivity{	// support.v4��FragmentActivity�ɂ���K�v������.

	// ������.
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        
    	// ����̏���.
    	super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // ViewPager�̏�����.
        ViewPager viewPager = (ViewPager)findViewById(R.id.viewpager);	// viewPager�̎擾.
        CustomFragmentPagerAdapter cfpa = new CustomFragmentPagerAdapter(getSupportFragmentManager());	// cfpa�𐶐�.
        viewPager.setAdapter(cfpa);	// viewPager��cfpa���Z�b�g.
        
    }
    
}