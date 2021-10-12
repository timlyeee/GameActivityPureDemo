#include "game-activity/native_app_glue/android_native_app_glue.c"
#include "NativeEngine.h"

extern "C" {
    void android_main(struct android_app *state);
};
void android_main(struct android_app *app){
    auto *engine = new NativeEngine(app);
    engine->GameLoop();
    delete engine;
}