package com.bgstation0.android.sample.activity_;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.Toast;

public class MainActivity extends Activity implements OnClickListener{	// View.OnClickListener������.

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // button1���擾��, OnClickListener�Ƃ��Ď��g���Z�b�g.
        Button button1 = (Button)findViewById(R.id.button1);	// findViewById��R.id.button1���擾.
        button1.setOnClickListener(this);	// button1.setOnClickListener��this(���g)���Z�b�g.
    }
    
    // View.OnClickListener�C���^�t�F�[�X�̃I�[�o�[���C�h���\�b�h������.
    public void onClick(View v){	// onClick���I�[�o�[���C�h.
    	
    	// �{�^����ID���ƂɐU�蕪����.
    	switch (v.getId()){	// v.getId���ƂɐU�蕪����.
    	
    		// button1�̎�.
    		case R.id.button1:
    			
    			// R.id.button1�u���b�N
    			{
    				
    				// �A�N�e�B�r�e�B�̋N��
    				Intent intent = new Intent(this, SubActivity.class);	// SubActivity���N������intent�̍쐬.
    				startActivityForResult(intent, 1);	// startActivityForResult��intent�����N�G�X�g�R�[�h1�ŋN��.
    			}
    			
    			// ������.
    			break;	// break�Ŕ�����.
    			
    	}
    	
    }
    
    // �A�N�e�B�r�e�B�̌��ʂ��Ԃ��Ă����Ƃ�.
    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data){
    	
    	// ���ʂɑ΂��鏈��.
    	super.onActivityResult(requestCode, resultCode, data);	// �܂��e�N���XonActivityResult.
    	
    	// �L�����Z���Ȃ�I��.
    	if (resultCode == RESULT_CANCELED){	// RESULT_CANCELED�̏ꍇ.
    		Toast.makeText(this, "RESULT_CANCELED", Toast.LENGTH_LONG).show();	// "RESULT_CANCELED"�ƕ\��.
    		return;	// ���������I��.
    	}
    	
    	// �L�����Z���łȂ���ΐU�蕪��.
    	switch (requestCode){	// requestCode�ŐU�蕪��.
    		
    		// requestCode��1.
    		case 1:	// 1�̎�.
    			
    			// requestCode = 1.
    			{
    				
    				String message = data.getStringExtra("message");	// �����̃L�["message"����data.getStringExtra�Œl���擾.
    				Toast.makeText(this, message, Toast.LENGTH_LONG).show();	// Toast��message��\��.
    				
    			}
    			
    			// ������.
    			break;	// break�Ŕ�����.
    			
    	}
    	
    }
    
}
