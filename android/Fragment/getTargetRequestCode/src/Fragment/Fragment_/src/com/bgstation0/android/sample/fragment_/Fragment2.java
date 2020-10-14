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

    // �����o�t�B�[���h
    static final String TAG = "Fragment2";	// TAG��"Fragment2"�ŏ�����.
	
	// �t�@�N�g�����\�b�h
	public static Fragment2 newInstance(Fragment target){
		
		// Fragment2�I�u�W�F�N�g�̐���.
		Fragment2 fragment2 = new Fragment2();	// fragment2�𐶐�.
		fragment2.setTargetFragment(target, 1);	// fragment2.setTargetFragment��targeet���Z�b�g.
		return fragment2;	// fragment2��Ԃ�.
		
	}
	
    // �r���[������
    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState){
			
        // ���O���c��.
        Log.d(TAG, "Fragment2.onCreateView");	// "Fragment2.onCreateView"�ƃ��O�Ɏc��.
			
        // ����̏���.
        super.onCreateView(inflater, container, savedInstanceState);
		
        // view�̐���.
        View view = inflater.inflate(R.layout.fragment2_main, null);	// inflater.inflate��R.layout.fragment2_main����r���[���쐬.
        Button button2 = (Button)view.findViewById(R.id.fragment2_button);	// button2���擾.
        button2.setOnClickListener(this);	// this���Z�b�g.
        return view;	// view��Ԃ�.
        
    }
    
    // �N���b�N���ꂽ��.
    @Override
    public void onClick(View v) {
    	// TODO Auto-generated method stub
    	// �^�[�Q�b�g�t���O�����g���擾.
    	Fragment targetFragment = getTargetFragment();	// targetFragment���擾.
        if (targetFragment != null){	// null�łȂ�.
        	Toast.makeText(getActivity(), "targetFragment != null", Toast.LENGTH_LONG).show();	// "targetFragment != null"�ƕ\��.
            if (targetFragment instanceof Fragment1){	// Fragment1�Ȃ�.
                Fragment1 fragment1 = (Fragment1)targetFragment;	// fragment1�ɃL���X�g.
                fragment1.customMethod();	// fragment1.customMethod���Ăяo��.
             }
        }
        else{	// null�Ȃ�.
        	Toast.makeText(getActivity(), "targetFragment == null", Toast.LENGTH_LONG).show();	// "targetFragment == null"�ƕ\��.
        }
    }
    
}