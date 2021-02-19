package com.bgstation0.android.sample.fragmentactivity_;

import android.Manifest;
import android.content.Context;
import android.content.pm.PackageManager;
import android.support.v4.app.ActivityCompat;
import android.support.v4.content.ContextCompat;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

import java.util.ArrayList;

// メインアクティビティクラスMainActivity(View.OnClickListenerを実装.)
public class MainActivity extends AppCompatActivity implements View.OnClickListener {

    // メンバフィールドの定義
    private Context mContext = null;    // mContextをnullで初期化.
    private static final int REQUEST_CODE_MULTI_PERMISSIONS = 110;  // REQUEST_CODE_MULTI_PERMISSIONSを110とする.
    private boolean mAccessFineLocation = false;   // 位置情報はfalse.
    private boolean mWriteExternalStorage = false; // 外部ストレージ書き込みはfalse.
    private boolean mCamera = false;   // カメラはfalse.

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

        // パーミッションリストの生成.
        ArrayList<String> permissionList = new ArrayList<String>(); // permissionListを生成.

        // ACCESS_FINE_LOCATIONのパーミッション確認.
        if (ContextCompat.checkSelfPermission(mContext, Manifest.permission.ACCESS_FINE_LOCATION) == PackageManager.PERMISSION_GRANTED) {    // 許可.
            Toast.makeText(mContext, "ACCESS_FINE_LOCATION PERMISSION_GRANTED", Toast.LENGTH_LONG).show();  // "ACCESS_FINE_LOCATION PERMISSION_GRANTED"と表示.
            mAccessFineLocation = true; // trueをセット.
        }
        else{   // 未許可.
            permissionList.add(Manifest.permission.ACCESS_FINE_LOCATION);   // permissionListにACCESS_FINE_LOCATIONを追加.
            mAccessFineLocation = false; // falseをセット.
        }

        // WRITE_EXTERNAL_STORAGEのパーミッション確認.
        if (ContextCompat.checkSelfPermission(mContext, Manifest.permission.WRITE_EXTERNAL_STORAGE) == PackageManager.PERMISSION_GRANTED) {    // 許可.
            Toast.makeText(mContext, "WRITE_EXTERNAL_STORAGE PERMISSION_GRANTED", Toast.LENGTH_LONG).show();  // "WRITE_EXTERNAL_STORAGE PERMISSION_GRANTED"と表示.
            mWriteExternalStorage = true;   // trueをセット.
        }
        else{   // 未許可.
            permissionList.add(Manifest.permission.WRITE_EXTERNAL_STORAGE);   // permissionListにWRITE_EXTERNAL_STORAGEを追加.
            mWriteExternalStorage = false;   // falseをセット.
        }

        // CAMERAのパーミッション確認.
        if (ContextCompat.checkSelfPermission(mContext, Manifest.permission.CAMERA) == PackageManager.PERMISSION_GRANTED) {    // 許可.
            Toast.makeText(mContext, "CAMERA PERMISSION_GRANTED", Toast.LENGTH_LONG).show();  // "CAMERA PERMISSION_GRANTED"と表示.
            mCamera = true; // trueをセット.
        }
        else{   // 未許可.
            permissionList.add(Manifest.permission.CAMERA);   // permissionListにCAMERAを追加.
            mCamera = false;    // falseをセット.
        }

        // permissionListにひとつでもあればリクエスト.
        if (permissionList.size() > 0){ // 1つでもあれば.

            // マルチパーミッションでリクエスト.
            ActivityCompat.requestPermissions(this, permissionList.toArray(new String[0]), REQUEST_CODE_MULTI_PERMISSIONS);    // ActivityCompat.requestPermissionsでマルチパーミッションリクエスト.

        }
        else{

            // 全て許可されている.
            Toast.makeText(mContext, "ALREADY ALL PERMISSION_GRANTED", Toast.LENGTH_LONG).show();   // "ALREADY ALL PERMISSION_GRANTED"と表示.

        }

    }

    // リクエストした結果.
    public void onRequestPermissionsResult (int requestCode, String[] permissions, int[] grantResults) {

        // ここに来たことをトースト表示.
        Toast.makeText(mContext, "Activity.onRequestPermissionsResult", Toast.LENGTH_LONG).show();  // "Activity.onRequestPermissionsResult"を表示.

        // リクエストコードのチェック.
        if (requestCode == REQUEST_CODE_MULTI_PERMISSIONS) {    // 指定したリクエストコードに該当するなら.(例えば今回はREQUEST_CODE_MULTI_PERMISSIONS.)

            // 各パーミッションのチェック.
            for (int i = 0; i < grantResults.length; i++){   // grantResultsの数だけ繰り返す.
                if (grantResults[i] == PackageManager.PERMISSION_GRANTED){  // i番目が許可なら.
                    Toast.makeText(mContext, permissions[i] + " PERMISSION_GRANTED", Toast.LENGTH_LONG).show();  // permissionsのi番目で"PERMISSION_GRANTED"を表示.
                    if (permissions[i].equals(Manifest.permission.ACCESS_FINE_LOCATION)){   // ACCESS_FINE_LOCATIONなら.
                        mAccessFineLocation = true; // trueをセット.
                    }
                    else if (permissions[i].equals(Manifest.permission.WRITE_EXTERNAL_STORAGE)){    // WRITE_EXTERNAL_STORAGEなら.
                        mWriteExternalStorage = true;   // trueをセット.
                    }
                    else if (permissions[i].equals(Manifest.permission.CAMERA)) {   // CAMERAなら.
                        mCamera = true; // trueをセット.
                    }
                }
                else{   // i番目が拒否
                    Toast.makeText(mContext, permissions[i] + " PERMISSION_DENIED", Toast.LENGTH_LONG).show();  // permissionsのi番目で"PERMISSION_DENIED"を表示.
                }
            }

            // 全てのパーミッションが許可された.
            if (mAccessFineLocation && mWriteExternalStorage && mCamera){
                Toast.makeText(mContext, "NOW ALL PERMISSION_GRANTED", Toast.LENGTH_LONG).show();   // "NOW ALL PERMISSION_GRANTED"と表示.
            }

        }

    }

}