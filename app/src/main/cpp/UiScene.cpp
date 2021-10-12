//
// Created by Administrator on 2021/10/12.
//

#include "UiScene.h"
#include <GLES3/gl3.h>
void UiScene::DoFrame() {
    // clear screen
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glDisable(GL_DEPTH_TEST);

    RenderBackground();

    // Render the "Please Wait" sign and do nothing else
//    if (mWaitScreen) {
//        SceneManager *mgr = SceneManager::GetInstance();
//        mTextRenderer->SetFontScale(WAIT_SIGN_SCALE);
//        mTextRenderer->SetColor(1.0f, 1.0f, 1.0f);
//        mTextRenderer->RenderText(S_PLEASE_WAIT, mgr->GetScreenAspect() * 0.5f,
//                                  0.5f);
//        glEnable(GL_DEPTH_TEST);
//        return;
//    }
//
//    // Render all the widgets.
//    for (int i = 0; i < mWidgetCount; ++i) {
//        mWidgets[i]->Render(mTrivialShader, mTextRenderer, mShapeRenderer,
//                            (mFocusWidget < 0) ? UiWidget::FOCUS_NOT_APPLICABLE :
//                            (mFocusWidget == i) ? UiWidget::FOCUS_YES : UiWidget::FOCUS_NO,tf);
//    }
    glEnable(GL_DEPTH_TEST);
}

void UiScene::RenderBackground() {

}
