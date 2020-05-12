package com.bgstation0.retrofit.sample.rf_;

import java.util.List;

import retrofit2.Call;
import retrofit2.http.GET;
import retrofit2.http.Path;

// GitHubレポジトリサービスインターフェース
public interface GitHubRepositoryService {
    @GET("/users/{user}/repos")
    Call<List<Repository>> listRepositories(@Path("user") String user);
}
