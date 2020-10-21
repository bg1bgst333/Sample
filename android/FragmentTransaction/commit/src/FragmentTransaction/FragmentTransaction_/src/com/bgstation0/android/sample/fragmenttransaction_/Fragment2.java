package com.bgstation0.android.sample.fragmenttransaction_;

import android.app.Fragment;
import android.os.Bundle;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

public class Fragment2 extends Fragment {

    // �����o�t�B�[���h
    static final String TAG = "Fragment2";	// TAG��"Fragment2"�ŏ�����.
	
    // �r���[������
    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState){
			
        // ���O���c��.
        Log.d(TAG, "Fragment2.onCreateView");	// "Fragment2.onCreateView"�ƃ��O�Ɏc��.
			
        // ����̏���.
        super.onCreateView(inflater, container, savedInstanceState);
		
        // Fragment2��EditText���擾.
        View view = inflater.inflate(R.layout.fragment2_main, null);	// inflater.inflate��R.layout.fragment2_main����r���[���쐬.
        return view;	// view��Ԃ�.
        
    }
    
}