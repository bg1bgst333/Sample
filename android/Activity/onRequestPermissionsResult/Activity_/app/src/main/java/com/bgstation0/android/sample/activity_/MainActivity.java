package com.bgstation0.android.sample.activity_;

import android.Manifest;
import android.app.Activity;
import android.content.Context;
import android.content.pm.PackageManager;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

// メインアクティビティクラスMainActivity(View.OnClickListenerを実装.)
public class MainActivity extends Activity implements View.OnClickListener {

    // メンバフィールドの定義
    private Context mContext = null;    // mContextをnullで初期化.
    private static final int REQUEST_CODE_PERMISSION_ACCESS_FINE_LOCATION = 101;    // REQUEST_CODE_PERMISSION_ACCESS_FINE_LOCATIONを101とする.

    // アクティビティ生成時
    @Override
    protected void onCreate(Bundle savedInstanceState) {

        // 既定の処理
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // mContextに自身をセット.
        mContext = this;    // mContextにthisを格納.

        // button1の初期化.
        Button button1 = (Button) findViewById(R.id.button1);    // button1を取得.
        button1.setOnClickListener(this);    // thisをセット.

    }

    // クリック時
    @Override
    public void onClick(View v) {

        // ACCESS_FINE_LOCATIONのパーミッション確認.
        if (mContext.checkSelfPermission(Manifest.permission.ACCESS_FINE_LOCATION) == PackageManager.PERMISSION_GRANTED){    // 許可.
            Toast.makeText(mContext, "ACCESS_FINE_LOCATION PERMISSION_GRANTED", Toast.LENGTH_LONG).show();  // "ACCESS_FINE_LOCATION PERMISSION_GRANTED"と表示.
        }
        else{   // 拒否.
            Toast.makeText(mContext, "ACCESS_FINE_LOCATION Not PERMISSION_GRANTED", Toast.LENGTH_LONG).show();  // "ACCESS_FINE_LOCATION Not PERMISSION_GRANTED"と表示.

            // ACCESS_FINE_LOCATIONをリクエスト.
            requestPermissions(new String[]{Manifest.permission.ACCESS_FINE_LOCATION}, REQUEST_CODE_PERMISSION_ACCESS_FINE_LOCATION);    // requestPermissionsでACCESS_FINE_LOCATIONの許可ダイアログを表示.

        }

    }

    // リクエストした結果.
    public void onRequestPermissionsResult (int requestCode, String[] permissions, int[] grantResults){

        // ここに来たことをトースト表示.
        Toast.makeText(mContext, "Activity.onRequestPermissionsResult", Toast.LENGTH_LONG).show();  // "Activity.onRequestPermissionsResult"を表示.

        // リクエストコードのチェック.
        if (requestCode == REQUEST_CODE_PERMISSION_ACCESS_FINE_LOCATION){    // 指定したリクエストコードに該当するなら.(例えば今回はREQUEST_CODE_PERMISSION_ACCESS_FINE_LOCATION.)
            // "ACCESS_FINE_LOCATION"かチェック.
            if (permissions[0].equals(Manifest.permission.ACCESS_FINE_LOCATION)){   // "ACCESS_FINE_LOCATION"なら.
                // PERMISSION_GRANTEDかチェック.
                if (grantResults[0] == PackageManager.PERMISSION_GRANTED){  // PERMISSION_GRANTEDなら.
                    Toast.makeText(mContext, "ACCESS_FINE_LOCATION PERMISSION_GRANTED", Toast.LENGTH_LONG).show();  // "ACCESS_FINE_LOCATION PERMISSION_GRANTED"を表示.
                }
                else{
                    Toast.makeText(mContext, "ACCESS_FINE_LOCATION PERMISSION_DENIED", Toast.LENGTH_LONG).show();  // "ACCESS_FINE_LOCATION PERMISSION_DENIED"を表示.
                }
            }
        }

    }

}