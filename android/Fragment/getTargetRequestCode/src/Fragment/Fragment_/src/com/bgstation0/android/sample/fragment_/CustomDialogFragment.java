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

	// メンバフィールド
    static final String TAG = "CustomDialogFragment";	// TAGを"CustomDialogFragment"で初期化.
	
	// ファクトリメソッド
	public static CustomDialogFragment newInstance(Fragment target, int requestCode){
		
		// CustomDialogFragmentオブジェクトの生成.
		CustomDialogFragment customDialogFragment = new CustomDialogFragment();	// customDialogFragmentを生成.
		customDialogFragment.setTargetFragment(target, requestCode);	// targetとrequestCodeをセット.
		return customDialogFragment;	// customDialogFragmentを返す.
		
	}
	
	// ダイアログ作成時.
	@Override
	public Dialog onCreateDialog(Bundle savedInstanceState){
		
		// アラートダイアログビルダーの設定.
		final DialogFragment df = this;	// dfにthisを格納.
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
				target.onActivityResult(r, Activity.RESULT_OK, intent);	// target.onActivityResultを呼ぶ.
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
				target.onActivityResult(r, Activity.RESULT_OK, intent);	// target.onActivityResultを呼ぶ.
			}
			
		});
		return builder.create();
				
	}
	
}