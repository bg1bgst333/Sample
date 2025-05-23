package com.bgstation0.android.sample.fragment_;

import android.app.Activity;
import android.app.FragmentManager;
import android.app.FragmentTransaction;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // savedInstanceStateがnullなら.
        if (savedInstanceState == null){
        	
        	// カスタムフラグメントの追加.
        	FragmentManager fragmentManager = getFragmentManager();	// fragmentManagerの取得.
        	FragmentTransaction fragmentTransaction = fragmentManager.beginTransaction();	// fragmentTransactionの取得.
        	CustomFragment customFragment = new CustomFragment();	// custmFragmentを生成.
        	fragmentTransaction.replace(R.id.framelayout1, customFragment);	// リプレース.
        	fragmentTransaction.commit();	// コミット.
        
        }
        
    }
}
