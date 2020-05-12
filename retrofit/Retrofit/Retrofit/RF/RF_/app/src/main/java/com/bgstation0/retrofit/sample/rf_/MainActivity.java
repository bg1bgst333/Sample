package com.bgstation0.retrofit.sample.rf_;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.ArrayAdapter;
import android.widget.ListView;

import java.util.ArrayList;
import java.util.List;

import retrofit2.Call;
import retrofit2.Callback;
import retrofit2.Response;
import retrofit2.Retrofit;
import retrofit2.converter.gson.GsonConverterFactory;

public class MainActivity extends AppCompatActivity {

    // メンバフィールドの定義
    ArrayList<String> mItems = null;
    ListView mListView = null;

    @Override
    protected void onCreate(Bundle savedInstanceState) {

        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // リストビューの取得.
        mListView = findViewById(R.id.listView1);   // mListViewを取得.

        // Retrofitオブジェクトの生成.
        Retrofit retrofit = new Retrofit.Builder().baseUrl("https://api.github.com").addConverterFactory(GsonConverterFactory.create()).build();    // GitHubAPI用のretrofit作成.

        // GitHubRepositoryServiceの生成.
        GitHubRepositoryService service = retrofit.create(GitHubRepositoryService.class);   // serviceを生成.
        Call<List<Repository>> repos = service.listRepositories("bg1bgst333");  // reposを取得.

        // ListViewへの反映.
        repos.enqueue(new Callback<List<Repository>>() {
            @Override
            public void onResponse(Call<List<Repository>> call, Response<List<Repository>> response) {
                mItems = new ArrayList<>();
                for (Repository repo : response.body()){
                    mItems.add(repo.getName());
                }
                ArrayAdapter<String> adapter = new ArrayAdapter<>(MainActivity.this, android.R.layout.simple_list_item_1, mItems);  // adapterを生成.
                mListView.setAdapter(adapter);  // mListViewにadapterをセット.
            }

            @Override
            public void onFailure(Call<List<Repository>> call, Throwable t) {

            }
        });

    }

}