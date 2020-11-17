package com.bgstation0.android.sample.fragment_;

import android.app.Activity;
import android.app.Fragment;
import android.os.Bundle;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.TextView;

//�t���O�����g1
public class Fragment1 extends Fragment implements OnClickListener{

	// �����o�t�B�[���h
	static final String TAG = "Fragment1";	// TAG��"Fragment1"�ŏ�����.
	public int mNumber = 0;	// mNumber��0�ŏ�����.
	public MainActivity mContext = null;	// mContext��null�ŏ�����.
	
	// �R���X�g���N�^
	public Fragment1(){
		
	}
	
	// �A�^�b�`��
	@Override
	public void onAttach(Activity activity){
			
		// ����̏���.
		super.onAttach(activity);
		Log.d(TAG, "Fragment1.onAttach");	// "Fragment1.onAttach"�ƃ��O�Ɏc��.
		mContext = (MainActivity)activity;	// activity��mContext�ɓn��.
		mContext.func();	// func���Ă�.
		
	}
		
	// �t���O�����g������
	@Override
	public void onCreate(Bundle savedInstanceState){
		
		// ����̏���.
		super.onCreate(savedInstanceState);	// �e�N���X��onCreate���Ă�.
		
		// Fragment�̍Đ�����}�~.
		setRetainInstance(true);	// setRetainInstance��true��.
				
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
				
		// ����̏���.
		View view = inflater.inflate(R.layout.fragment1_main, null);	// inflater.inflate��R.layout.fragment1_main����r���[���쐬.
        Button button1 = (Button)view.findViewById(R.id.fragment1_button1);	// Fragment1��button1���擾.
        button1.setOnClickListener(this);	// ���X�i�[�Ƃ���this���Z�b�g.
        TextView tv = (TextView)view.findViewById(R.id.fragment1_textview);
        tv.setText(Integer.toString(mNumber));
		return view;
		
	}

	@Override
	public void onClick(View v) {
		// TODO Auto-generated method stub
		mNumber++;	// mNumber�𑝂₷.
		View view = getView();
		TextView tv = (TextView)view.findViewById(R.id.fragment1_textview);
        tv.setText(Integer.toString(mNumber));
	}
	
	// �f�^�b�`��
    @Override
    public void onDetach(){
    	
    	// ���O���c��.
    	Log.d(TAG, "Fragment1.onDetach");	// "Fragment1.onDetach"�ƃ��O�Ɏc��.
    
    	// mContext��null.
    	mContext = null;
    	
    	// ����̏���.
    	super.onDetach();	// �e�N���X��onDetach���Ă�.
	
    }
    	
}