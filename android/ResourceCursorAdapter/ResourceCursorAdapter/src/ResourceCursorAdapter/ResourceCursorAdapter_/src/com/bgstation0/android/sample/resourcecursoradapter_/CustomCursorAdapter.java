package com.bgstation0.android.sample.resourcecursoradapter_;

import android.content.Context;
import android.database.Cursor;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ResourceCursorAdapter;
import android.widget.TextView;

public class CustomCursorAdapter extends ResourceCursorAdapter {

	// サブクラスの定義.
	private class ViewHolder{
		TextView name;	// 名前name.
		TextView age;	// 年齢age.
	}
		
	// コンストラクタ.
	public CustomCursorAdapter(Context context, int layout, Cursor c){
		super(context, layout, c, 0);	// 親コンストラクタを呼ぶ.
	}
		
	// Viewの生成.
	@Override
	public View newView(Context context, Cursor cursor, ViewGroup parent) {
		
		// Viewの生成.
		final View view = super.newView(context, cursor, parent);	// 親クラスのnewViewでview生成.
		
		// ViewHolderの生成.
		ViewHolder viewHolder = new ViewHolder();	// viewHolderの生成.
		viewHolder.name = (TextView)view.findViewById(R.id.list_item_name);	// list_item_nameで表されるTextViewをviewHolder.nameにセット.
		viewHolder.age = (TextView)view.findViewById(R.id.list_item_age);	// list_item_ageで表されるTextViewをviewHolder.ageにセット.
		
		// ViewHolderをタグにセット.
		view.setTag(viewHolder);	// viewHolderをセット.
				
		// viewを返す.	
		return view;	// viewを返す.
		
	}
		
	@Override
	public void bindView(View view, Context context, Cursor cursor) {
		
		// TODO Auto-generated method stub
		// タグからViewHolderの取得.
		ViewHolder viewHolder = (ViewHolder)view.getTag();	// viewHolderの取得.
		
		// Cursorから値を取り出す.
		final String name = cursor.getString(cursor.getColumnIndex("name"));	// nameを取得.
		final String age = String.valueOf(cursor.getInt(cursor.getColumnIndex("age")));	// ageを取得.
		
		// Viewにセット.
		viewHolder.name.setText(name);	// nameをセット.
		viewHolder.age.setText(age);	// ageをセット.
		
	}

}
