#include "GlobalNamespace/MainMenuViewController.hpp"
#include "MainConfig.hpp"
#include "Hooks.hpp"
#include "main.hpp"
#include "GlobalNamespace/DefaultScenesTransitionsFromInit.hpp"
#include "GlobalNamespace/SettingsFlowCoordinator.hpp"
using namespace UnityEngine;
using namespace GlobalNamespace;
using namespace TMPro;
MAKE_AUTO_HOOK_MATCH(MainMenuUIHook, &MainMenuViewController::DidActivate, void, GlobalNamespace::MainMenuViewController *self, bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling)
{
    getMainConfig().inMulti.SetValue(false);
    getLogger().info("User left Multiplayer");
    MainMenuUIHook(self, firstActivation, addedToHierarchy, screenSystemEnabling);
    UnityEngine::UI::Button *soloMenuButton = self->soloButton;
    UnityEngine::GameObject *gameObject = soloMenuButton->get_gameObject();
    HMUI::CurvedTextMeshPro *soloMenuText = gameObject->GetComponentInChildren<HMUI::CurvedTextMeshPro *>();
    //
    UnityEngine::UI::Button *onlineMenuButton = self->multiplayerButton;
    UnityEngine::GameObject *gameObject1 = onlineMenuButton->get_gameObject();
    HMUI::CurvedTextMeshPro *onlineMenuText = gameObject1->GetComponentInChildren<HMUI::CurvedTextMeshPro *>();
    //
    UnityEngine::UI::Button *campaignMenuButton = self->campaignButton;
    UnityEngine::GameObject *gameObject2 = campaignMenuButton->get_gameObject();
    HMUI::CurvedTextMeshPro *campaignMenuText = gameObject2->GetComponentInChildren<HMUI::CurvedTextMeshPro *>();
    //
    UnityEngine::UI::Button *partyMenuButton = self->partyButton;
    UnityEngine::GameObject *gameObject3 = partyMenuButton->get_gameObject();
    HMUI::CurvedTextMeshPro *partyMenuText = gameObject3->GetComponentInChildren<HMUI::CurvedTextMeshPro *>();
    //
    //
    soloMenuText->set_color(getMainConfig().MenuButtonColour.GetValue());
    onlineMenuText->set_color(getMainConfig().MenuButtonColour.GetValue());
    campaignMenuText->set_color(getMainConfig().MenuButtonColour.GetValue());
    partyMenuText->set_color(getMainConfig().MenuButtonColour.GetValue());
}

MAKE_AUTO_HOOK_MATCH(SafetySkip, &DefaultScenesTransitionsFromInit::TransitionToNextScene, void,
                     DefaultScenesTransitionsFromInit *self, bool goStraightToMenu, bool goStraightToEditor, bool goToRecordingToolScene)
{
    SafetySkip(self, getMainConfig().safetySkip.GetValue(), goStraightToEditor, goToRecordingToolScene);
}

MAKE_AUTO_HOOK_MATCH(fuckyou, &SettingsFlowCoordinator::CancelSettings, void, SettingsFlowCoordinator *self){
    if(getMainConfig().DontResetSettings.GetValue()){
        self->ApplySettings();      
    }
    else{
        fuckyou(self);
    }
}