package com.bgstation0.android.sample.fragment_;

import android.app.Fragment;
import android.os.Bundle;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

// フラグメント1
public class Fragment2 extends Fragment {

	// メンバフィールド
	static final String TAG = "Fragment2";	// TAGを"Fragment2"で初期化.
	
	// コンストラクタ
	public Fragment2(){
		
	}
	
	// フラグメント生成時
	@Override
	public void onCreate(Bundle savedInstanceState){
		
		// 既定の処理.
		super.onCreate(savedInstanceState);	// 親クラスのonCreateを呼ぶ.
		
		// ログを残す.
		Log.d(TAG, "Fragment2.onCreate");	// "Fragment2.onCreate"とログに残す.
		
	}
	
	// フラグメント破棄時
	@Override
	public void onDestroy(){
			
		// ログを残す.
		Log.d(TAG, "Fragment2.onDestroy");	// "Fragment2.onDestroy"とログに残す.
		
		// 既定の処理.
		super.onDestroy();	// 親クラスのonDestroyを呼ぶ.
				
	}
	
	// ビュー生成時
	@Override
	public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState){
		
		// ログを残す.
		Log.d(TAG, "Fragment2.onCreateView");	// "Fragment2.onCreateView"とログに残す.
				
		// 既定の処理.
		return inflater.inflate(R.layout.fragment2_main, null);	// inflater.inflateでR.layout.fragment2_mainからビューを作成し, そのまま返す.
		
	}
	
}