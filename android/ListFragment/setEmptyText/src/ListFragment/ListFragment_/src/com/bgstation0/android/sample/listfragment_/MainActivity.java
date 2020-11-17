package com.bgstation0.android.sample.listfragment_;

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
        
        // savedInstanceState�̃`�F�b�N.
        if (savedInstanceState == null){	// null�̎�.
        	
        	// FragmentManager, fragmentTransaction�̎擾.
        	FragmentManager fragmentManager = getFragmentManager();	// fragmentManager�̎擾.
        	FragmentTransaction fragmentTransaction = fragmentManager.beginTransaction();	// fragmentTransaction�̎擾.
        	CustomListFragment customListFragment = new CustomListFragment();	// customListFragment�𐶐�.
        	fragmentTransaction.add(R.id.framelayout1, customListFragment);	// customListFragment��ǉ�.
        	fragmentTransaction.commit();	// �R�~�b�g.
        	
        }
        
    }
    
}