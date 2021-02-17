package com.bgstation0.android.sample.activitycompat_;

import android.Manifest;
import android.content.Context;
import android.content.pm.PackageManager;
import android.support.v4.app.ActivityCompat;
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
    public static final int CUSTOM_DIALOG_FRAGMENT_ID_ACCESS_FINE_LOCATION = 1;    // CUSTOM_DIALOG_FRAGMENT_ID_ACCESS_FINE_LOCATIONを1とする.
    public static final int CUSTOM_DIALOG_FRAGMENT_ID_WRITE_EXTERNAL_STORAGE = 2;  // CUSTOM_DIALOG_FRAGMENT_ID_WRITE_EXTERNAL_STORAGEを2とする.
    public static final int CUSTOM_DIALOG_FRAGMENT_ID_CAMERA = 3;                   // CUSTOM_DIALOG_FRAGMENT_ID_CAMERAを3とする.
    public ArrayList<String> mPermissionList = null;    // mPermissionListをnullで初期化.

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

        // mPermissionListの初期化.
        mPermissionList = new ArrayList<String>();  // mPermissionListを生成.

    }

    // クリック時
    @Override
    public void onClick(View v) {

        // パーミッションリストの初期化.
        mPermissionList.clear();    // mPermissionListをクリア.

        // ACCESS_FINE_LOCATIONのパーミッション確認.
        if (mContext.checkSelfPermission(Manifest.permission.ACCESS_FINE_LOCATION) == PackageManager.PERMISSION_GRANTED) {    // 許可.
            Toast.makeText(mContext, "ACCESS_FINE_LOCATION PERMISSION_GRANTED", Toast.LENGTH_LONG).show();  // "ACCESS_FINE_LOCATION PERMISSION_GRANTED"と表示.
            mAccessFineLocation = true; // trueをセット.
        }
        else{   // 未許可.
            if (ActivityCompat.shouldShowRequestPermissionRationale(this, Manifest.permission.ACCESS_FINE_LOCATION)){    // 許可をしてほしい根拠を示すべきである場合.(2回目以降に呼ばれる.)
                CustomDialogFragment customDialogFragment1 = new CustomDialogFragment(); // customDialogFragment1を生成.
                Bundle args1 = new Bundle(); // args1を用意.
                args1.putString("title", "Need ACCESS_FINE_LOCATION!");  // "Need ACCESS_FINE_LOCATION!"
                args1.putString("message", "add Request ACCESS_FINE_LOCATION?");   // "add Request ACCESS_FINE_LOCATION?"
                args1.putInt("id", CUSTOM_DIALOG_FRAGMENT_ID_ACCESS_FINE_LOCATION); // CUSTOM_DIALOG_FRAGMENT_ID_ACCESS_FINE_LOCATION
                customDialogFragment1.setArguments(args1);  // args1をセット.
                customDialogFragment1.show(getSupportFragmentManager(), "dialog1");   //  customDialogFragment1.showで表示.
            }
            else{   // 示す必要がない場合.(1回目や今後表示しないの場合.)
                mPermissionList.add(Manifest.permission.ACCESS_FINE_LOCATION);   // mPermissionListにACCESS_FINE_LOCATIONを追加.
                mAccessFineLocation = false;    // falseをセット.
            }
        }

        // WRITE_EXTERNAL_STORAGEのパーミッション確認.
        if (mContext.checkSelfPermission(Manifest.permission.WRITE_EXTERNAL_STORAGE) == PackageManager.PERMISSION_GRANTED) {    // 許可.
            Toast.makeText(mContext, "WRITE_EXTERNAL_STORAGE PERMISSION_GRANTED", Toast.LENGTH_LONG).show();  // "WRITE_EXTERNAL_STORAGE PERMISSION_GRANTED"と表示.
            mWriteExternalStorage = true; // trueをセット.
        }
        else{   // 未許可.
            if (ActivityCompat.shouldShowRequestPermissionRationale(this, Manifest.permission.WRITE_EXTERNAL_STORAGE)){    // 許可をしてほしい根拠を示すべきである場合.(2回目以降に呼ばれる.)
                CustomDialogFragment customDialogFragment2 = new CustomDialogFragment(); // customDialogFragment2を生成.
                Bundle args2 = new Bundle(); // args2を用意.
                args2.putString("title", "Need WRITE_EXTERNAL_STORAGE!");  // "Need WRITE_EXTERNAL_STORAGE!"
                args2.putString("message", "add Request WRITE_EXTERNAL_STORAGE?");   // "add Request WRITE_EXTERNAL_STORAGE?"
                args2.putInt("id", CUSTOM_DIALOG_FRAGMENT_ID_WRITE_EXTERNAL_STORAGE); // CUSTOM_DIALOG_FRAGMENT_ID_WRITE_EXTERNAL_STORAGE
                customDialogFragment2.setArguments(args2);  // args2をセット.
                customDialogFragment2.show(getSupportFragmentManager(), "dialog2");   //  customDialogFragment2.showで表示.
            }
            else{   // 示す必要がない場合.(1回目や今後表示しないの場合.)
                mPermissionList.add(Manifest.permission.WRITE_EXTERNAL_STORAGE);   // mPermissionListにWRITE_EXTERNAL_STORAGEを追加.
                mWriteExternalStorage = false;    // falseをセット.
            }
        }

        // CAMERAのパーミッション確認.
        if (mContext.checkSelfPermission(Manifest.permission.CAMERA) == PackageManager.PERMISSION_GRANTED) {    // 許可.
            Toast.makeText(mContext, "CAMERA PERMISSION_GRANTED", Toast.LENGTH_LONG).show();  // "CAMERA PERMISSION_GRANTED"と表示.
            mCamera = true; // trueをセット.
        }
        else{   // 未許可.
            if (ActivityCompat.shouldShowRequestPermissionRationale(this, Manifest.permission.CAMERA)){    // 許可をしてほしい根拠を示すべきである場合.(2回目以降に呼ばれる.)
                CustomDialogFragment customDialogFragment3 = new CustomDialogFragment(); // customDialogFragment3を生成.
                Bundle args3 = new Bundle(); // args3を用意.
                args3.putString("title", "Need CAMERA!");  // "Need CAMERA!"
                args3.putString("message", "add Request CAMERA?");   // "add Request CAMERA?"
                args3.putInt("id", CUSTOM_DIALOG_FRAGMENT_ID_CAMERA); // CUSTOM_DIALOG_FRAGMENT_ID_CAMERA
                customDialogFragment3.setArguments(args3);  // args3をセット.
                customDialogFragment3.show(getSupportFragmentManager(), "dialog3");   //  customDialogFragment3.showで表示.
            }
            else{   // 示す必要がない場合.(1回目や今後表示しないの場合.)
                mPermissionList.add(Manifest.permission.CAMERA);   // mPermissionListにCAMERAを追加.
                mCamera = false;    // falseをセット.
            }
        }

        // すべてのフラグが立っている == 全て許可されている.(mPermissionListに何も追加されていない事を全て許可されているにはできない.)
        if (mAccessFineLocation && mWriteExternalStorage && mCamera) {  // 全てtrue.

            // 全て許可されている.
            Toast.makeText(mContext, "ALREADY ALL PERMISSION_GRANTED", Toast.LENGTH_LONG).show();   // "ALREADY ALL PERMISSION_GRANTED"と表示.

        }
        else {   // どれかがfalse.

            // mPermissionListにひとつでもあればリクエスト.
            if (mPermissionList.size() > 0) { // 1つでもあれば.

                // マルチパーミッションでリクエスト.
                requestPermissions(mPermissionList.toArray(new String[0]), REQUEST_CODE_MULTI_PERMISSIONS);    // requestPermissionsでマルチパーミッションリクエスト.

            }

        }

    }

    // ダイアログフラグメントから呼ぶ関数.
    public void func(int id){

        // idごとに処理を振り分け.
        if (id == CUSTOM_DIALOG_FRAGMENT_ID_ACCESS_FINE_LOCATION){  // ACCESS_FINE_LOCATION
            //mPermissionList.add(Manifest.permission.ACCESS_FINE_LOCATION);   // mPermissionListにACCESS_FINE_LOCATIONを追加.
            //mAccessFineLocation = false;    // falseをセット.
            requestPermissions(new String[]{Manifest.permission.ACCESS_FINE_LOCATION}, REQUEST_CODE_MULTI_PERMISSIONS); // マルチと言いながら単一リクエスト.
        }
        else if (id == CUSTOM_DIALOG_FRAGMENT_ID_WRITE_EXTERNAL_STORAGE){   // WRITE_EXTERNAL_STORAGE
            //mPermissionList.add(Manifest.permission.WRITE_EXTERNAL_STORAGE);    // mPermissionListにWRITE_EXTERNAL_STORAGEを追加.
            //mWriteExternalStorage = false;  // falseをセット.
            requestPermissions(new String[]{Manifest.permission.WRITE_EXTERNAL_STORAGE}, REQUEST_CODE_MULTI_PERMISSIONS); // マルチと言いながら単一リクエスト.
        }
        else if (id == CUSTOM_DIALOG_FRAGMENT_ID_CAMERA){   // CAMERA
            //mPermissionList.add(Manifest.permission.CAMERA);    // mPermissionListにCAMERAを追加.
            //mCamera = false;    // falseをセット.
            requestPermissions(new String[]{Manifest.permission.CAMERA}, REQUEST_CODE_MULTI_PERMISSIONS); // マルチと言いながら単一リクエスト.
        }

    }

    // リクエストした結果.
    public void onRequestPermissionsResult (int requestCode, String[] permissions, int[] grantResults) {

        // ここに来たことをトースト表示.
        Toast.makeText(mContext, "Activity.onRequestPermissionsResult", Toast.LENGTH_LONG).show();  // "Activity.onRequestPermissionsResult"を表示.

        // リクエストコードのチェック.
        if (requestCode == REQUEST_CODE_MULTI_PERMISSIONS) {    // 指定したリクエストコードに該当するなら.(例えば今回はREQUEST_CODE_MULTI_PERMISSIONS.)

            // 各パーミッションのチェック.
            for (int i = 0; i < grantResults.length; i++) {   // grantResultsの数だけ繰り返す.
                if (grantResults[i] == PackageManager.PERMISSION_GRANTED) {  // i番目が許可なら.
                    Toast.makeText(mContext, permissions[i] + " PERMISSION_GRANTED", Toast.LENGTH_LONG).show();  // permissionsのi番目で"PERMISSION_GRANTED"を表示.
                    if (permissions[i].equals(Manifest.permission.ACCESS_FINE_LOCATION)) {   // ACCESS_FINE_LOCATIONなら.
                        mAccessFineLocation = true; // trueをセット.
                    }
                    else if (permissions[i].equals(Manifest.permission.WRITE_EXTERNAL_STORAGE)){    // WRITE_EXTERNAL_STORAGEなら.
                        mWriteExternalStorage = true;   // trueをセット.
                    }
                    else if (permissions[i].equals(Manifest.permission.CAMERA)){    // CAMERAなら.
                        mCamera = true; // trueをセット.
                    }
                }
                else {   // i番目が拒否
                    Toast.makeText(mContext, permissions[i] + " PERMISSION_DENIED", Toast.LENGTH_LONG).show();  // permissionsのi番目で"PERMISSION_DENIED"を表示.
                }
            }

            // 全てのパーミッションが許可された.
            if (mAccessFineLocation && mWriteExternalStorage && mCamera) {  // 全てtrue.
                Toast.makeText(mContext, "NOW ALL PERMISSION_GRANTED", Toast.LENGTH_LONG).show();   // "NOW ALL PERMISSION_GRANTED"と表示.
            }

        }

    }

}