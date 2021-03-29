package com.bgstation0.android.sample.patternviewholder_;

import java.util.ArrayList;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.ListView;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // ArrayList�Œǉ�����v�f���`.
        ArrayList<ListItem> listItems = new ArrayList<ListItem>();	// listItems����.
        for (int i = 0; i < 10000; i++){	// �A�C�e���ǉ�.
        	ListItem item = new ListItem();	// item����.
        	item.name = "Name" + Integer.toString(i);	// �A�C�e���ɕ\�����镶������Z�b�g.
        	item.address = "Address" + Integer.toString(i);	// �A�C�e���ɕ\�����镶������Z�b�g.
        	listItems.add(item);	// item��ǉ�.
        }
        
        // ListView�I�u�W�F�N�g���擾.
        ListView listview1 = (ListView)findViewById(R.id.listview1);	// findViewById��listview1���擾.
        
        // �A�_�v�^�̃Z�b�g.
        CustomAdapter adapter = new CustomAdapter(this, R.layout.list_item, listItems);	// adapter�𐶐�.
        listview1.setAdapter(adapter);	// adapter���Z�b�g.
        
    }
    
}