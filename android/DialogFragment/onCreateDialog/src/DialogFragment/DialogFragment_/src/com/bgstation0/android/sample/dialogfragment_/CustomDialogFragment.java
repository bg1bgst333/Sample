package com.bgstation0.android.sample.dialogfragment_;

import android.app.AlertDialog;
import android.app.Dialog;
import android.app.DialogFragment;
import android.content.Context;
import android.content.DialogInterface;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Toast;

public class CustomDialogFragment extends DialogFragment {

	// �r���[������.
	/*
	@Override
	public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState){
		
		// ���C�A�E�g����r���[����.
		return inflater.inflate(R.layout.fragment_custom_dialog, container);	// infalter.inflate��R.layout.fragment_custom_dialog�����Ƀr���[���쐬��, �Ԃ�.
		
	}
	*/
	
	// �_�C�A���O�쐬��.
	@Override
	public Dialog onCreateDialog(Bundle savedInstanceState){
		
		// �A���[�g�_�C�A���O�r���_�[�̐ݒ�.
		final Context context = getActivity();
		AlertDialog.Builder builder = new AlertDialog.Builder(context);	// builder�̐���.
		builder.setTitle("CustomDialogFragment");	// �^�C�g��"CustomDialogFragment".
		builder.setMessage("CustomDialogFragment");	// ���b�Z�[�W"CustomDialogFragment".
		builder.setPositiveButton("OK", new DialogInterface.OnClickListener() {	// �|�W�e�B�u�{�^��"OK".
			@Override
			public void onClick(DialogInterface dialog, int which) {
				// TODO Auto-generated method stub
				Toast.makeText(context, "OK", Toast.LENGTH_LONG).show();
			}
		});
		
		// �A���[�g�_�C�A���O�̍쐬.
		return builder.create();	// builder.create�Ő���.
		
	}
	
}