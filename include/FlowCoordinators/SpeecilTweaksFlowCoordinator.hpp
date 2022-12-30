#pragma once

#include "HMUI/ViewController.hpp"
#include "HMUI/FlowCoordinator.hpp"
#include "custom-types/shared/macros.hpp"
#include "beatsaber-hook/shared/utils/il2cpp-utils.hpp"

#include "ViewControllers/SpeecilTweaksViewController.hpp"
using namespace SpeecilTweaks::UI;


#define GET_FIND_METHOD(mPtr) il2cpp_utils::il2cpp_type_check::MetadataGetter<mPtr>::get()

DECLARE_CLASS_CODEGEN(SpeecilTweaks::UI::FlowCoordinators, SpeecilTweaksFlowCoordinator, HMUI::FlowCoordinator,
    DECLARE_INSTANCE_FIELD(ViewControllers::SpeecilTweaksUI*, SpeecilTweaksViewController);

    DECLARE_OVERRIDE_METHOD(void, DidActivate, GET_FIND_METHOD(&HMUI::FlowCoordinator::DidActivate), bool firstActivation, bool addedToHeirarchy, bool screenSystemEnabling);
    DECLARE_OVERRIDE_METHOD(void, BackButtonWasPressed, GET_FIND_METHOD(&HMUI::FlowCoordinator::BackButtonWasPressed), HMUI::ViewController* topViewController);
)

//inline SpeecilTweaks::UI::FlowCoordinators::SpeecilTweaksFlowCoordinator *fcInstance;