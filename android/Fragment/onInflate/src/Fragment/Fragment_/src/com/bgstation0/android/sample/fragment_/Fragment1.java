package com.bgstation0.android.sample.fragment_;

import android.app.Activity;
import android.app.Fragment;
import android.content.res.Resources;
import android.content.res.TypedArray;
import android.os.Bundle;
import android.util.AttributeSet;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

//フラグメント1
public class Fragment1 extends Fragment {

	// メンバフィールド
	static final String TAG = "Fragment1";	// TAGを"Fragment1"で初期化.
	String mCustomData = "";	// mCustomDataを""で初期化.
	
	// コンストラクタ
	public Fragment1(){
		
	}
	
	// レイアウトXML情報取得時
	@Override
	public void onInflate(Activity activity, AttributeSet attrs, Bundle savedInstanceState){
		
		// 既定の処理.
		super.onInflate(activity, attrs, savedInstanceState);	// 親クラスのonInflateを呼ぶ.
		
		// ログを残す.
		Log.d(TAG, "Fragment1.onInflate");	// "Fragment1.onInflate"とログに残す.
		
		// 属性の取得.
		Resources res = activity.getResources();	// resの取得.
		TypedArray a = res.obtainAttributes(attrs, R.styleable.Fragment1);	// aの取得.
		mCustomData = a.getString(R.styleable.Fragment1_custom_data);	// mCustomDataの取得.
		
	}
	
	// フラグメント生成時
	@Override
	public void onCreate(Bundle savedInstanceState){
		
		// 既定の処理.
		super.onCreate(savedInstanceState);	// 親クラスのonCreateを呼ぶ.
		
		// ログを残す.
		Log.d(TAG, "Fragment1.onCreate");	// "Fragment1.onCreate"とログに残す.
		
	}
	
	// フラグメント破棄時
	@Override
	public void onDestroy(){
		
		// ログを残す.
		Log.d(TAG, "Fragment1.onDestroy");	// "Fragment1.onDestroy"とログに残す.
		
		// 既定の処理.
		super.onDestroy();	// 親クラスのonDestroyを呼ぶ.
		
	}
	
	// ビュー生成時
	@Override
	public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState){
		
		// ログを残す.
		Log.d(TAG, "Fragment1.onCreateView");	// "Fragment1.onCreateView"とログに残す.
		
		// 既定の処理.
		super.onCreateView(inflater, container, savedInstanceState);
		
		// viewを生成し, 返す..
		View view = inflater.inflate(R.layout.fragment1_main, null);	// inflater.inflateでR.layout.fragment1_mainからビューを作成.
		return view;	// viewを返す.
		
	}
	
	// ビュー生成完了時.
	@Override
	public void onViewCreated(View view, Bundle savedInstanceState){
	
		// ログを残す.
		Log.d(TAG, "Fragment1.onViewCreated");	// "Fragment1.onViewCreated"とログに残す.
				
		// 既定の処理.
		super.onViewCreated(view, savedInstanceState);
	
		// mCustomDataのセット.
		TextView textview1 = (TextView)view.findViewById(R.id.fragment1_textview);	// textview1の取得.
		textview1.setText(mCustomData);	// textview1.setTextでmCustomDataをセット.
		
	}
	
	// アクティビティ生成完了時
	@Override
	public void onActivityCreated(Bundle savedInstanceState){
		
		// ログを残す.
		Log.d(TAG, "Fragment1.onActivityCreated");	// "Fragment1.onActivityCreated"とログに残す.
				
		// 既定の処理.
		super.onActivityCreated(savedInstanceState);
		
	}
	
}
