package com.bgstation0.android.sample.fragment_;

import android.app.Activity;
import android.app.Fragment;
import android.app.FragmentManager;
import android.app.FragmentTransaction;
import android.os.Bundle;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.Toast;

public class Fragment2 extends Fragment implements View.OnClickListener{

    // メンバフィールド
    static final String TAG = "Fragment2";	// TAGを"Fragment2"で初期化.
	
	// ファクトリメソッド
	public static Fragment2 newInstance(Fragment target){
		
		// Fragment2オブジェクトの生成.
		Fragment2 fragment2 = new Fragment2();	// fragment2を生成.
		fragment2.setTargetFragment(target, 1);	// fragment2.setTargetFragmentでtargeetをセット.
		return fragment2;	// fragment2を返す.
		
	}
	
    // ビュー生成時
    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState){
			
        // ログを残す.
        Log.d(TAG, "Fragment2.onCreateView");	// "Fragment2.onCreateView"とログに残す.
			
        // 既定の処理.
        super.onCreateView(inflater, container, savedInstanceState);
		
        // viewの生成.
        View view = inflater.inflate(R.layout.fragment2_main, null);	// inflater.inflateでR.layout.fragment2_mainからビューを作成.
        Button button2 = (Button)view.findViewById(R.id.fragment2_button);	// button2を取得.
        button2.setOnClickListener(this);	// thisをセット.
        return view;	// viewを返す.
        
    }
    
    // クリックされた時.
    @Override
    public void onClick(View v) {
    	// TODO Auto-generated method stub
    	// ターゲットフラグメントを取得.
    	Fragment targetFragment = getTargetFragment();	// targetFragmentを取得.
        if (targetFragment != null){	// nullでない.
        	Toast.makeText(getActivity(), "targetFragment != null", Toast.LENGTH_LONG).show();	// "targetFragment != null"と表示.
            if (targetFragment instanceof Fragment1){	// Fragment1なら.
                Fragment1 fragment1 = (Fragment1)targetFragment;	// fragment1にキャスト.
                fragment1.customMethod();	// fragment1.customMethodを呼び出す.
             }
        }
        else{	// nullなら.
        	Toast.makeText(getActivity(), "targetFragment == null", Toast.LENGTH_LONG).show();	// "targetFragment == null"と表示.
        }
    }
    
}