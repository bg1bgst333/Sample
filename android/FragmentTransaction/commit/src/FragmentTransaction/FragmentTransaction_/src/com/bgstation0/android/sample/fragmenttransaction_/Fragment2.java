package com.bgstation0.android.sample.fragmenttransaction_;

import android.app.Fragment;
import android.os.Bundle;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

public class Fragment2 extends Fragment {

    // メンバフィールド
    static final String TAG = "Fragment2";	// TAGを"Fragment2"で初期化.
	
    // ビュー生成時
    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState){
			
        // ログを残す.
        Log.d(TAG, "Fragment2.onCreateView");	// "Fragment2.onCreateView"とログに残す.
			
        // 既定の処理.
        super.onCreateView(inflater, container, savedInstanceState);
		
        // Fragment2のEditTextを取得.
        View view = inflater.inflate(R.layout.fragment2_main, null);	// inflater.inflateでR.layout.fragment2_mainからビューを作成.
        return view;	// viewを返す.
        
    }
    
}