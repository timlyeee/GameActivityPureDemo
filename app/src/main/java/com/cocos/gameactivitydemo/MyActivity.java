package com.cocos.gameactivitydemo;
import android.os.Bundle;

import com.google.androidgamesdk.GameActivity;
public class MyActivity extends GameActivity{
    static {
        System.loadLibrary("c++_shared");

        //Defined in CMakeLists.txt
        System.loadLibrary("game");
    }
    @Override
    protected void onCreate(Bundle savedInstanceState) {

        super.onCreate(savedInstanceState);
    }
}
