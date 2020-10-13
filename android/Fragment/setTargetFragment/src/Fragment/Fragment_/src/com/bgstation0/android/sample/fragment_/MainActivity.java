package com.bgstation0.android.sample.fragment_;

import android.app.Activity;
import android.app.FragmentManager;
import android.app.FragmentTransaction;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;

//���C���A�N�e�B�r�e�B
public class MainActivity extends Activity {

    // �����o�t�B�[���h
    static final String TAG = "MainActivity";	// TAG��"MainActivity"�ŏ�����.
    
    // ������.
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        
    	// ����̏���
    	super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // null�Ȃ�Fragment�ǉ�.
        if (savedInstanceState == null){
        
        	// Fragment�̒ǉ�.
        	FragmentManager fragmentManager = getFragmentManager();	// fragmentManager�̎擾.
        	FragmentTransaction fragmentTransaction = fragmentManager.beginTransaction();	// fragmentTransaction�̊J�n.
        	Fragment1 fragment1 = Fragment1.newInstance();	// fragment1�𐶐�.
        	fragmentTransaction.add(R.id.framelayout1, fragment1);	// fragment1��ǉ�.
        	fragmentTransaction.commit();	// �m��.
            
        }
        
    }
    
}