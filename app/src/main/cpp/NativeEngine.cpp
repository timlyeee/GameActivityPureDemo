//
// Created by Administrator on 2021/10/12.
//

#include "NativeEngine.h"
#include "SceneManager.h"
#include <cassert>

NativeEngine::NativeEngine(android_app *app) : mApp{app} {
}


void NativeEngine::GameLoop() {
    mApp->userData = this;
    while (true) {
        //TODO: game rendering
        int events;
        struct android_poll_source *source;
        while ((ALooper_pollAll(IsAnimating() ? 0 : -1, NULL, &events, (void **) &source)) >= 0) {
            //TODO: process events.
        }
        if(IsAnimating()){
            DoFrame();
        }
    }
}
bool NativeEngine::IsAnimating() {
    return mHasFocus && mIsVisible && mHasWindow;
}
bool NativeEngine::InitDisplay() {
    if (mEGLDisplay != EGL_NO_DISPLAY) {
        return true;
    }
    mEGLDisplay = eglGetDisplay(EGL_DEFAULT_DISPLAY);
    if (EGL_FALSE == eglInitialize(mEGLDisplay, 0, 0)) {
        LOGE("NativeEngine: failed to init display, error %d", eglGetError());
        return false;
    }
    return true;
}

bool NativeEngine::InitSurface() {
    assert(mEGLDisplay != EGL_NO_DISPLAY);
    if (mEGLSurface != EGL_NO_SURFACE) {
        return true;
    }
    EGLint numConfigs;
    const EGLint attribList[] = {
            EGL_RENDERABLE_TYPE, EGL_OPENGL_ES3_BIT,
            EGL_SURFACE_TYPE, EGL_WINDOW_BIT,
            EGL_BLUE_SIZE, 8,
            EGL_GREEN_SIZE, 8,
            EGL_RED_SIZE, 8,
            EGL_DEPTH_SIZE, 16,
            EGL_NONE
    };
    // Pick the first EGLConfig that matches.
    eglChooseConfig(mEGLDisplay, attribList, &mEGLConfig, 1, &numConfigs);
    mEGLSurface = eglCreateWindowSurface(mEGLDisplay, mEGLConfig, mApp->window, NULL);

    if (mEGLSurface == EGL_NO_SURFACE) {
        LOGE("Failed to create EGL surface, EGL error %d", eglGetError());
        return false;
    }
    return true;
}

bool NativeEngine::InitContext() {
    assert(mEGLDisplay != EGL_NO_DISPLAY);
    if (mEGLContext != EGL_NO_CONTEXT) {
        return true;
    }
    EGLint attribList[] = {EGL_CONTEXT_CLIENT_VERSION, 2, EGL_NONE};
    mEGLContext = eglCreateContext(mEGLDisplay, mEGLConfig, NULL, attribList);
    if (mEGLContext == EGL_NO_CONTEXT) {
        LOGE("Failed to create EGL context, EGL error %d", eglGetError());
        return false;
    }
    return true;
}

void NativeEngine::ConfigureOpenGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
}

void NativeEngine::DoFrame() {

    // Query the current surface dimension
    int width, height;
    eglQuerySurface(mEGLDisplay, mEGLSurface, EGL_WIDTH, &width);
    eglQuerySurface(mEGLDisplay, mEGLSurface, EGL_HEIGHT, &height);

    // Handle dimension changes
    SceneManager mgr = SceneManager::GetInstance();
    if (width != mSurfWidth || height != mSurfHeight) {
        mSurfWidth = width;
        mSurfHeight = height;
        mgr.SetScreenSize(mSurfWidth, mSurfHeight);
        glViewport(0, 0, mSurfWidth, mSurfHeight);
    }


    // Render scenes and objects
    mgr.DoFrame();

    // Swap buffers
    if(EGL_FALSE == eglSwapBuffers(mEGLDisplay, mEGLSurface)){
        HandleEglError(eglGetError());
    }

}

void NativeEngine::HandleEglError(EGLint error) {

}

