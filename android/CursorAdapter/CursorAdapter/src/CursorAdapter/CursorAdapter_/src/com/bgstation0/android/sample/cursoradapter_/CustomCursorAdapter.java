package com.bgstation0.android.sample.cursoradapter_;

import android.content.Context;
import android.database.Cursor;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.CursorAdapter;
import android.widget.TextView;

public class CustomCursorAdapter extends CursorAdapter {

	// メンバフィールドの定義.
	private LayoutInflater mInflater = null;	// mInflaterにnullをセット.
	
	// サブクラスの定義.
	private class ViewHolder{
		TextView name;	// 名前name.
		TextView age;	// 年齢age.
	}
	
	// コンストラクタ.
	public CustomCursorAdapter(Context context, Cursor c, boolean autoRequery){
		super(context, c, autoRequery);	// 親コンストラクタを呼ぶ.
		mInflater = (LayoutInflater)context.getSystemService(Context.LAYOUT_INFLATER_SERVICE);	// mInflaterの生成.
	}
	
	// Viewの生成.
	@Override
	public View newView(Context context, Cursor cursor, ViewGroup parent) {

		// TODO Auto-generated method stub
		// Viewの生成.
		final View view = mInflater.inflate(R.layout.list_item, null);	// view生成.
		
		// ViewHolderの生成.
		ViewHolder viewHolder = new ViewHolder();	// viewHolderの生成.
		viewHolder.name = (TextView)view.findViewById(R.id.list_item_name);	// list_item_nameで表されるTextViewをviewHolder.nameにセット.
		viewHolder.age = (TextView)view.findViewById(R.id.list_item_age);	// list_item_ageで表されるTextViewをviewHolder.ageにセット.
		
		// ViewHolderをタグにセット.
		view.setTag(viewHolder);	// viewHolderをセット.
		
		// viewを返す.
		return view;	// viewを返す.
		
	}

	// Viewの再利用.
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