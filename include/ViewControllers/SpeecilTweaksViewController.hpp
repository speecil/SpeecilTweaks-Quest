#pragma once

#include "HMUI/ViewController.hpp"
#include "custom-types/shared/macros.hpp"

#include "bsml/shared/macros.hpp"
#include "bsml/shared/BSML/Components/Settings/SliderSetting.hpp"
using namespace BSML;

#include "UnityEngine/Color.hpp"
using namespace UnityEngine;

#define GET_FIND_METHOD(mPtr) il2cpp_utils::il2cpp_type_check::MetadataGetter<mPtr>::get()

DECLARE_CLASS_CODEGEN(SpeecilTweaks::UI::ViewControllers, SpeecilTweaksUI, HMUI::ViewController,
    DECLARE_OVERRIDE_METHOD(void, DidActivate, GET_FIND_METHOD(&HMUI::ViewController::DidActivate), bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling);
    DECLARE_INSTANCE_METHOD(void, Patreon);
    DECLARE_INSTANCE_METHOD(void, Discord);
    
    DECLARE_BSML_PROPERTY(bool, EnablePlayButton);
    DECLARE_BSML_PROPERTY(bool, EnablePracticeButton);
    DECLARE_BSML_PROPERTY(bool, DisableAllDebris);
    DECLARE_BSML_PROPERTY(bool, EnablePMenuTweaks);
    DECLARE_BSML_PROPERTY(bool, safetySkip);
    DECLARE_BSML_PROPERTY(bool, DisableRumble);
    DECLARE_BSML_PROPERTY(bool, DisableHitScore);
    DECLARE_BSML_PROPERTY(bool, DontResetSettings);

    DECLARE_BSML_PROPERTY(StringW, pText);
    DECLARE_BSML_PROPERTY(StringW, aText);
    DECLARE_BSML_PROPERTY(StringW, rText);
    DECLARE_BSML_PROPERTY(StringW, rfText);
    
    DECLARE_BSML_PROPERTY(Color, rBackColour);
    DECLARE_BSML_PROPERTY(Color, rfBackColour);
    DECLARE_BSML_PROPERTY(Color, MenuButtonColour);
    DECLARE_BSML_PROPERTY(Color, PMenuColour);
    DECLARE_BSML_PROPERTY(Color, PMenuTextColour);
)