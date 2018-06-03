#include <jni.h>
#include <string>
#include "log.h"

extern "C" JNIEXPORT jstring
JNICALL
Java_com_mobilegg_jnidemo_JNIUtil_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    LOGI("Java_com_mobilegg_jnidemo_JNIUtil_stringFromJNI");
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

extern "C" JNIEXPORT void
JNICALL
Java_com_mobilegg_jnidemo_JNIUtil_testJString(
        JNIEnv *env, jobject thiz, jstring jstr) {
    LOGI("Java_com_mobilegg_jnidemo_JNIUtil_testJString");
    int len = env->GetStringUTFLength(jstr);
    LOGI("len = %d", len);
    const char *str = env->GetStringUTFChars(jstr,NULL);
    LOGI("str = %s", str);
    env->ReleaseStringUTFChars(jstr,str);
}

extern "C" JNIEXPORT void
JNICALL
Java_com_mobilegg_jnidemo_JNIUtil_testJIntArray(
        JNIEnv *env, jobject thiz, jintArray jArray) {
    LOGI("Java_com_mobilegg_jnidemo_JNIUtil_testJIntArray");
    int len = env->GetArrayLength(jArray);
    LOGI("len = %d", len);
    jint *intArray = env->GetIntArrayElements(jArray, NULL);
    for(int i=0; i<len; i++){
        jint item = intArray[i];
        LOGI("intArray[%d] = %d", i, item);
    }
    env->ReleaseIntArrayElements(jArray, intArray, NULL);
}

extern "C" JNIEXPORT void
JNICALL
Java_com_mobilegg_jnidemo_JNIUtil_testJObjectArray(
        JNIEnv *env, jobject thiz, jobjectArray jArray) {
    LOGI("Java_com_mobilegg_jnidemo_JNIUtil_testJObjectArray");
    int len = env->GetArrayLength(jArray);
    LOGI("len = %d", len);
    for(int i=0; i<len; i++){
        jstring item = (jstring)env->GetObjectArrayElement(jArray, i);
        const char *itemStr = env->GetStringUTFChars(item,NULL);
        LOGI("objectArray[%d] = %s", i, itemStr);
        env->ReleaseStringUTFChars(item,itemStr);
    }
}

extern "C" JNIEXPORT void
JNICALL
Java_com_mobilegg_jnidemo_JNIUtil_testComplexObject(
        JNIEnv *env, jobject thiz, jobject jobj) {
    LOGI("Java_com_mobilegg_jnidemo_JNIUtil_testComplexObject");

    jclass clazz = env->GetObjectClass(jobj);
    jfieldID fid_name = env->GetFieldID(clazz,"name","Ljava/lang/String;");
    jfieldID fid_id = env->GetFieldID(clazz,"id","Ljava/lang/String;");
    jfieldID fid_age = env->GetFieldID(clazz,"age","I");
    jfieldID fid_isBoy = env->GetFieldID(clazz,"isBoy","Z");


    jstring name = (jstring) env->GetObjectField(jobj, fid_name);
    jstring id = (jstring) env->GetObjectField(jobj, fid_id);
    jint age = env->GetIntField(jobj, fid_age);
    jboolean isBoy = env->GetBooleanField(jobj, fid_isBoy);

    const char *nameStr = env->GetStringUTFChars(name,NULL);
    LOGI("nameStr = %s", nameStr);
    env->ReleaseStringUTFChars(name,nameStr);

    const char *idStr = env->GetStringUTFChars(id,NULL);
    LOGI("idStr = %s", idStr);
    env->ReleaseStringUTFChars(id,idStr);

    LOGI("age = %d", age);
    LOGI("isBoy = %d", isBoy);
}