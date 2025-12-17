#pragma once

#include <EGL/egl.h>
#include <GLES3/gl3.h>
#include <dlfcn.h>
#include <vector>

#include "imgui.h"
#include "imgui_impl_android.h"
#include "imgui_impl_opengl3.h"
#include "AXL_MODS_HOOK/Tools.hpp"

#include <AXL_MODS_HOOK/Hook.h>
#include "imgui/Font.h"



inline static bool g_IsSetup = false;
inline int prevWidth, prevHeight;


int (*o_inject_event)(JNIEnv *env, jobject thiz, jobject inputEvent);
int hook_input(JNIEnv *env, jobject __this, jobject input_event) {
    ImGuiIO &io = ImGui::GetIO();
    
    jclass motionEventClass = env->FindClass(OBFUSCATE("android/view/MotionEvent"));
    
    if (env->IsInstanceOf(input_event, motionEventClass)) {
        jmethodID getActionMethod = env->GetMethodID(motionEventClass, OBFUSCATE("getAction"), OBFUSCATE("()I"));
        jint getAction = env->CallIntMethod(input_event, getActionMethod);
        
        jmethodID getXMethod = env->GetMethodID(motionEventClass, OBFUSCATE("getX"), OBFUSCATE("()F"));
        jfloat getX = env->CallFloatMethod(input_event, getXMethod);
        
        jmethodID getYMethod = env->GetMethodID(motionEventClass, OBFUSCATE("getY"), OBFUSCATE("()F"));
        jfloat getY = env->CallFloatMethod(input_event, getYMethod);
        
        jmethodID getPointerCountMethod = env->GetMethodID(motionEventClass, OBFUSCATE("getPointerCount"), OBFUSCATE("()I"));
        jint getPointerCount = env->CallIntMethod(input_event, getPointerCountMethod);
        
        switch(getAction) {
            
        case 0:
            io.MouseDown[0] = true;
            break;
        case 1:
            io.MouseDown[0] = false;
            break;
        case 2:
            if (getPointerCount > 1) {
                io.MouseDown[0] = false;
            } else {
                io.MouseWheel = 0;
            }
            break;
        }
        io.MousePos = ImVec2(getX, getY);
    }
    
    jclass KeyEventClass = env->FindClass(OBFUSCATE("android/view/KeyEvent"));
    if (env->IsInstanceOf(input_event, KeyEventClass)) {
        jmethodID getActionMethod = env->GetMethodID(KeyEventClass, OBFUSCATE("getAction"), OBFUSCATE("()I"));
        if (env->CallIntMethod(input_event, getActionMethod) == 0) {
            jmethodID getKeyCodeMethod = env->GetMethodID(KeyEventClass, OBFUSCATE("getKeyCode"), OBFUSCATE("()I"));
            jmethodID getUnicodeCharMethod = env->GetMethodID(KeyEventClass, OBFUSCATE("getUnicodeChar"), OBFUSCATE("(I)I"));
            jmethodID getMetaStateMethod = env->GetMethodID(KeyEventClass, OBFUSCATE("getMetaState"), OBFUSCATE("()I"));
            
            jint keyCode = env->CallIntMethod(input_event, getKeyCodeMethod);
            switch (keyCode)
            {
                case 19:
                    io.KeysDown[io.KeyMap[ImGuiKey_UpArrow]] = true;
                    break;
                case 20:
                    io.KeysDown[io.KeyMap[ImGuiKey_DownArrow]] = true;
                    break;
                case 21:
                    io.KeysDown[io.KeyMap[ImGuiKey_LeftArrow]] = true;
                    break;
                case 22:
                    io.KeysDown[io.KeyMap[ImGuiKey_RightArrow]] = true;
                    break;
                case 66:
                    io.KeysDown[io.KeyMap[ImGuiKey_Enter]] = true;
                    break;
                case 67:
                    io.KeysDown[io.KeyMap[ImGuiKey_Backspace]] = true;;
                    break;
                case 111:
                    io.KeysDown[io.KeyMap[ImGuiKey_Escape]] = true;
                    break;
                case 112:
                    io.KeysDown[io.KeyMap[ImGuiKey_Delete]] = true;
                    break;
                case 122:
                    io.KeysDown[io.KeyMap[ImGuiKey_Home]] = true;
                    break;
                case 123:
                    io.KeysDown[io.KeyMap[ImGuiKey_End]] = true;
                    break;
                default:
                    io.AddInputCharacter(env->CallIntMethod(input_event, getUnicodeCharMethod, env->CallIntMethod(input_event, getMetaStateMethod)));
                    break;
            }
        }
    }
    return o_inject_event(env, __this, input_event);
}

