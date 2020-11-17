package com.bgstation0.android.sample.fragmenttransaction_;

import android.app.Activity;
import android.app.Fragment;
import android.app.FragmentManager;
import android.app.FragmentTransaction;
import android.content.Context;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.Toast;

public class MainActivity extends Activity {

	// �����o�t�B�[���h�̒�`
	CustomAsyncTask task = null;	// CustomAsyncTask�I�u�W�F�N�gtask��null��.
	Context context = null;	// context��null�ŏ�����.
	
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // context��this���i�[.
        context = this;
        
        // savedInstance��null�̎�.
        if (savedInstanceState == null){

        	// Button�̏�����.
            Button button1 = (Button)findViewById(R.id.button1);	// button1���擾.
            button1.setOnClickListener(new OnClickListener() {	// ���X�i�[���Z�b�g.
    			
    			@Override
    			public void onClick(View v) {
    				// TODO Auto-generated method stub
    				// CustomAsyncTask�ɂ��񓯊������𐶐���, ���s.
    		    	task = new CustomAsyncTask(context);	// CustomAsyncTask�I�u�W�F�N�g���쐬��, task�Ɋi�[.
    		    	task.execute(10);	// task.execute��10��n���Ď��s.
    			}
    			
    		});
            Button button2 = (Button)findViewById(R.id.button2);
            button2.setOnClickListener(new OnClickListener() {	// ���X�i�[���Z�b�g.
    			
    			@Override
    			public void onClick(View v) {
    				// TODO Auto-generated method stub
    				
    			}
    			
    		});
            
        }
        
    }
    
    // �t���O�����g�̒u��
    public void replaceFragment(){
    	
    	try{
    		FragmentManager fragmentManager = getFragmentManager();	// fragmentManager�̎擾.
    		Fragment1 fragment1 = new Fragment1();	// fragment1�𐶐�.
    		FragmentTransaction fragmentTransaction = fragmentManager.beginTransaction();	// fragmentTransaction�̎擾.
    		fragmentTransaction.replace(R.id.framelayout1, fragment1, "fragment1");	// fragment1��replace.
    		//fragmentTransaction.commit();
    		fragmentTransaction.commitAllowingStateLoss();
    		Log.d("MainActivity", "Fragment1");
    		Toast.makeText(context, "replace success!", Toast.LENGTH_LONG).show();
    	}
    	catch(Exception ex){
    		Toast.makeText(context, ex.toString(), Toast.LENGTH_LONG).show();
    		Log.d("MainActivity", ex.toString());
    	}
    }
    
}