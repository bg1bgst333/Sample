package com.bgstation0.android.sample.fragmenttransaction_;

import android.app.Activity;
import android.app.Fragment;
import android.app.FragmentManager;
import android.app.FragmentTransaction;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        if (savedInstanceState == null){

        	// Button�̏�����.
            Button button1 = (Button)findViewById(R.id.button1);	// button1���擾.
            button1.setOnClickListener(new OnClickListener() {	// ���X�i�[���Z�b�g.
    			
    			@Override
    			public void onClick(View v) {
    				// TODO Auto-generated method stub
    				// Fragment2��\����, Fragment1���\���ɂ���.
    				FragmentManager fragmentManager = getFragmentManager();	// fragmentManager�̎擾.
    		        Fragment f1 = fragmentManager.findFragmentById(R.id.framelayout1);	// f1���擾.
    		        FragmentTransaction fragmentTransaction = fragmentManager.beginTransaction();	// fragmentTransaction�̎擾.
    		        fragmentTransaction.remove(f1);	// f1���폜.
    		        fragmentTransaction.commit();	// �m��.      
    			}
    			
    		});
            
            // �t���O�����g�̒ǉ�.
            FragmentManager fragmentManager = getFragmentManager();	// fragmentManager�̎擾.
            FragmentTransaction fragmentTransaction = fragmentManager.beginTransaction();	// fragmentTransaction�̎擾.
            Fragment1 fragment1 = new Fragment1();	// fragment1�̐���.
            fragmentTransaction.add(R.id.framelayout1, fragment1);	// fragment1��ǉ�.
            fragmentTransaction.commit();	// �m��.
            
        }
        
    }
    
}
