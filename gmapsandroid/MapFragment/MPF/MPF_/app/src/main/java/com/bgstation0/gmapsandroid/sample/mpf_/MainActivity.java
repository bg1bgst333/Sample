package com.bgstation0.gmapsandroid.sample.mpf_;

import android.app.Activity;
import android.app.FragmentManager;
import android.os.Bundle;

import com.google.android.gms.maps.CameraUpdateFactory;
import com.google.android.gms.maps.GoogleMap;
import com.google.android.gms.maps.MapFragment;
import com.google.android.gms.maps.OnMapReadyCallback;
import com.google.android.gms.maps.model.LatLng;

public class MainActivity extends Activity implements OnMapReadyCallback {

    // メンバフィールドの定義
    private GoogleMap mGoogleMap;    // GoogleMapオブジェクトmGoogleMap.

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // マップの表示.
        FragmentManager fragmentManager = getFragmentManager(); // getFragmentManagerでfragmentManager取得.
        MapFragment mapFragment = (MapFragment) fragmentManager.findFragmentById(R.id.mapFragment);   // fragmentManager.findFragmentByIdでmapFragmentを取得.
        mapFragment.getMapAsync(this);  // mapFragment.getMapAsyncでマップを非同期で取得.
    }

    // マップの準備完了時.
    @Override
    public void onMapReady(GoogleMap googleMap) {

        // 引数をメンバにセット.
        mGoogleMap = googleMap;    // googleMapをmGoogleMapにセット.

        // 渋谷に移動.
        LatLng shibuya = new LatLng(35.661777, 139.704051); // shibuyaはLatLng(35.661777, 139.704051)に設定.
        mGoogleMap.moveCamera(CameraUpdateFactory.newLatLngZoom(shibuya, 15));  // mGoogleMap.moveCameraでカメラを渋谷にズームして移動.
    }
}
