package com.bgstation0.java.sample;

import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;

// カスタムアノテーション(実行時にもアノテーション情報を取得できるようにする.)
@Retention(value = RetentionPolicy.RUNTIME)
public @interface CustomAnnotation {

}