package com.bgstation0.android.sample.actionbar.tab_;

import android.app.Fragment;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

public class Fragment1 extends Fragment {
	
	// ビューの生成時
	public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState){
		return inflater.inflate(R.layout.fragment1, container, false);	// inflater.inflateでR.layout.fragment1をもとにViewを作成し, returnで返す.
	}
}
