package com.bgstation0.android.sample.listfragment_;

import java.util.ArrayList;

import android.app.ListFragment;
import android.os.Bundle;
import android.widget.ArrayAdapter;

// ListFragment���p������CustomListFragment.
public class CustomListFragment extends ListFragment {

	// �����o�t�B�[���h.
	//private String[] mNames = {"Taro", "Jiro", "Saburo", "Shiro", "Goro"};	// mNames�̏�����.
	private ArrayList<ListItem> mItems = null;	// mItems��null�ŏ�����.	
			
	// �A�N�e�B�r�e�B������.
	@Override
	public void onActivityCreated(Bundle savedInstanceState){
		
		// ����̏���.
		super.onActivityCreated(savedInstanceState);
		
		// mItems������.
		mItems = new ArrayList<ListItem>();
		ListItem item1 = new ListItem();
		item1.name = "Taro";
		item1.address = "Tokyo";
		mItems.add(item1);	// item1��ǉ�.
		ListItem item2 = new ListItem();
		item2.name = "Jiro";
		item2.address = "Osaka";
		mItems.add(item2);	// item2��ǉ�.
		ListItem item3 = new ListItem();
		item3.name = "Saburo";
		item3.address = "Nagoya";
		mItems.add(item3);	// item3��ǉ�.
		
		// CustomAdapter�̐���.
		CustomAdapter customAdapter = new CustomAdapter(getActivity(), R.layout.list_item, mItems);	// customAdapter�̐���.
		
    	// �A�_�v�^�̃Z�b�g.
    	setListAdapter(customAdapter);	// setListAdapter��customAdapter���Z�b�g.
		
	}
	
}