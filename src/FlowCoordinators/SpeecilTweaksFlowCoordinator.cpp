#include "FlowCoordinators/SpeecilTweaksFlowCoordinator.hpp"
using namespace SpeecilTweaks::UI::FlowCoordinators;
using namespace SpeecilTweaks::UI::ViewControllers;
#include "ViewControllers/SpeecilTweaksViewController.hpp"
#include "HMUI/ViewController_AnimationDirection.hpp"
#include "HMUI/ViewController_AnimationType.hpp"
#include "MainConfig.hpp"
#include "bsml/shared/BSML.hpp"
#include "assets.hpp"
#include "main.hpp"
#include "GlobalNamespace/MenuTransitionsHelper.hpp"
#include "questui/shared/BeatSaberUI.hpp"
#include "questui/shared/QuestUI.hpp"
#include "UnityEngine/Application.hpp"
#include "UnityEngine/PointerType.hpp"
#include "UI/UIManager.hpp"
using namespace QuestUI;
using namespace UnityEngine;
using namespace GlobalNamespace;

bool orig;
DEFINE_TYPE(SpeecilTweaks::UI::FlowCoordinators, SpeecilTweaksFlowCoordinator);

void SpeecilTweaksFlowCoordinator::DidActivate(bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling)
{
    orig = getMainConfig().DisableAllDebris.GetValue();
    if (firstActivation)
    {
        SetTitle("Speecil Tweaks", HMUI::ViewController::AnimationType::In);
        showBackButton = true;

        SpeecilTweaksViewController = QuestUI::BeatSaberUI::CreateViewController<ViewControllers::SpeecilTweaksUI *>();

        ProvideInitialViewControllers(SpeecilTweaksViewController, nullptr, nullptr, nullptr, nullptr);
    }
}

void SpeecilTweaksFlowCoordinator::BackButtonWasPressed(HMUI::ViewController *topViewController)
{
    if (orig != getMainConfig().DisableAllDebris.GetValue())
    {
        getLogger().info("LMFAOO cfing debirs not the same");
        UnityEngine::Resources::UnloadUnusedAssets();
        UnityEngine::Resources::FindObjectsOfTypeAll<GlobalNamespace::MenuTransitionsHelper *>().FirstOrDefault()->RestartGame(nullptr);
    }
    else
    {
        this->parentFlowCoordinator->DismissFlowCoordinator(this, HMUI::ViewController::AnimationDirection::Horizontal, nullptr, false);
    }
}