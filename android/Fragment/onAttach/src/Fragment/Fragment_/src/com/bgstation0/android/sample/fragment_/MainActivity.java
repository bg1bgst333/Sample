package com.bgstation0.android.sample.fragment_;

import android.app.Activity;
import android.app.FragmentManager;
import android.app.FragmentTransaction;
import android.content.Context;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.Toast;

// メインアクティビティ
public class MainActivity extends Activity implements CustomListener{

	// メンバフィールド
	static final String TAG = "MainActivity";	// TAGを"MainActivity"で初期化.
	Context mContext = null;	// mContextをnullで初期化.
	
	// 生成時.
    @Override
    protected void onCreate(Bundle savedInstanceState) {
    	
    	// 既定の処理.
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        mContext = this;	// mContextにthisをセット.
        
        if (savedInstanceState == null){
        	
        	// Fragmentの追加.
        	FragmentManager fragmentManager = getFragmentManager();	// fragmentManagerの取得.
        	FragmentTransaction fragmentTransaction = fragmentManager.beginTransaction();	// fragmentTransactionの開始.
        	Fragment1 fragment1 = Fragment1.newInstance();	// fragment1を生成.
        	fragmentTransaction.replace(R.id.framelayout1, fragment1);	// fragment1に置換.
        	fragmentTransaction.commit();	// 確定.
        
        }
        
    }
    
    @Override
	public void onButtonClicked(int no){
		//Toast.makeText(mContext, TAG + " Callback", Toast.LENGTH_LONG).show();	// Toast表示.
    	if (no == 1){	// 1の時.
    		// Fragment2に置換.
    		FragmentManager fragmentManager = getFragmentManager();	// fragmentManagerの取得.
        	FragmentTransaction fragmentTransaction = fragmentManager.beginTransaction();	// fragmentTransactionの開始.
        	Fragment2 fragment2 = Fragment2.newInstance();	// fragment2を生成.
        	fragmentTransaction.replace(R.id.framelayout1, fragment2);	// fragment2に置換.
        	fragmentTransaction.commit();	// 確定.    		
    	}
    	else if (no == 2){	// 2の時.
    		// Fragment1に置換.
    		FragmentManager fragmentManager = getFragmentManager();	// fragmentManagerの取得.
        	FragmentTransaction fragmentTransaction = fragmentManager.beginTransaction();	// fragmentTransactionの開始.
        	Fragment1 fragment1 = Fragment1.newInstance();	// fragment1を生成.
        	fragmentTransaction.replace(R.id.framelayout1, fragment1);	// fragment1に置換.
        	fragmentTransaction.commit();	// 確定.
    	}
	}
    
}
