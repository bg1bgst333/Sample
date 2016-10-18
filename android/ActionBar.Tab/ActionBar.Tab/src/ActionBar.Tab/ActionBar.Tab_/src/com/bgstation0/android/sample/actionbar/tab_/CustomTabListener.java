package com.bgstation0.android.sample.actionbar.tab_;

import android.app.ActionBar;
import android.app.ActionBar.TabListener;
import android.app.Activity;
import android.app.Fragment;
import android.app.FragmentTransaction;

public class CustomTabListener<T extends Fragment> implements ActionBar.TabListener {

	// メンバフィールドの定義.
	private Activity activity = null;	// Activity型activityをnullにセット.
	private String tag = null;	// String型tagをnullにセット.
	private Class<T> c = null;	// Class<T>型cをnullにセット.
	
	// コンストラクタ
	public CustomTabListener(Activity activity, String tag, Class<T> c){
		// パラメータをセット.
		this.activity = activity;
		this.tag = tag;
		this.c = c;
	}
	
	// タブの選択時
	public void onTabSelected(ActionBar.Tab tab, FragmentTransaction ft) {
		// フラグメントがあるか探す.
		Fragment f = activity.getFragmentManager().findFragmentByTag(tag);	// findFragmentByTagでtagなfragmentがあるか探す.
		if (f == null){	// なければ追加.
			f = Fragment.instantiate(activity, c.getName());	// Fragment.instantiateでfを生成.
			activity.getFragmentManager().beginTransaction().add(R.id.framelayout1, f, tag).show(f).commit();	// fを追加して表示して確定.
		}
		else{	// あれば表示.
			activity.getFragmentManager().beginTransaction().show(f).commit();	// showで表示.
		}
	}

	// タブの選択解除時
	public void onTabUnselected(ActionBar.Tab tab, FragmentTransaction ft) {
		// フラグメントがあるか探して非表示.
		Fragment f = activity.getFragmentManager().findFragmentByTag(tag);	// findFragmentByTagでtagなfragmentがあるか探す.
		activity.getFragmentManager().beginTransaction().hide(f).commit();	// hideで非表示.
	}
	
	// タブの再選択時
	public void onTabReselected(ActionBar.Tab tab, FragmentTransaction ft) {
		// フラグメントがあるか探して表示.
		Fragment f = activity.getFragmentManager().findFragmentByTag(tag);	// findFragmentByTagでtagなfragmentがあるか探す.
		activity.getFragmentManager().beginTransaction().show(f).commit();	// showで表示.
	}
}