void *(*orig_Input)(void *, void *, const void *);
void *Input(void *inst, void *motionEvent, const void *inputMessage) {
    void *result = orig_Input(inst, motionEvent, inputMessage);
    ImGui_ImplAndroid_HandleInputEvent((AInputEvent*) inst);
    return result;
}


int32_t (*orig_ANativeWindow_getWidth)(ANativeWindow* window);
int32_t _ANativeWindow_getWidth(ANativeWindow* window) {
	prevWidth = orig_ANativeWindow_getWidth(window);
	return orig_ANativeWindow_getWidth(window);
}

int32_t (*orig_ANativeWindow_getHeight)(ANativeWindow* window);
int32_t _ANativeWindow_getHeight(ANativeWindow* window) {
	prevHeight = orig_ANativeWindow_getHeight(window);
	return orig_ANativeWindow_getHeight(window);
}


//float density = -1;

int32_t (*orig_AConfiguration_getDensity)(ANativeWindow* config);
int32_t _AConfiguration_getDensity(ANativeWindow* config) {
    density = orig_AConfiguration_getDensity(config);
    return orig_AConfiguration_getDensity(config);
}

ImFont *font;


/*
void SetupImgui() {
    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.DisplaySize = ImVec2((float)g_GlWidth, (float)g_GlHeight);
    
    ImGui_ImplOpenGL3_Init("#version 300 es");
    
    // We load the default font with increased size to improve readability on many devices with "high" DPI.
    io.Fonts->AddFontFromMemoryTTF(const_cast<std::uint8_t*>(Custom), sizeof(Custom), 32.f, NULL, io.Fonts->GetGlyphRangesVietnamese());
	/*
	io.KeyMap[ImGuiKey_UpArrow] = 19;
    io.KeyMap[ImGuiKey_DownArrow] = 20;
    io.KeyMap[ImGuiKey_LeftArrow] = 21;
    io.KeyMap[ImGuiKey_RightArrow] = 22;
    io.KeyMap[ImGuiKey_Enter] = 66;
    io.KeyMap[ImGuiKey_Backspace] = 67;
    io.KeyMap[ImGuiKey_Escape] = 111;
    io.KeyMap[ImGuiKey_Delete] = 112;
    io.KeyMap[ImGuiKey_Home] = 122;
    io.KeyMap[ImGuiKey_End] = 123;

    // Arbitrary scale-up
    ImGui::GetStyle().ScaleAllSizes(3.0f);
}
*/

struct UnityEngine_Vector2_Fields {
    float x;
    float y;
};

struct UnityEngine_Vector2_o {
    UnityEngine_Vector2_Fields fields;
};

enum TouchPhase {
    Began = 0,
    Moved = 1,
    Stationary = 2,
    Ended = 3,
    Canceled = 4
};

struct UnityEngine_Touch_Fields {
    int32_t m_FingerId;
    struct UnityEngine_Vector2_o m_Position;
    struct UnityEngine_Vector2_o m_RawPosition;
    struct UnityEngine_Vector2_o m_PositionDelta;
    float m_TimeDelta;
    int32_t m_TapCount;
    int32_t m_Phase;
    int32_t m_Type;
    float m_Pressure;
    float m_maximumPossiblePressure;
    float m_Radius;
    float m_RadiusVariance;
    float m_AltitudeAngle;
    float m_AzimuthAngle;
};


