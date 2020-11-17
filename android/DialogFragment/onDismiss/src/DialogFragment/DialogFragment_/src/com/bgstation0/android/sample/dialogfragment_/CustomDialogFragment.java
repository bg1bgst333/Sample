package com.bgstation0.android.sample.dialogfragment_;

import android.app.DialogFragment;
import android.content.DialogInterface;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.Toast;

public class CustomDialogFragment extends DialogFragment implements View.OnClickListener{

	// �����o�t�B�[���h�̒�`
	CustomAsyncTask task = null;	// CustomAsyncTask�I�u�W�F�N�gtask��null��.
	
	// �r���[������.
	@Override
	public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState){
		
		// ���C�A�E�g����r���[����.
		View view = inflater.inflate(R.layout.fragment_custom_dialog, container);	// infalter.inflate��R.layout.fragment_custom_dialog�����Ƀr���[���쐬��, view�Ɋi�[.
		Button button1 = (Button)view.findViewById(R.id.fragment1_button1);	// button1���擾.
		button1.setOnClickListener(this);	// this���Z�b�g.
		return view;	// view��Ԃ�.
		
	}
	
	// �L�����Z����.
	@Override
	public void onCancel(DialogInterface dialog){
		super.onCancel(dialog);
		Toast.makeText(getActivity(), "onCancel", Toast.LENGTH_LONG).show();	// "onCancel"��Toast�\��.
	}
	
	// ��\����.
	@Override
	public void onDismiss(DialogInterface dialog){
		super.onDismiss(dialog);
		Toast.makeText(getActivity(), "onDismiss", Toast.LENGTH_LONG).show();	// "onDismiss"��Toast�\��.
	}

	// �{�^���N���b�N��.
	@Override
	public void onClick(View v) {
		// TODO Auto-generated method stub
		// CustomAsyncTask�ɂ��񓯊������𐶐���, ���s.
    	task = new CustomAsyncTask(getActivity(), this);	// CustomAsyncTask�I�u�W�F�N�g���쐬��, task�Ɋi�[.(getActivity�ŐeActivity��n��, this���n��.)
    	task.execute(10);	// task.execute��10��n���Ď��s.
	}
	
}