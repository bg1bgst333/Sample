package com.bgstation0.android.sample.fragmentmanager_;

import android.app.Fragment;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

// Fragment2クラスの定義.
public class Fragment2 extends Fragment{
	
	// フラグメントのビュー生成時.
	@Override
	public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState){
		// Fragment2のリソースをベースにレイアウト作成.
		return inflater.inflate(R.layout.fragment2_main, null);	// inflater.inflaceでR.layout.fragment2_mainをベースにレイアウト作成.
	}
}
