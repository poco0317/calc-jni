#include "MinaCalc/MinaCalc.h"
#include <jni.h>
#include <fstream>

extern "C" {
JNIEXPORT jstring JNICALL Java_com_etterna_calc_jni_MinaCalcJNI_getCalcVersion(JNIEnv* env, jobject obj) {

    std::string c = std::to_string(GetCalcVersion());
    jstring result = env->NewStringUTF(c.c_str());
    return result;
}

JNIEXPORT jfloatArray JNICALL Java_com_etterna_calc_jni_MinaCalcJNI_minaSDCalc(JNIEnv* env, jobject obj, jstring noteInfoPath, jfloat musicrate, jfloat goal) {

    const char* raw = env->GetStringUTFChars(noteInfoPath, NULL);
    if (!raw) {
        return env->NewFloatArray(0);
    }

    std::string path(raw);
    env->ReleaseStringUTFChars(noteInfoPath, raw);

    std::vector<NoteInfo> noteinfo;
    std::ifstream INFILE(path,
                            std::ios::in | std::ifstream::binary);
    INFILE.seekg(0, std::ios::end);
    noteinfo.resize(unsigned int(INFILE.tellg() / sizeof(NoteInfo)));
    INFILE.seekg(0, std::ios::beg);
    INFILE.read((char*)&noteinfo[0],
                noteinfo.capacity() * sizeof(NoteInfo));
    INFILE.close();

    thread_local std::unique_ptr<Calc> calc = std::make_unique<Calc>();
    const std::vector<float> ssrs = MinaSDCalc(noteinfo, musicrate, goal, calc.get());

    jfloatArray out = env->NewFloatArray(ssrs.size());
    env->SetFloatArrayRegion(out, 0, ssrs.size(), ssrs.data());
    return out;
}
}