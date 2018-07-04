#pragma once
#include <cstdio>
#ifndef WIN32
#define _ANDROID
#endif

#ifdef _ANDROID

#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>

#include <android/log.h>
#define  LOG_TAG    "GAME"
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)

#else

#ifdef _WIN32

#include <GLES2\gl2.h>
#define LOGI(...) printf(__VA_ARGS__)
#define LOGE(...) printf(__VA_ARGS__)

#endif
#endif


#define SCREEN_W 800
#define SCREEN_H 640

#define SAFE_DEL(p) if (p) delete p; p = 0;
#define SAFE_DEL_ARRAY(p) if (p) delete []p; p = 0;
//#include stl at here
#include <vector>
#include <cstring>
#include <string>
#include <sstream>
#include <fstream>

#include "TGA.h"
