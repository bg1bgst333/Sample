package com.bgstation0.android.sample.resources_;

import android.app.Activity;
import android.content.res.Resources;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;

// ���C���A�N�e�B�r�e�B�N���XMainActivity�̒�`.
public class MainActivity extends Activity {

	// �����o�t�B�[���h�̒�`
	static final String TAG = "MainActivity";	// TAG��"MainActivity"�ŏ�����.
	
	// �A�N�e�B�r�e�B������
    @Override
    protected void onCreate(Bundle savedInstanceState) {
    	
    	// ����̏���
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // ���\�[�X���琮���l�̎擾.
        Resources res = getResources();	// res���擾.
        int ten = res.getInteger(R.integer.ten);	// R.integer.ten����ten���擾.
        Log.d(TAG, "ten = " + ten);	// ten���o��.
        
    }
    
}
