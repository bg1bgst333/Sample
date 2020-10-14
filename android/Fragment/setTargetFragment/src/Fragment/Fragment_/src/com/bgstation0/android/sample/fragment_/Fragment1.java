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

public class Fragment1 extends Fragment implements View.OnClickListener{

    // �����o�t�B�[���h
    static final String TAG = "Fragment1";	// TAG��"Fragment1"�ŏ�����.
	
	// �t�@�N�g�����\�b�h
	public static Fragment1 newInstance(){
		
		// Fragment1�I�u�W�F�N�g�̐���.
		Fragment1 fragment1 = new Fragment1();	// fragment1�𐶐�.
		return fragment1;	// fragment1��Ԃ�.
		
	}
	
    // �r���[������
    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState){
			
        // ���O���c��.
        Log.d(TAG, "Fragment1.onCreateView");	// "Fragment1.onCreateView"�ƃ��O�Ɏc��.
			
        // ����̏���.
        super.onCreateView(inflater, container, savedInstanceState);
		
        // Fragment1��Button���擾.
        View view = inflater.inflate(R.layout.fragment1_main, null);	// inflater.inflate��R.layout.fragment1_main����r���[���쐬.
        Button button1 = (Button)view.findViewById(R.id.fragment1_button);	// button1���擾.
        button1.setOnClickListener(this);	// this���Z�b�g.
        return view;	// view��Ԃ�.
        
    }
    
    // �N���b�N���ꂽ��.
    @Override
    public void onClick(View v) {
    	// TODO Auto-generated method stub
    	// �e�̃A�N�e�B�r�e�B���擾.
    	Activity activity = getActivity();	// getActivity��activity���擾.
    	if (activity !=null){	// null�łȂ�.
    		FragmentManager fragmentManager = activity.getFragmentManager();	// fragmentManager���擾.
    		FragmentTransaction fragmentTransaction = fragmentManager.beginTransaction();	// fragmentTransaction���擾.
    		Fragment2 fragment2 = Fragment2.newInstance(this);	// fragment2�𐶐�.(�^�[�Q�b�g�ɌĂяo����this���Z�b�g.)
        	fragmentTransaction.add(R.id.framelayout1, fragment2);	// fragment2��ǉ�.
        	fragmentTransaction.commit();	// �m��.
    	}
    }
    
    // �Ǝ����\�b�hcustomMethod.
    public void customMethod(){
    	// �e�̃A�N�e�B�r�e�B���擾.
    	Activity activity = getActivity();	// getActivity��activity���擾.
        if (activity !=null){	// null�łȂ�.
            // �g�[�X�g�\��.
            Toast.makeText(activity, "customMethod!", Toast.LENGTH_LONG).show();	// "customMethod!"�ƕ\��.
    	}
    }
    
}