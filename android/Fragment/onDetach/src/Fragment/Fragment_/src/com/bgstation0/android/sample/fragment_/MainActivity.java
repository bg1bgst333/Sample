package com.bgstation0.android.sample.fragment_;

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

public class MainActivity extends Activity {

	// メンバフィールド
	Fragment mFragment = null;	// mFragmentをnullで初期化.
	
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        if (savedInstanceState == null){

        	// Buttonの初期化.
            Button button1 = (Button)findViewById(R.id.button1);	// button1を取得.
            button1.setOnClickListener(new OnClickListener() {	// リスナーをセット.
    			
    			@Override
    			public void onClick(View v) {
    				// TODO Auto-generated method stub
    				// Fragment2を表示し, Fragment1を非表示にする.
    				FragmentManager fragmentManager = getFragmentManager();	// fragmentManagerの取得.
    		        Fragment f1 = fragmentManager.findFragmentById(R.id.framelayout1);	// f1を取得.
    		        FragmentTransaction fragmentTransaction = fragmentManager.beginTransaction();	// fragmentTransactionの取得.
    		        fragmentTransaction.remove(f1);	// f1を削除.
    		        fragmentTransaction.commit();	// 確定.
    		        mFragment = f1;	// mFragmentにf1を格納.
    			}
    			
    		});
            Button button2 = (Button)findViewById(R.id.button2);
            button2.setOnClickListener(new OnClickListener() {	// リスナーをセット.
    			
    			@Override
    			public void onClick(View v) {
    				// TODO Auto-generated method stub
    				Activity activity = mFragment.getActivity();
    				if (activity == null){	// null.
    		    		Log.d("MainActivity", "activity == null");
    		    	}
    		    	else{	// nullでない.
    		    		Log.d("MainActivity", "activity != null");
    		    	}
    			}
    			
    		});
            
            // フラグメントの追加.
            FragmentManager fragmentManager = getFragmentManager();	// fragmentManagerの取得.
            FragmentTransaction fragmentTransaction = fragmentManager.beginTransaction();	// fragmentTransactionの取得.
            Fragment1 fragment1 = new Fragment1();	// fragment1の生成.
            fragmentTransaction.add(R.id.framelayout1, fragment1);	// fragment1を追加.
            fragmentTransaction.commit();	// 確定.
            
        }
        
    }
    
}