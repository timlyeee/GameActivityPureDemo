//
// Created by Administrator on 2021/10/12.
//

#ifndef GAMEACTIVITYDEMO_SCENEMANAGER_H
#define GAMEACTIVITYDEMO_SCENEMANAGER_H


#include "UiScene.h"

class SceneManager {

public:
    static SceneManager GetInstance();

    void SetScreenSize(int i, int i1);

    void DoFrame();

    void InstallScene(void* install);

private:
    void *mSceneToInstall{nullptr};
    bool mHasGraphics{false};
    UiScene* mCurScene{nullptr};
};


#endif //GAMEACTIVITYDEMO_SCENEMANAGER_H
