package com.bgstation0.android.sample.scrollview_;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.ScrollView;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }
    
    // ���j���[���쐬���ꂽ��.
    @Override
    public boolean onCreateOptionsMenu(Menu menu){
    	
    	// ���j���[�̍쐬
    	getMenuInflater().inflate(R.menu.main, menu);	// getMenuInflater��MenuItem���擾��, ���̂܂�inflate�Ŏw�肳�ꂽR.menu.main������menu���쐬.
    	return true;	// true��Ԃ�.
    	
    }
    
    // ���j���[���I�����ꂽ��.
    @Override
    public boolean onOptionsItemSelected(MenuItem item){
    
    	// �ǂ̃��j���[���I�����ꂽ��.
    	switch (item.getItemId()){	// �A�C�e��ID���ƂɐU�蕪��.
    	
    		// Up
    		case R.id.menu_scrollup:
    			
    			// Up�u���b�N
				{
					
					// ��ɃX�N���[��.
					ScrollView scrollView = (ScrollView)findViewById(R.id.scrollview);	// scrollView���擾.
					scrollView.scrollTo(0, scrollView.getTop());	// scrollView.scrollTo�ŏ�ɃX�N���[��.
					
				}
				
				break;
				
    		case R.id.menu_scrolldown:
    			
    			// Down�u���b�N
				{
					
					// ���ɃX�N���[��.
					ScrollView scrollView = (ScrollView)findViewById(R.id.scrollview);	// scrollView���擾.
					scrollView.scrollTo(0, scrollView.getBottom());	// scrollView.scrollTo�ŉ��ɃX�N���[��.
				
				}
			
				break;
    
    	}
    	return super.onOptionsItemSelected(item);	// �e�N���X���菈��
    	
    }
    
}