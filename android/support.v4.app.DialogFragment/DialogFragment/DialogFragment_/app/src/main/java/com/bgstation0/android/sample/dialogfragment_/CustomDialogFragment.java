package com.bgstation0.android.sample.dialogfragment_;

import android.app.AlertDialog;
import android.app.Dialog;
import android.content.Context;
import android.content.DialogInterface;
import android.os.Bundle;
import android.support.v4.app.DialogFragment;
import android.widget.Toast;

// カスタムダイアログフラグメントCustomDialogFragment
public class CustomDialogFragment extends DialogFragment {

    // ダイアログ作成時.
    @Override
    public Dialog onCreateDialog(Bundle savedInstanceState){

        // アラートダイアログビルダーの設定.
        final MainActivity mainActivity = (MainActivity) getActivity(); // MainActivityにキャスト.
        AlertDialog.Builder builder = new AlertDialog.Builder(mainActivity);	// builderの生成.
        Bundle args = getArguments();   // argsを取得.
        String title = args.getString("title");   // titleを取得.
        String message = args.getString("message");   // messageを取得.
        final int id = args.getInt("id");   // idを取得.
        builder.setTitle(title);        // titleをセット.
        builder.setMessage(message);    // messageをセット.
        builder.setPositiveButton("OK", new DialogInterface.OnClickListener() { // "OK"
            @Override
            public void onClick(DialogInterface dialog, int which) {
                Toast.makeText(mainActivity, "OK", Toast.LENGTH_LONG).show();   // "OK"をトースト表示.
                mainActivity.func(id);  // funcを実行.
            }
        });
        builder.setNegativeButton("NG", new DialogInterface.OnClickListener() { // "NG"
            @Override
            public void onClick(DialogInterface dialog, int which) {
                Toast.makeText(mainActivity, "NG", Toast.LENGTH_LONG).show();   // "NG"をトースト表示.
            }
        });
        return builder.create();    // builder.createで生成.

    }

}