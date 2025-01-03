package com.bgstation0.android.sample.viewpager_;

import java.util.ArrayList;
import java.util.List;

import android.app.Activity;
import android.content.Context;
import android.support.v4.view.PagerAdapter;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

public class CustomPagerAdapter extends PagerAdapter {

	// メンバフィールドの定義.
	private Context context = null;	// Context型contextをnullで初期化.
	private List<PageItem> list = null;	// List<PageItem>インスタンスlistをnullで初期化.
	private LayoutInflater inflater = null;	// LayoutInflater型inflaterをnullで初期化.
	
	// コンストラクタ
	public CustomPagerAdapter(Context context){
		
		// メンバにセット.
		this.context = context;	// 引数contextをメンバthis.contextにセット.
		this.list = new ArrayList<PageItem>();	// ArrayListオブジェクトをlistにセット.
		this.inflater = (LayoutInflater)context.getSystemService(Context.LAYOUT_INFLATER_SERVICE);	// inflater生成.
		
	}
	
	// 追加.
	public void add(PageItem item){
		list.add(item);	// list.addでitemを追加.
	}
	
	@Override
	public Object instantiateItem(ViewGroup container, int position){
		
		// itemを取得..
		PageItem item = list.get(position);	// this.get(position)でitemを取得.
		
		// Viewの生成.
		View view = inflater.inflate(R.layout.page_layout, container, false);	// inflater.inflateでviewを生成.
		TextView nametv = (TextView)view.findViewById(R.id.name_textview);	// nametvを取得.
		nametv.setText(item.name);	// nametv.setTextにitem.nameをセット.
		TextView numtv = (TextView)view.findViewById(R.id.num_textview);	// numtvを取得.
		numtv.setText(String.valueOf(item.num));	// numtv.setTextにitem.numをセット.
		
		// 追加.
		container.addView(view);	// container.addViewでviewを追加.
		return view;	// viewを返す.
		
	}
	
	@Override
    public void destroyItem(ViewGroup container, int position, Object object) {
        // containerからobject削除.
        container.removeView((View) object);	// container.removeViewでobject削除.
    }
	
	@Override
	public int getCount() {
		// TODO Auto-generated method stub
		return list.size();	// list.size()を返す.
	}

	@Override
	public boolean isViewFromObject(View arg0, Object arg1) {
		// TODO Auto-generated method stub
		return arg0 == (View) arg1;	// arg1がviewかどうか判定.
	}

}
