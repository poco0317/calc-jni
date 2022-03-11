build:
	ifeq ($(UNAME), Linux)
		g++ -c -fPIC -I${JAVA_HOME}/include -I${JAVA_HOME}/include/linux com_etterna_calc_jni_MinaCalcJNI.cpp -o com_etterna_calc_jni_MinaCalcJNI.o
		g++ -shared -fPIC -o MinaCalcJNI.so com_etterna_calc_jni_MinaCalcJNI.o -lc
	else
		g++ -c -I%JAVA_HOME%\include -I%JAVA_HOME%\include\win32 -std=c++17 com_etterna_calc_jni_MinaCalcJNI.cpp -o com_etterna_calc_jni_MinaCalcJNI.o
		g++ -shared -o MinaCalcJNI.dll com_etterna_calc_jni_MinaCalcJNI.o -Wl,--add-stdcall-alias
	endif

all: build