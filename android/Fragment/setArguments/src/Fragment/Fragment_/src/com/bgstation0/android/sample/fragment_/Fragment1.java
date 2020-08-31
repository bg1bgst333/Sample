package com.bgstation0.android.sample.fragment_;

import android.app.Activity;
import android.app.Fragment;
import android.os.Bundle;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.view.ViewParent;
import android.widget.EditText;

//�t���O�����g1
public class Fragment1 extends Fragment {

	// �����o�t�B�[���h
	static final String TAG = "Fragment1";	// TAG��"Fragment1"�ŏ�����.
	public static final String KEY = "key";	// �n�������̃L�[��"key"�Ƃ���.
	
	// �R���X�g���N�^
	public Fragment1(){
		
	}
	
	// �t�@�N�g�����\�b�h
	public static Fragment1 newInstance(String value){
		
		// Fragment1�I�u�W�F�N�g�̐���.
		Fragment1 fragment1 = new Fragment1();	// fragment1�𐶐�.
		Bundle args = new Bundle();	// args���쐬.
		args.putString(Fragment1.KEY, value);	// value��o�^.
		fragment1.setArguments(args);	// fragment1.setArguments��args���Z�b�g.
		return fragment1;	// fragment1��Ԃ�.
		
	}
	
	// �t���O�����g������
	@Override
	public void onCreate(Bundle savedInstanceState){
		
		// ����̏���.
		super.onCreate(savedInstanceState);	// �e�N���X��onCreate���Ă�.
		
		// ���O���c��.
		Log.d(TAG, "Fragment1.onCreate");	// "Fragment1.onCreate"�ƃ��O�Ɏc��.
		
		// �������擾.
		Bundle args = getArguments();	// getArguments��args���擾.
		if (args != null){	// null�łȂ����.
			
			// args�̒��g���擾.
			String value = args.getString(KEY);	// value���擾.
		
			// ���O���c��.
			Log.d(TAG, "value = " + value);	// value�����O�o��.
		
		}
		
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
		
		// ����̏���.
		super.onCreateView(inflater, container, savedInstanceState);
		
		// MainActivity��EditText�̓��e���擾.
		Activity mainActivity = getActivity();	// mainActivity���擾.
		EditText activityEdittext1 = (EditText)mainActivity.findViewById(R.id.activityedittext1);	// activityEdittext1���擾.
		Log.d(TAG, "activityEdittext1 = " + activityEdittext1.getText().toString());	// activityEdittext1�����O�o��.
		
		// Fragment1��EditText���擾.
		View view = inflater.inflate(R.layout.fragment1_main, null);	// inflater.inflate��R.layout.fragment1_main����r���[���쐬.
		ViewParent viewParent = view.getParent();	// viewParent�̎擾.
		if (viewParent == null){	// null�Ȃ�.
			Log.d(TAG, "viewParent = null");	// "viewParent = null"�����O�o��.
		}
		else{	// null�łȂ����.
			Log.d(TAG, "viewParent = " + viewParent.getClass().getName());	// viewParent���o��.
		}
		EditText fragmentEdittext1 = (EditText)view.findViewById(R.id.fragmentedittext1);	// fragmentEdittext1���擾.
		Log.d(TAG, "fragmentEdittext1 = " + fragmentEdittext1.getText().toString());	// fragmentEdittext1�����O�o��.
		return view;	// view��Ԃ�.
		
	}
	
	// �r���[����������.
	@Override
	public void onViewCreated(View view, Bundle savedInstanceState){
	
		// ���O���c��.
		Log.d(TAG, "Fragment1.onViewCreated");	// "Fragment1.onViewCreated"�ƃ��O�Ɏc��.
				
		// ����̏���.
		super.onViewCreated(view, savedInstanceState);
		
		// viewParent�̎擾.
		ViewParent viewParent = view.getParent();	// viewParent�̎擾.
		if (viewParent == null){	// null�Ȃ�.
			Log.d(TAG, "viewParent = null");	// "viewParent = null"�����O�o��.
		}
		else{	// null�łȂ����.
			Log.d(TAG, "viewParent = " + viewParent.getClass().getName());	// viewParent���o��.
		}
		
	}
	
	// �A�N�e�B�r�e�B����������
	@Override
	public void onActivityCreated(Bundle savedInstanceState){
			
		// ���O���c��.
		Log.d(TAG, "Fragment1.onActivityCreated");	// "Fragment1.onActivityCreated"�ƃ��O�Ɏc��.
					
		// ����̏���.
		super.onActivityCreated(savedInstanceState);
			
		// MainActivity��EditText�̓��e���擾.
		Activity mainActivity = getActivity();	// mainActivity���擾.
		EditText activityEdittext1 = (EditText)mainActivity.findViewById(R.id.activityedittext1);	// activityEdittext1���擾.
		Log.d(TAG, "activityEdittext1 = " + activityEdittext1.getText().toString());	// activityEdittext1�����O�o��.
		
		// Fragment1��EditText�̓��e���擾.
		View view = getView();	// getView��view���擾.
		EditText fragmentEdittext1 = (EditText)view.findViewById(R.id.fragmentedittext1);	// fragmentEdittext1���擾.
		Log.d(TAG, "fragmentEdittext1 = " + fragmentEdittext1.getText().toString());	// fragmentEdittext1�����O�o��.
		
	}
	
	// �J�n��
	@Override
	public void onStart(){
		
		// ���O���c��.
		Log.d(TAG, "Fragment1.onStart");	// "Fragment1.onStart"�ƃ��O�Ɏc��.
							
		// ����̏���.
		super.onStart();
		
		// MainActivity��EditText�̓��e���擾.
		Activity mainActivity = getActivity();	// mainActivity���擾.
		EditText activityEdittext1 = (EditText)mainActivity.findViewById(R.id.activityedittext1);	// activityEdittext1���擾.
		Log.d(TAG, "activityEdittext1 = " + activityEdittext1.getText().toString());	// activityEdittext1�����O�o��.
				
		// Fragment1��EditText�̓��e���擾.
		View view = getView();	// getView��view���擾.
		EditText fragmentEdittext1 = (EditText)view.findViewById(R.id.fragmentedittext1);	// fragmentEdittext1���擾.
		Log.d(TAG, "fragmentEdittext1 = " + fragmentEdittext1.getText().toString());	// fragmentEdittext1�����O�o��.
				
	}
	
	// �ĊJ��
	@Override
	public void onResume(){
		
		// ���O���c��.
		Log.d(TAG, "Fragment1.onResume");	// "Fragment1.onResume"�ƃ��O�Ɏc��.
									
		// ����̏���.
		super.onResume();
		
		// MainActivity��EditText�̓��e���擾.
		Activity mainActivity = getActivity();	// mainActivity���擾.
		EditText activityEdittext1 = (EditText)mainActivity.findViewById(R.id.activityedittext1);	// activityEdittext1���擾.
		Log.d(TAG, "activityEdittext1 = " + activityEdittext1.getText().toString());	// activityEdittext1�����O�o��.
						
		// Fragment1��EditText�̓��e���擾.
		View view = getView();	// getView��view���擾.
		EditText fragmentEdittext1 = (EditText)view.findViewById(R.id.fragmentedittext1);	// fragmentEdittext1���擾.
		Log.d(TAG, "fragmentEdittext1 = " + fragmentEdittext1.getText().toString());	// fragmentEdittext1�����O�o��.		
				
	}
	
}
