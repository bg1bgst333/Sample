package com.bgstation0.android.sample.resources_;

import android.app.Activity;
import android.content.res.Resources;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.TextView;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // リソース名(フル)を取得して, TextViewにセット.
        Resources resources = getResources();	// resourcesを取得.
        TextView tv1 = (TextView)findViewById(R.id.textview1);	// tv1を取得.
        String pkgName1 = resources.getResourcePackageName(R.id.textview1);	// resources.getResourcePackageNameでR.id.textview1のパッケージ名を取得.
        tv1.setText("tv1: " + pkgName1);	// pkgName1をセット.
        TextView tv2 = (TextView)findViewById(R.id.textview2);	// tv2を取得.
        String pkgName2 = resources.getResourcePackageName(android.R.id.text1);	// resources.getResourcePackageNameでandroid.R.id.text1のパッケージ名を取得.
        tv2.setText("tv2: " + pkgName2);	// pkgName2をセット.
        
    }
}