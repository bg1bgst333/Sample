package com.bgstation0.android.sample.camera_;

import android.app.Activity;
import android.content.res.Configuration;
import android.hardware.Camera;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.SurfaceHolder;
import android.view.SurfaceView;
import android.widget.Toast;

public class MainActivity extends Activity implements SurfaceHolder.Callback{

	// メンバフィールドの定義.
	private Camera camera;	// Cameraオブジェクトcamera.
	
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // SurfaceViewの取得とコールバックのセット.
        SurfaceView surfaceView = (SurfaceView)findViewById(R.id.surfaceView);	// surfaceViewの取得.
        SurfaceHolder holder = surfaceView.getHolder();	// surfaceView.getHolderでholderを取得.
        holder.addCallback(this);	// holder.addCallbackでコールバック(リスナー)としてthisをセット.
        
    }
    
    // Surface作成時.
    @Override
    public void surfaceCreated(SurfaceHolder holder){
    	
    	// カメラの取得.
    	camera = Camera.open();	// cameraオープン.
    	try{	// tryで囲む.
    		camera.setDisplayOrientation(90);	// 90度右に回転.
    		camera.setPreviewDisplay(holder);	// setPreviewDisplayでholderの指すSurfaceViewをプレビューディスプレイに.
    	}
    	catch(Exception ex){	// 例外時
    		ex.printStackTrace();	// スタックトレース出力.
    	}
    	
    }
    
    // Surface破棄時.
    @Override
    public void surfaceDestroyed(SurfaceHolder holder){
    	
    	// カメラの破棄.
    	camera.stopPreview();	// stopPreviewでプレビュー停止.
    	camera.release();	// releaseでcameraのリリース.
    	camera = null;	// nullで埋める.
    	
    }
    
    // Surface変更時.
    @Override
    public void surfaceChanged(SurfaceHolder holder, int format, int width, int height){
    	
    	// パラメータの取得.
    	Camera.Parameters parameters = camera.getParameters();	// parametersを取得.
    	//Toast.makeText(this, "before width = " + String.valueOf(parameters.getPreviewSize().width) + ", before height = " + String.valueOf(parameters.getPreviewSize().height), Toast.LENGTH_LONG).show();	// 設定前のプレビューのサイズを表示.
    	//parameters.setPreviewSize(640, 480);	// プレビューサイズに(640, 480)をセット.
    	//Toast.makeText(this, "after width = " + String.valueOf(parameters.getPreviewSize().width) + ", after height = " + String.valueOf(parameters.getPreviewSize().height), Toast.LENGTH_LONG).show();	// 設定後のプレビューのサイズを表示.
    	/*
    	for (int i = 0; i < parameters.getSupportedPreviewSizes().size(); i++){	// サポートしてるサイズ一覧の数だけ繰り返す.
    		Toast.makeText(this, "width = " + String.valueOf(parameters.getSupportedPreviewSizes().get(i).width) + ", height = " + String.valueOf(parameters.getSupportedPreviewSizes().get(i).height), Toast.LENGTH_LONG).show();	// i番目を表示.
    	}
    	*/
    	try{	// try句
    		camera.setParameters(parameters);	// cameraにparametersをセット.
    	}
    	catch (Exception ex){	// 例外キャッチ.
    		Toast.makeText(this, "ex = " + ex.toString(), Toast.LENGTH_LONG).show();	// exの表示.
    	}
    	
    	// プレビュー開始.
    	camera.startPreview();	// startPreviewでプレビュー開始.
    	
    }
    
    // 設定変更が発生した時.(回転など.)
    @Override
    public void onConfigurationChanged(Configuration newConfig){
    	
    	// 親クラスの既定処理.
    	super.onConfigurationChanged(newConfig);	// super.onConfigurationChangedにnewConfigを渡す.
    	
    	// 方向を表示.
    	if (newConfig.orientation == Configuration.ORIENTATION_PORTRAIT){	// 縦.
    		camera.setDisplayOrientation(90);	// 90度右に回転.
    	}
    	else if (newConfig.orientation == Configuration.ORIENTATION_LANDSCAPE){	// 横.
    		camera.setDisplayOrientation(0);	// 0度.
    	}
    	
    }
    
}