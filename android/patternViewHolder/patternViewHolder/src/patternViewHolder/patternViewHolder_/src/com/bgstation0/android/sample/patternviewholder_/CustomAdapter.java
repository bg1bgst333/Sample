package com.bgstation0.android.sample.patternviewholder_;

import java.util.List;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.TextView;

//�J�X�^���A�_�v�^
public class CustomAdapter extends ArrayAdapter<ListItem> {

	// �����o�t�B�[���h�̒�`.
	private final LayoutInflater mInflater;	// �C���t���[�^mInflater.
	
	// �R���X�g���N�^.
	public CustomAdapter(Context context, int textViewResourceId, List<ListItem> objects) {
		super(context, textViewResourceId, objects);
		// TODO Auto-generated constructor stub
		mInflater = (LayoutInflater)context.getSystemService(Context.LAYOUT_INFLATER_SERVICE);	// mInflater�𐶐�.
	}

	// �A�C�e���\���̃J�X�^�}�C�Y
	@Override
	public View getView(int position, View convertView, ViewGroup parent) {
		
		// ViewHolder������.
		ViewHolder viewHolder = null;	// viewHolder��null�ŏ�����.
	
		// convertView��null�̎�.
		if (convertView == null){
			viewHolder = new ViewHolder();	// ����.
			convertView = mInflater.inflate(R.layout.list_item, null);	// convertView��null�Ȃ�inflater.inflate�Ŏ擾.(�����͓���̂łЂƂ܂������������̂��Ƒ����Ă���.)
			viewHolder.tvName = (TextView)convertView.findViewById(R.id.list_item_name_textview);	// viewHolder.tvName���擾.
			viewHolder.tvAddress = (TextView)convertView.findViewById(R.id.list_item_address_textview);	// viewHolder.tvAddress���擾.
			convertView.setTag(viewHolder);	// 
		}
		else{	// null�łȂ���.
			viewHolder = (ViewHolder)convertView.getTag();	// viewHolder���擾.
		}
		
		// �A�C�e���̃Z�b�g.
		ListItem item = getItem(position);	// item�擾.
		viewHolder.tvName.setText(item.name);	// name�Z�b�g.
		viewHolder.tvAddress.setText(item.address);	// address�Z�b�g.
		return convertView;	// convertView��Ԃ�.
	
	}
	
}