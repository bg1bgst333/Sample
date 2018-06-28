package com.bgstation0.android.sample.activity_;

import android.app.Activity;
import android.app.SearchManager;
import android.content.Intent;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.Toast;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        
    	super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    
        // �����_�C�A���O�\��.
        //super.onSearchRequested();	// �e�N���X��onSearchRequested���Ă�Ō����_�C�A���O��\������̂���ʓI�炵��.(�n���h���Ȃ̂�.)
        onSearchRequested();	// �I�[�o�[���C�h����onSearchRequested���Ă�.
        
    }
    
    @Override
    public boolean onSearchRequested() {
    
    	// �V�X�e�����ʂ̌����_�C�A���O��\��.
        Bundle args = new Bundle();	// args�𐶐�.
        args.putString("userStr", "test123");	// �L�[��"userStr", �l��"test123"�Ƃ��ăZ�b�g.
        startSearch("ABC", false, args, false);	// startSearch�Ō���.(���[�J������, args��n��.)
    	return true;
    	
    }
    
    @Override
    protected void onNewIntent(Intent intent){
    	
    	super.onNewIntent(intent);
    	
    	// �����N�G���̎擾.
        if (intent != null){	// intent��null�łȂ���.
        	String action = intent.getAction();	// action���擾.
        	if (action != null){	// action��null�łȂ���.
        		if (action.equals(Intent.ACTION_SEARCH)){	// action��Intent.ACTION_SEARCH�̎�.
        			String query = intent.getStringExtra(SearchManager.QUERY);	// query���擾.
        			Toast.makeText(this, "query = " + query, Toast.LENGTH_LONG).show();	// query��\��.
        			Bundle args = intent.getBundleExtra(SearchManager.APP_DATA);	// args���擾.
        			if (args != null){	// args��null�łȂ���.
        				String userStr = args.getString("userStr");	// userStr���擾.
        				Toast.makeText(this, "userStr = " + userStr, Toast.LENGTH_LONG).show();	// userStr��\��.
        			}
        		}
        	}
        }
    	
    }
    
}