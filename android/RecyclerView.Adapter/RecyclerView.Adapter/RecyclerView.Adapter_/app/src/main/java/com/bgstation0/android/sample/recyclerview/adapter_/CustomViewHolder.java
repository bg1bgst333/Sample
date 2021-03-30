package com.bgstation0.android.sample.recyclerview.adapter_;

import android.support.v7.widget.RecyclerView;
import android.view.View;
import android.widget.TextView;

// ビューホルダー
public class CustomViewHolder extends RecyclerView.ViewHolder {
    public TextView mtvName;
    public CustomViewHolder(View view){
        super(view);
        mtvName = (TextView)view.findViewById(android.R.id.text1);   // android既定のtext1を取得し, mtvNameに格納.
    }
}
