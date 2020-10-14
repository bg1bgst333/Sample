package com.bgstation0.android.sample.fragmenttransaction_;

import android.app.Fragment;
import android.os.Bundle;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

public class Fragment1 extends Fragment {

    // �����o�t�B�[���h
    static final String TAG = "Fragment1";	// TAG��"Fragment1"�ŏ�����.
	
    // �r���[������
    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState){
			
        // ���O���c��.
        Log.d(TAG, "Fragment1.onCreateView");	// "Fragment1.onCreateView"�ƃ��O�Ɏc��.
			
        // ����̏���.
        super.onCreateView(inflater, container, savedInstanceState);
		
        // Fragment1��EditText���擾.
        View view = inflater.inflate(R.layout.fragment1_main, null);	// inflater.inflate��R.layout.fragment1_main����r���[���쐬.
        return view;	// view��Ԃ�.
        
    }
    
    // �t���O�����g�̃r���[�j����
    @Override
    public void onDestroyView(){
    
    	// ���O���c��.
    	Log.d(TAG, "Fragment1.onDestroyView");	// "Fragment1.onDestroyView"�ƃ��O�Ɏc��.
    	
    	// ����̏���.
    	super.onDestroyView();	// �e�N���X��onDestroyView���Ă�.
    	
    }
    
    // �t���O�����g�j����
    @Override
    public void onDestroy(){
    	
    	// ���O���c��.
    	Log.d(TAG, "Fragment1.onDestroy");	// "Fragment1.onDestroy"�ƃ��O�Ɏc��.
    	
    	// ����̏���.
    	super.onDestroy();	// �e�N���X��onDestroy���Ă�.
    	
    }
    
}