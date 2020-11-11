package com.bgstation0.android.sample.listfragment_;

import android.app.Activity;
import android.app.FragmentManager;
import android.app.FragmentTransaction;
import android.app.ListFragment;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;

public class MainActivity extends Activity {

	// メンバフィールド.
	ListFragment mCustomListFragment = null;
	
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // savedInstanceStateのチェック.
        if (savedInstanceState == null){	// nullの時.
        	
        	// FragmentManager, fragmentTransactionの取得.
        	FragmentManager fragmentManager = getFragmentManager();	// fragmentManagerの取得.
        	FragmentTransaction fragmentTransaction = fragmentManager.beginTransaction();	// fragmentTransactionの取得.
        	mCustomListFragment = new CustomListFragment();	// customListFragmentを生成.
        	fragmentTransaction.add(R.id.framelayout1, mCustomListFragment);	// mCustomListFragmentを追加.
        	fragmentTransaction.commit();	// コミット.
        	
        }
        
        // ボタンハンドラ
        Button button1 = (Button)findViewById(R.id.button1);
        button1.setOnClickListener(new View.OnClickListener() {
			
			@Override
			public void onClick(View v) {
				// TODO Auto-generated method stub
				//mCustomListFragment.setListShown(true);	// 表示.
				mCustomListFragment.setListShownNoAnimation(true);	// 非アニメーションで表示.
			}
			
		});
        
    }
    
}