package com.bgstation0.android.sample.fragmentstatepageradapter_;

import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

//�J�X�^���t���O�����g
public class CustomFragment extends Fragment {

	// �����o�t�B�[���h�̒�`.
	String mText = "";	// mText��""�ŏ�����.
	
	// �������\�b�h.
	public static CustomFragment newInstance(String text){
		CustomFragment customFragment = new CustomFragment();	// customFragment�𐶐�.
		Bundle args = new Bundle();	// args�𐶐�.
		args.putString("text", text);	// text��o�^.
		customFragment.setArguments(args);	// args���Z�b�g.
		return customFragment;	// customFragment��Ԃ�.
	}
	
	// �r���[�̐���.
	@Override
	public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState){
		super.onCreateView(inflater, container, savedInstanceState);
		View view = inflater.inflate(R.layout.custom_fragment_main, null);	// View�𐶐�.
		TextView customFragmentTextView1 = (TextView)view.findViewById(R.id.custom_fragment_textview1);	// customFragmentTextView1���擾.
		if (savedInstanceState == null){	// null�̎��͈���������.
			Bundle args = getArguments();	// args���擾.
			mText = args.getString("text");	// mText���擾.
			Log.d("FragmentStatePagerAdapter", "savedInstanceState == null(" + mText + ")");
		}
		else{	// null�łȂ�����, �ۑ����Ă��������̂����.
			mText = savedInstanceState.getString("text");	// mText���擾.
			Log.d("FragmentStatePagerAdapter", "savedInstanceState != null(" + mText + ")");
		}
		customFragmentTextView1.setText(mText);	// mText���Z�b�g.
		return view;	// view��Ԃ�.
	}
	
	// ��ԕۑ���.
	@Override
	public void onSaveInstanceState(Bundle outState){
		super.onSaveInstanceState(outState);
		outState.putString("text", mText);	// mText��ۑ�.
	}
	
}