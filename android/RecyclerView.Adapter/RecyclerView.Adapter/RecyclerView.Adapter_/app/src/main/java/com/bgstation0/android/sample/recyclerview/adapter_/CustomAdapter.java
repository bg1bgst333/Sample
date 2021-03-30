package com.bgstation0.android.sample.recyclerview.adapter_;

import android.content.Context;
import android.support.v7.widget.RecyclerView;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

import java.util.List;

// アダプタ
public class CustomAdapter extends RecyclerView.Adapter<CustomViewHolder> {
    private Context mContext;
    private List<String> mItems;
    public CustomAdapter(Context context, List<String> items){
        mContext = context;
        mItems = items;
    }
    @Override
    public CustomViewHolder onCreateViewHolder(ViewGroup parent, int viewType){
        LayoutInflater inflater = (LayoutInflater)mContext.getSystemService(Context.LAYOUT_INFLATER_SERVICE);
        View view = inflater.inflate(android.R.layout.simple_list_item_1, parent, false);
        CustomViewHolder customViewHolder = new CustomViewHolder(view);
        return customViewHolder;
    }
    @Override
    public void onBindViewHolder(CustomViewHolder holder, int position){
        String item = mItems.get(position);
        holder.mtvName.setText(item);
    }
    @Override
    public int getItemCount(){
        return mItems.size();
    }
}
