//
// Created by Administrator on 2021/10/12.
//

#include "SceneManager.h"

SceneManager SceneManager::GetInstance() {
    static SceneManager instance;
    return instance;
}

void SceneManager::SetScreenSize(int i, int i1) {

}

void SceneManager::DoFrame() {
    if (mSceneToInstall) {
        InstallScene(mSceneToInstall);
        mSceneToInstall = nullptr;
    }

    if (mHasGraphics && mCurScene) {
        mCurScene->DoFrame();
    }
}

void SceneManager::InstallScene(void* install) {

}
