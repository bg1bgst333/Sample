package com.bgstation0.android.sample.fragment_;

import android.app.Activity;
import android.app.AlertDialog;
import android.app.Dialog;
import android.app.DialogFragment;
import android.app.Fragment;
import android.content.DialogInterface;
import android.content.Intent;
import android.os.Bundle;
import android.widget.Toast;

public class CustomDialogFragment extends DialogFragment {

	// �����o�t�B�[���h
    static final String TAG = "CustomDialogFragment";	// TAG��"CustomDialogFragment"�ŏ�����.
	
	// �t�@�N�g�����\�b�h
	public static CustomDialogFragment newInstance(Fragment target, int requestCode){
		
		// CustomDialogFragment�I�u�W�F�N�g�̐���.
		CustomDialogFragment customDialogFragment = new CustomDialogFragment();	// customDialogFragment�𐶐�.
		customDialogFragment.setTargetFragment(target, requestCode);	// target��requestCode���Z�b�g.
		return customDialogFragment;	// customDialogFragment��Ԃ�.
		
	}
	
	// �_�C�A���O�쐬��.
	@Override
	public Dialog onCreateDialog(Bundle savedInstanceState){
		
		// �A���[�g�_�C�A���O�r���_�[�̐ݒ�.
		final DialogFragment df = this;	// df��this���i�[.
		AlertDialog.Builder builder = new AlertDialog.Builder(getActivity());
		builder.setTitle("CustomDialogFragment");
		builder.setMessage("OK or NG");
		builder.setPositiveButton("OK", new DialogInterface.OnClickListener() {
			
			@Override
			public void onClick(DialogInterface dialog, int which) {
				// TODO Auto-generated method stub
				Fragment target = df.getTargetFragment();
				Intent intent = new Intent();
				intent.putExtra("message", "OK");
				int r = df.getTargetRequestCode();
				Toast.makeText(df.getActivity(), "r = " + r, Toast.LENGTH_LONG).show();
				target.onActivityResult(r, Activity.RESULT_OK, intent);	// target.onActivityResult���Ă�.
			}
			
		});
		builder.setNegativeButton("NG", new DialogInterface.OnClickListener() {
			
			@Override
			public void onClick(DialogInterface dialog, int which) {
				// TODO Auto-generated method stub
				Fragment target = df.getTargetFragment();
				Intent intent = new Intent();
				intent.putExtra("message", "NG");
				int r = df.getTargetRequestCode();
				Toast.makeText(df.getActivity(), "r = " + r, Toast.LENGTH_LONG).show();
				target.onActivityResult(r, Activity.RESULT_OK, intent);	// target.onActivityResult���Ă�.
			}
			
		});
		return builder.create();
				
	}
	
}