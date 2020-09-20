package com.bgstation0.android.sample.fragment_;

import android.app.Activity;
import android.app.Fragment;
import android.os.Bundle;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.EditText;

//�t���O�����g1
public class Fragment1 extends Fragment {

	// �����o�t�B�[���h
	static final String TAG = "Fragment1";	// TAG��"Fragment1"�ŏ�����.
	
	// �R���X�g���N�^
	public Fragment1(){
		
	}
	
	// �t���O�����g������
	@Override
	public void onCreate(Bundle savedInstanceState){
		
		// ����̏���.
		super.onCreate(savedInstanceState);	// �e�N���X��onCreate���Ă�.
		
		// ���O���c��.
		Log.d(TAG, "Fragment1.onCreate");	// "Fragment1.onCreate"�ƃ��O�Ɏc��.
		
	}
	
	// �t���O�����g�j����
	@Override
	public void onDestroy(){
		
		// ���O���c��.
		Log.d(TAG, "Fragment1.onDestroy");	// "Fragment1.onDestroy"�ƃ��O�Ɏc��.
		
		// ����̏���.
		super.onDestroy();	// �e�N���X��onDestroy���Ă�.
		
	}
	
	// �r���[������
	@Override
	public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState){
		
		// ���O���c��.
		Log.d(TAG, "Fragment1.onCreateView");	// "Fragment1.onCreateView"�ƃ��O�Ɏc��.
		
		// MainActivity��EditText�̓��e���擾.
		Activity mainActivity = getActivity();	// mainActivity���擾.
		EditText mainEdittext1 = (EditText)mainActivity.findViewById(R.id.edittext1);	// mainEdittext1���擾.
		Log.d(TAG, "mainEdittext1 = " + mainEdittext1.getText().toString());	// mainEdittext1�����O�o��.
		
		// ����̏���.
		return inflater.inflate(R.layout.fragment1_main, null);	// inflater.inflate��R.layout.fragment1_main����r���[���쐬��, ���̂܂ܕԂ�.
		
	}
	
}