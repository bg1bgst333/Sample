package com.bgstation0.android.sample.fragmentmanager_;

import android.app.Activity;
import android.app.Fragment;
import android.app.FragmentManager;
import android.app.FragmentTransaction;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.Toast;

//メインアクティビティ
public class MainActivity extends Activity implements OnClickListener{

	// 生成時
    @Override
    protected void onCreate(Bundle savedInstanceState) {
 	
 	    // 既定の処理.
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
     
        // Button1の処理.
        Button button1 = (Button)findViewById(R.id.button1);	// button1を取得.
        button1.setOnClickListener(this);	// リスナーとしてthisをセット.
     
    }
 
    // クリック時
    public void onClick(View v){
 	
        // FragmentManager, fragmentTransactionの取得.
    	FragmentManager fragmentManager = getFragmentManager();	// fragmentManagerの取得.
    	FragmentTransaction fragmentTransaction = fragmentManager.beginTransaction();	// fragmentTransactionの取得.
    	Fragment1 fragment1 = new Fragment1();	// fragment1を生成.
    	fragmentTransaction.add(R.id.framelayout1, fragment1);	// fragment1を追加.
    	fragmentTransaction.commit();	// コミット.
 	
    }
    
    @Override
    protected void onSaveInstanceState(Bundle outState){
    	super.onSaveInstanceState(outState);
    	Fragment f = getFragmentManager().findFragmentById(R.id.framelayout1);
    	Log.d("Fragment", "save fragment = " + f.toString());	// fragmentの内容を出力.
    	Log.d("Fragment", "id = " + Integer.toHexString(f.getId()));	// idを出力.
    	Log.d("Fragment", "mNumber = " + ((Fragment1)f).mNumber);
    	getFragmentManager().putFragment(outState, "savedFragment", f);
    }

    @Override
    protected void onRestoreInstanceState(Bundle savedInstanceState){
    	super.onRestoreInstanceState(savedInstanceState);
    	Fragment f = getFragmentManager().getFragment(savedInstanceState, "savedFragment");
    	Log.d("Fragment", "restore fragment = " + f.toString());	// fragmentの内容を出力.
    	Log.d("Fragment", "id = " + Integer.toHexString(f.getId()));	// idを出力.
    	Log.d("Fragment", "mNumber = " + ((Fragment1)f).mNumber);
    }
    
}