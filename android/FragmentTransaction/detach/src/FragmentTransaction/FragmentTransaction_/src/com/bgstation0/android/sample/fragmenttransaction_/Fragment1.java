package com.bgstation0.android.sample.fragmenttransaction_;

import android.app.Fragment;
import android.os.Bundle;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

public class Fragment1 extends Fragment {

    // メンバフィールド
    static final String TAG = "Fragment1";	// TAGを"Fragment1"で初期化.
	
    // ビュー生成時
    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState){
			
        // ログを残す.
        Log.d(TAG, "Fragment1.onCreateView");	// "Fragment1.onCreateView"とログに残す.
			
        // 既定の処理.
        super.onCreateView(inflater, container, savedInstanceState);
		
        // Fragment1のEditTextを取得.
        View view = inflater.inflate(R.layout.fragment1_main, null);	// inflater.inflateでR.layout.fragment1_mainからビューを作成.
        return view;	// viewを返す.
        
    }
    
    // フラグメントのビュー破棄時
    @Override
    public void onDestroyView(){
    
    	// ログを残す.
    	Log.d(TAG, "Fragment1.onDestroyView");	// "Fragment1.onDestroyView"とログに残す.
    	
    	// 既定の処理.
    	super.onDestroyView();	// 親クラスのonDestroyViewを呼ぶ.
    	
    }
    
    // フラグメント破棄時
    @Override
    public void onDestroy(){
    	
    	// ログを残す.
    	Log.d(TAG, "Fragment1.onDestroy");	// "Fragment1.onDestroy"とログに残す.
    	
    	// 既定の処理.
    	super.onDestroy();	// 親クラスのonDestroyを呼ぶ.
    	
    }
    
    // デタッチ時
    @Override
    public void onDetach(){
    	
    	// ログを残す.
    	Log.d(TAG, "Fragment1.onDetach");	// "Fragment1.onDetach"とログに残す.
    	
    	// 既定の処理.
    	super.onDetach();	// 親クラスのonDetachを呼ぶ.
    	
    }
    
}