package com.bgstation0.android.sample.activitycompat_;

import android.app.AlertDialog;
import android.app.Dialog;
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
        builder.setPositiveButton("YES", new DialogInterface.OnClickListener() { // "YES"
            @Override
            public void onClick(DialogInterface dialog, int which) {
                Toast.makeText(mainActivity, "YES", Toast.LENGTH_LONG).show();   // "YES"をトースト表示.
                mainActivity.func(id);  // funcを実行.
            }
        });
        builder.setNegativeButton("NO", new DialogInterface.OnClickListener() { // "NO"
            @Override
            public void onClick(DialogInterface dialog, int which) {
                Toast.makeText(mainActivity, "NO", Toast.LENGTH_LONG).show();   // "NO"をトースト表示.
            }
        });
        return builder.create();    // builder.createで生成.

    }

}