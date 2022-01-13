package com.bgstation0.android.sample.recyclerview.viewholder_;

import android.support.v7.widget.RecyclerView;
import android.view.View;
import android.widget.TextView;

// ビューホルダー
public class CustomViewHolder extends RecyclerView.ViewHolder {
    public TextView mtvName;
    public TextView mtvAddress;

    public CustomViewHolder(View view) {
        super(view);
        mtvName = (TextView) view.findViewById(R.id.text1);   // 独自のtext1を取得し, mtvNameに格納.
        mtvAddress = (TextView) view.findViewById(R.id.text2);   // 独自のtext2を取得し, mtvAddressに格納.
    }
}