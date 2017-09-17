#include <jni.h>
#include <string>

extern "C"
JNIEXPORT jstring JNICALL
Java_com_bgstation0_ndk_sample_ntv_1_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

// jintを返すC++関数Java_com_bgstation0_ndk_sample_ntv_1_MainActivity_intFromJNI
extern "C" JNIEXPORT jint JNICALL Java_com_bgstation0_ndk_sample_ntv_1_MainActivity_intFromJNI(JNIEnv *env, jobject /*this*/){

    // 10を返す.
    return 10;  // returnで10を返す.

}
