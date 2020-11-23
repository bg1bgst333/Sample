package com.bgstation0.android.sample.fragmentstatepageradapter_;

import android.support.v4.app.Fragment;
import android.support.v4.app.FragmentManager;
import android.support.v4.app.FragmentStatePagerAdapter;

public class CustomFragmentStatePagerAdapter extends FragmentStatePagerAdapter {

	public CustomFragmentStatePagerAdapter(FragmentManager fm) {
		super(fm);
		// TODO Auto-generated constructor stub
	}

	@Override
	public Fragment getItem(int arg0) {
		// TODO Auto-generated method stub
		switch (arg0){
		case 0:
			return CustomFragment.newInstance("Zero");
		case 1:
			return CustomFragment.newInstance("One");
		case 2:
			return CustomFragment.newInstance("Two");
		case 3:
			return CustomFragment.newInstance("Three");
		case 4:
			return CustomFragment.newInstance("Four");
		}
		return null;
	}

	@Override
	public int getCount() {
		// TODO Auto-generated method stub
		return 5;	// Fragment‚ª5‚Â‚È‚Ì‚Å5‚ð•Ô‚·.
	}

}