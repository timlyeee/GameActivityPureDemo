//
// Created by Administrator on 2021/10/12.
//

#ifndef GAMEACTIVITYDEMO_NATIVEENGINE_H
#define GAMEACTIVITYDEMO_NATIVEENGINE_H

#include "game-activity/native_app_glue/android_native_app_glue.c"
#include <EGL/egl.h>
#include <GLES3/gl3.h>
class NativeEngine {
public:
    NativeEngine() = delete;
    NativeEngine(android_app *app);
    void GameLoop();
private:
    android_app* mApp;
    EGLDisplay mEGLDisplay{EGL_NO_DISPLAY};
    EGLContext mEGLContext{EGL_NO_CONTEXT};
    EGLSurface mEGLSurface{EGL_NO_SURFACE};
    EGLConfig mEGLConfig{0};

    bool mHasFocus{false}, mIsVisible{false}, mHasWindow{false};
    bool mHasGLObjects{true};
    bool mIsFirstFrame{true};
    int mSurfWidth{0}, mSurfHeight{0};

    bool InitDisplay();
    bool InitSurface();
    bool InitContext();
    void ConfigureOpenGL();

    bool IsAnimating();

    void DoFrame();

    void HandleEglError(EGLint error);
};


#endif //GAMEACTIVITYDEMO_NATIVEENGINE_H
