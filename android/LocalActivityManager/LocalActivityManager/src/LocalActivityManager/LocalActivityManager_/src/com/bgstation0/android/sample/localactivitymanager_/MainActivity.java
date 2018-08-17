package com.bgstation0.android.sample.localactivitymanager_;

import android.app.Activity;
import android.app.ActivityGroup;
import android.app.LocalActivityManager;
import android.content.Intent;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.Window;


public class MainActivity extends ActivityGroup {

	// �����o�t�B�[���h�̒�`.
	LocalActivityManager lam = null;
	
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // LocalActivityManager�̎擾.
        lam = getLocalActivityManager();	// lam�̎擾.
        
        // SubActivity��Intent�쐬.
        Intent intent1 = new Intent(this, SubActivity.class);	// intent1�쐬.
        // Window�̎擾.
        Window window1 = lam.startActivity("test1", intent1);	// intent1��n����, window1�̎擾.
        
        // SubActivity��Intent�쐬.
        Intent intent2 = new Intent(this, SubActivity.class);	// intent2�쐬.
        // Window�̎擾.
        Window window2 = lam.startActivity("test2", intent2);	// intent2��n����, window2�̎擾.
        
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
    	
    		// TextView1
    		case R.id.menu_textview1:
    			
    			// TextView1�u���b�N
				{
								        
				}
				
				break;
			
			// TextView1
    		case R.id.menu_textview2:
    			
    			// TextView2�u���b�N
				{
	
				}
				
				break;
				
    	}
    	return super.onOptionsItemSelected(item);	// �e�N���X���菈��
    	
    }
    
}