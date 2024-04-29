package com.mi.ai.assist;

import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.LinearLayout;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import java.util.List;

public class DialogAdapter extends RecyclerView.Adapter<DialogAdapter.DialogViewHolder> {
    private List<DialogData> mData;

    public DialogAdapter(List<DialogData> data) {
        mData = data;
    }

    @NonNull
    @Override
    public DialogViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View itemView = LayoutInflater.from(parent.getContext())
                .inflate(R.layout.dialog_item, parent, false);
        return new DialogViewHolder(itemView);
    }

    @Override
    public void onBindViewHolder(DialogViewHolder holder, int position) {
        holder.UpdateUI(mData.get(position));
        Log.d("holder", "更新ui！");

        if (mData.get(position).type == 0) {
            holder.aiLayout.setVisibility(View.INVISIBLE);
            holder.meLayout.setVisibility(View.VISIBLE);
        } else {
            holder.aiLayout.setVisibility(View.VISIBLE);
            holder.meLayout.setVisibility(View.INVISIBLE);
        }
    }

    @Override
    public int getItemCount() {
        return mData.size();
    }

    public static class DialogViewHolder extends RecyclerView.ViewHolder {
        public TextView textView;
        public LinearLayout aiLayout;
        public TextView aiContent;
        public LinearLayout meLayout;
        public TextView meContent;
        public View mRoot;

        public DialogViewHolder(View view) {
            super(view);
            aiContent = view.findViewById(R.id.ai_content);
            meContent = view.findViewById(R.id.me_content);

            meLayout = view.findViewById(R.id.ll_me);
            aiLayout = view.findViewById(R.id.ll_ai);
            mRoot = view;
        }

        public void UpdateUI(DialogData data) {
            switch (data.fromType)
            {
                case ai:
                    aiContent.setText(data.content);
                    break;
                case me:
                    meContent.setText(data.content);
                    break;
            }
        }
    }
}
