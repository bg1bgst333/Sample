package com.bgstation0.android.sample.fragmentpageradapter_;

import android.os.Bundle;
import android.support.v4.app.Fragment;	// support.v4��Fragment�ɂ���K�v������.
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

// �J�X�^���t���O�����g
public class CustomFragment extends Fragment {

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
		Bundle args = getArguments();	// args���擾.
		customFragmentTextView1.setText(args.getString("text"));	// �擾����"text"���Z�b�g.
		return view;	// view��Ԃ�.
	}
	
}