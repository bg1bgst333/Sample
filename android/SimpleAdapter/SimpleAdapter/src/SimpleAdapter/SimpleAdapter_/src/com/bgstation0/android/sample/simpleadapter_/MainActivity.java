package com.bgstation0.android.sample.simpleadapter_;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.ListView;
import android.widget.SimpleAdapter;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // ListViewの取得.
        ListView listView1 = (ListView)findViewById(R.id.listview1);	// listView1を取得.
        
        // SimpleAdapterの定義.
        Map<String, String> map1 = new HashMap<String, String>();	// キーをString, 値をStringとするHashMapを生成し, map1に格納.
        map1.put("Name", "Taro");	// "Name"をキー, "Taro"を値とする.
        map1.put("Age", "20");	// "Age"をキー, "20"を値とする.
        Map<String, String> map2 = new HashMap<String, String>();	// キーをString, 値をStringとするHashMapを生成し, map2に格納.
        map2.put("Name", "Jiro");	// "Name"をキー, "Jiro"を値とする.
        map2.put("Age", "18");	// "Age"をキー, "18"を値とする.
        Map<String, String> map3 = new HashMap<String, String>();	// キーをString, 値をStringとするHashMapを生成し, map3に格納.
        map3.put("Name", "Saburo");	// "Name"をキー, "Saburo"を値とする.
        map3.put("Age", "16");	// "Age"をキー, "16"を値とする.
        List<Map<String, String>> list = new ArrayList<Map<String, String>>();	// listを生成.
        list.add(map1);	// map1を追加.
        list.add(map2);	// map2を追加.
        list.add(map3);	// map3を追加.
        SimpleAdapter adapter = new SimpleAdapter(this, list, R.layout.list_item, new String[]{"Name", "Age"}, new int[]{R.id.list_item_name, R.id.list_item_age});	// adapterを生成.
        listView1.setAdapter(adapter);	// adapterをセット.
        
    }
    
}