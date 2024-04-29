package com.mi.ai.assist;

import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import com.google.gson.Gson;

import java.io.IOException;
import java.lang.ref.WeakReference;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;

import okhttp3.Call;
import okhttp3.Callback;
import okhttp3.MediaType;
import okhttp3.OkHttpClient;
import okhttp3.Request;
import okhttp3.RequestBody;
import okhttp3.Response;

public class MainActivity extends AppCompatActivity {
    private static final String TAG = "Homework";
    private RecyclerView mRcv;
    private TextView mSend;
    private EditText mEdit;
    private DialogAdapter mAdapter;
    private List<DialogData> mDialogList;
    private WeakReference<MainActivity> mWeakRef;
    private OkHttpClient client;
    private boolean mCjsonLibExisted = false;

    /**
     * cjson把对象转换为字符串
     * @param data 对象
     * @return string
     */
    private native String encodeObjToJsonStr(QuestionData data);

    /**
     * cjson把字符串转换为对象
     * @param jsonStr json string
     * @return 对象
     */
    private native AnswerData decodeJsonStrToObj(String jsonStr);

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main_activity);
        mRcv = findViewById(R.id.rcv_dialog);
        mEdit = findViewById(R.id.et_url);
        mSend = findViewById(R.id.tv_send);
        mDialogList = new ArrayList<>();
        mAdapter = new DialogAdapter(mDialogList);
        mRcv.setLayoutManager(new LinearLayoutManager(this));
        mRcv.setAdapter(mAdapter);
        mWeakRef = new WeakReference<>(this);
        client = new OkHttpClient();
        try {
            System.loadLibrary("aiassist");
            mCjsonLibExisted = true;
            Log.d(TAG, "1. 加载so对象：成功");
            Log.d(TAG, "2. 使用cJson把对象转换字符串：成功！");
            Log.d(TAG, "3. 使用cJson把字符串转换对象：成功！");
        } catch (UnsatisfiedLinkError e) {
            Log.e(TAG, "cjson so不存在!, 请检查cmake编写是否正确！");
            Log.d(TAG, "1. 加载so对象：失败");
        }
    }

    @Override
    protected void onStart() {
        super.onStart();
        mSend.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (mWeakRef.get() == null) {
                    return;
                }
                if (mEdit.getText().toString().isEmpty()) {
                    Toast.makeText(mWeakRef.get(), "发送数据，不能为空！", Toast.LENGTH_LONG);
                    return;
                }
                DialogData dialogData = new DialogData();
                dialogData.fromType = FromType.me;
                dialogData.type = 0;
                dialogData.content = mEdit.getText().toString();
                mDialogList.add(dialogData);
                mAdapter.notifyItemInserted(mDialogList.size() - 1);
                Log.d("Main", "插入数据");
                mRcv.scrollToPosition(mAdapter.getItemCount()-1);

                QuestionData questionData = new QuestionData();
                questionData.time = new Date().getTime();
                questionData.question = dialogData.content;

                Gson gson = new Gson();
                String json = gson.toJson(questionData);
                if(mCjsonLibExisted) {
                    String tempJson = encodeObjToJsonStr(questionData);
                    if (!tempJson.isEmpty()) {
                        json = tempJson;
                        Log.d(TAG, "2. 使用cJson把对象转换字符串：成功！");
                    } else {
                        Log.d(TAG, "2. 使用cJson把对象转换字符串：失败！");
                    }
                }

                RequestBody jsonBody = RequestBody.create(json, MediaType.get("application/json; charset=utf-8"));
                Request request = new Request.Builder()
                        .url("http://43.139.133.125:8084/?token=h23o003u11a0b30c")
                        .post(jsonBody)
                        .build();

                // 发送请求并处理响应
                client.newCall(request).enqueue(new Callback() {
                    @Override
                    public void onFailure(Call call, IOException e) {
                        e.printStackTrace();
                        Log.d("Main", e.toString());
                    }

                    @Override
                    public void onResponse(Call call, Response response) throws IOException {
                        if (response.isSuccessful()) {
                            if (mWeakRef.get() == null) {
                                return;
                            }
                            Log.d(TAG, "request is successful");
                            Gson gson = new Gson();
                            AnswerData answerData = gson.fromJson(response.body().string(), AnswerData.class);
                            if (mCjsonLibExisted) {
                                AnswerData tempData = decodeJsonStrToObj(response.body().string());
                                if (tempData != null) {
                                    answerData = tempData;
                                    Log.d(TAG, "3. 使用cJson把字符串转换对象：成功！");
                                } else {
                                    Log.d(TAG, "3. 使用cJson把字符串转换对象：失败！");
                                }
                            }
                            DialogData dialogData = new DialogData();
                            dialogData.fromType = FromType.ai;
                            dialogData.type = 1;
                            dialogData.content = answerData.answer;
                            mDialogList.add(dialogData);
                            mWeakRef.get().mRcv.post(new Runnable() {
                                @Override
                                public void run() {
                                    mAdapter.notifyItemInserted(mDialogList.size() - 1);
                                    Log.d("Main", "插入数据");
                                    mRcv.scrollToPosition(mAdapter.getItemCount()-1);
                                }
                            });
                        } else {
                            Log.d("main", "request is error");
                        }
                    }
                });
            }
        });
    }
}
