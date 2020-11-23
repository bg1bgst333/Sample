package com.bgstation0.android.sample.fragmentstatepageradapter_;

import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

//カスタムフラグメント
public class CustomFragment extends Fragment {

	// メンバフィールドの定義.
	String mText = "";	// mTextを""で初期化.
	
	// 生成メソッド.
	public static CustomFragment newInstance(String text){
		CustomFragment customFragment = new CustomFragment();	// customFragmentを生成.
		Bundle args = new Bundle();	// argsを生成.
		args.putString("text", text);	// textを登録.
		customFragment.setArguments(args);	// argsをセット.
		return customFragment;	// customFragmentを返す.
	}
	
	// ビューの生成.
	@Override
	public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState){
		super.onCreateView(inflater, container, savedInstanceState);
		View view = inflater.inflate(R.layout.custom_fragment_main, null);	// Viewを生成.
		TextView customFragmentTextView1 = (TextView)view.findViewById(R.id.custom_fragment_textview1);	// customFragmentTextView1を取得.
		if (savedInstanceState == null){	// nullの時は引数から取る.
			Bundle args = getArguments();	// argsを取得.
			mText = args.getString("text");	// mTextを取得.
			Log.d("FragmentStatePagerAdapter", "savedInstanceState == null(" + mText + ")");
		}
		else{	// nullでない時は, 保存しておいたものを取る.
			mText = savedInstanceState.getString("text");	// mTextを取得.
			Log.d("FragmentStatePagerAdapter", "savedInstanceState != null(" + mText + ")");
		}
		customFragmentTextView1.setText(mText);	// mTextをセット.
		return view;	// viewを返す.
	}
	
	// 状態保存時.
	@Override
	public void onSaveInstanceState(Bundle outState){
		super.onSaveInstanceState(outState);
		outState.putString("text", mText);	// mTextを保存.
	}
	
}