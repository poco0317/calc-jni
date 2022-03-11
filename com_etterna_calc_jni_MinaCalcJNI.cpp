#include "MinaCalc/MinaCalc.h"
#include <jni.h>

JNIEXPORT jstring JNICALL Java_com_etterna_calc_jni_MinaCalcJNI_test(JNIEnv* env, jobject obj) {

    std::string c = std::to_string(GetCalcVersion());

    jstring result = env->NewStringUTF(c.c_str());
    return result;
}
