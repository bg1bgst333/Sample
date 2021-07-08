package com.bgstation0.android.sample.view_;

import java.util.ArrayList;
import java.util.List;

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
        List<String> items = new ArrayList<String>();	// items���擾.
        for (int i = 0; i < 10000; i++){	// �A�C�e���ǉ�.
        	String itemStr = "Item" + Integer.toString(i);	// �A�C�e���ɕ\�����镶������Z�b�g.
        	items.add(itemStr);	// items��itemStr��ǉ�.
        }
        
        // ListView�I�u�W�F�N�g���擾.
        ListView listview1 = (ListView)findViewById(R.id.listview1);	// findViewById��listview1���擾.
        
        // �A�_�v�^�̃Z�b�g.
        CustomAdapter adapter = new CustomAdapter(this, R.layout.list_item, items);	// adapter�𐶐�.
        listview1.setAdapter(adapter);	// adapter���Z�b�g.
        
    }
    
}