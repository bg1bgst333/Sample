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

	// �����o�t�B�[���h.
	ListFragment mCustomListFragment = null;
	
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // savedInstanceState�̃`�F�b�N.
        if (savedInstanceState == null){	// null�̎�.
        	
        	// FragmentManager, fragmentTransaction�̎擾.
        	FragmentManager fragmentManager = getFragmentManager();	// fragmentManager�̎擾.
        	FragmentTransaction fragmentTransaction = fragmentManager.beginTransaction();	// fragmentTransaction�̎擾.
        	mCustomListFragment = new CustomListFragment();	// customListFragment�𐶐�.
        	fragmentTransaction.add(R.id.framelayout1, mCustomListFragment);	// mCustomListFragment��ǉ�.
        	fragmentTransaction.commit();	// �R�~�b�g.
        	
        }
        
        // �{�^���n���h��
        Button button1 = (Button)findViewById(R.id.button1);
        button1.setOnClickListener(new View.OnClickListener() {
			
			@Override
			public void onClick(View v) {
				// TODO Auto-generated method stub
				//mCustomListFragment.setListShown(true);	// �\��.
				mCustomListFragment.setListShownNoAnimation(true);	// ��A�j���[�V�����ŕ\��.
			}
			
		});
        
    }
    
}