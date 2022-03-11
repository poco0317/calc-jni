all:
ifneq ($(OS), Windows_NT)
	g++ -c -fPIC -I${JAVA_HOME}/include -I${JAVA_HOME}/include/linux MinaCalc/MinaCalc.cpp -std=c++17 com_etterna_calc_jni_MinaCalcJNI.cpp
	g++ -shared -fPIC -o MinaCalcJNI.so com_etterna_calc_jni_MinaCalcJNI.o MinaCalc.o -lc
else
	g++ -c -I${JAVA_HOME}\include -I${JAVA_HOME}\include\win32 -std=c++17 MinaCalc\MinaCalc.cpp com_etterna_calc_jni_MinaCalcJNI.cpp
	g++ -shared -o MinaCalcJNI.dll com_etterna_calc_jni_MinaCalcJNI.o MinaCalc.o -Wl,--add-stdcall-alias
endif
