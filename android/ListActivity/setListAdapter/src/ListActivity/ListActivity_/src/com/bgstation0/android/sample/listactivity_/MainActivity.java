package com.bgstation0.android.sample.listactivity_;

import java.util.ArrayList;

import android.app.Activity;
import android.app.ListActivity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.ArrayAdapter;

// ListActivty���p������MainActivity.
public class MainActivity extends ListActivity {

	// �����o�t�B�[���h.
	private ArrayList<ListItem> mListItems = null;	// mListItems��null.
	
	// ������.
    @Override
    protected void onCreate(Bundle savedInstanceState) {
    	
    	// ����̏���.
        super.onCreate(savedInstanceState);
        //setContentView(R.layout.activity_main);	// �R���e���c�r���[�̃Z�b�g���s�v.
    	
    	// CustomAdapter�̐���.
    	//ArrayAdapter<String> arrayAdapter = new ArrayAdapter<String>(this, android.R.layout.simple_list_item_1, mNames);	// �A�C�e���̃��C�A�E�g�͊����android.R.layout.simple_list_item_1���g��.
        mListItems = new ArrayList<ListItem>();	// mListItems�𐶐�.
        ListItem item1 = new ListItem();
        item1.name = "Taro";
        item1.address = "Tokyo";
        mListItems.add(item1);
        ListItem item2 = new ListItem();
        item2.name = "Jiro";
        item2.address = "Osaka";
        mListItems.add(item2);
        ListItem item3 = new ListItem();
        item3.name = "Saburo";
        item3.address = "Nagoya";
        mListItems.add(item3);
    	CustomAdapter customAdapter = new CustomAdapter(this, R.layout.list_item, mListItems);	// customAdapter�𐶐�.
    	
    	// �A�_�v�^�̃Z�b�g.
    	setListAdapter(customAdapter);	// setListAdapter��customAdapter���Z�b�g.
    	
    }
    
}