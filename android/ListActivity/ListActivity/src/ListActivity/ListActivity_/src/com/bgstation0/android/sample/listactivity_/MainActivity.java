package com.bgstation0.android.sample.listactivity_;

import android.app.Activity;
import android.app.ListActivity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.ArrayAdapter;

// ListActivty���p������MainActivity.
public class MainActivity extends ListActivity {

	// �����o�t�B�[���h.
	private String[] mNames = {"Taro", "Jiro", "Saburo", "Shiro", "Goro"};	// mNames�̏�����.
	
	// ������.
    @Override
    protected void onCreate(Bundle savedInstanceState) {
    	
    	// ����̏���.
        super.onCreate(savedInstanceState);
        //setContentView(R.layout.activity_main);	// �R���e���c�r���[�̃Z�b�g���s�v.
    	
    	// ArrayAdapter�̐���.
    	ArrayAdapter<String> arrayAdapter = new ArrayAdapter<String>(this, android.R.layout.simple_list_item_1, mNames);	// �A�C�e���̃��C�A�E�g�͊����android.R.layout.simple_list_item_1���g��.
    	
    	// �A�_�v�^�̃Z�b�g.
    	setListAdapter(arrayAdapter);	// setListAdapter��arrayAdapter���Z�b�g.
    	
    }
    
}