package com.bgstation0.android.sample.accountmanager_;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.TextView;

// ListItem�p�A�_�v�^�[ListItemAdapter
public class ListItemAdapter extends ArrayAdapter<ListItem> {

	// �����o�t�B�[���h�̒�`.
	LayoutInflater mInflater = null;	// mInflater��null�ŏ�����.
	
	// �R���X�g���N�^
	public ListItemAdapter(Context context, int resource, ListItem[] objects){
		super(context, resource, objects);	// �e�R���X�g���N�^.
		mInflater = (LayoutInflater)context.getSystemService(context.LAYOUT_INFLATER_SERVICE);	// mInflater�̎擾.
	}
	
	// �A�C�e���\���̃J�X�^�}�C�Y.
	@Override
	public View getView(int position, View convertView, ViewGroup parent){
		// convertView��null�̎�.
		if (convertView == null){
			convertView = mInflater.inflate(R.layout.list_item, null);	// null�Ȃ琶��.
		}
		TextView tvName = (TextView)convertView.findViewById(R.id.list_item_name);	// tvName���擾.
		tvName.setText(getItem(position).name);	// name���Z�b�g.
		return convertView;	// convertView��Ԃ�.
	}
	
}