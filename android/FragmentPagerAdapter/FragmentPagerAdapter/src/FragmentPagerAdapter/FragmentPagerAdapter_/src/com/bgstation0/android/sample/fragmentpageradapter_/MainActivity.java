package com.bgstation0.android.sample.fragmentpageradapter_;

import android.os.Bundle;
import android.support.v4.app.FragmentActivity;
import android.support.v4.view.ViewPager;
import android.view.Menu;
import android.view.MenuItem;

public class MainActivity extends FragmentActivity{	// support.v4のFragmentActivityにする必要がある.

	// 生成時.
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        
    	// 既定の処理.
    	super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // ViewPagerの初期化.
        ViewPager viewPager = (ViewPager)findViewById(R.id.viewpager);	// viewPagerの取得.
        CustomFragmentPagerAdapter cfpa = new CustomFragmentPagerAdapter(getSupportFragmentManager());	// cfpaを生成.
        viewPager.setAdapter(cfpa);	// viewPagerにcfpaをセット.
        
    }
    
}