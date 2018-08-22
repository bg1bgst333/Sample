package com.bgstation0.android.sample.camera.parameters_;

import android.app.Activity;
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
    	parameters.setPreviewSize(width, height);	// プレビューサイズにwidth, heightをセット.
    	try{	// try句
    		camera.setParameters(parameters);	// cameraにparametersをセット.
    	}
    	catch (Exception ex){	// 例外キャッチ.
    		Toast.makeText(this, "ex = " + ex.toString(), Toast.LENGTH_LONG).show();	// exの表示.
    	}
    	
    	// プレビュー開始.
    	camera.startPreview();	// startPreviewでプレビュー開始.
    	
    }
    
}