package com.bgstation0.java.sample;

import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;

// カスタムアノテーション(コンパイル時にアノテーション情報を破棄.)
@Retention(value = RetentionPolicy.SOURCE)
public @interface CustomAnnotation {

}