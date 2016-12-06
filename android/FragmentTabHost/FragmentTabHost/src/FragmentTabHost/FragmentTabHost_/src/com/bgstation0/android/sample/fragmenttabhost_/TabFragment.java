package com.bgstation0.android.sample.fragmenttabhost_;

import android.support.v4.app.Fragment;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

public class TabFragment extends Fragment {

	// ビューの生成時
	public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState){
		View view = inflater.inflate(R.layout.fragment_tab, container, false);	// inflater.inflateでR.layout.fragment_tabをもとにViewを作成.
		Bundle bundle = getArguments();	// bundleを取得.
		String name = bundle.getString("name");	// nameを取得.
		TextView textView = (TextView)view.findViewById(R.id.tab_textview);	// textViewを取得.
		textView.setText(name);	// textViewにnameをセット.
		return view;	// viewを返す.
	}
	
}
