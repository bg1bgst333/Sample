package com.bgstation0.android.sample.fragment_;

import android.app.Fragment;
import android.os.Bundle;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

public class CustomFragment extends Fragment {

	// public�Ȉ����Ȃ��R���X�g���N�^.
	public CustomFragment(){
		Log.d("testtag", "test1234");
	}
	
	// �t���O�����g�̃r���[������.
	@Override
	public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState){
	
		// �r���[�̐���.
		return inflater.inflate(R.layout.customfragment_main, null);	// inflate�Ő�������View��Ԃ�.
		
	}
	
}
