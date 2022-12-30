#include "FlowCoordinators/SpeecilTweaksFlowCoordinator.hpp"
using namespace SpeecilTweaks::UI::FlowCoordinators;
using namespace SpeecilTweaks::UI::ViewControllers;
#include "ViewControllers/SpeecilTweaksViewController.hpp"
#include "HMUI/ViewController_AnimationDirection.hpp"
#include "HMUI/ViewController_AnimationType.hpp"
#include "MainConfig.hpp"
#include "bsml/shared/BSML.hpp"
#include "assets.hpp"
#include "GlobalNamespace/MenuTransitionsHelper.hpp"
#include "questui/shared/BeatSaberUI.hpp"
#include "questui/shared/QuestUI.hpp"
using namespace QuestUI;
using namespace UnityEngine;
using namespace GlobalNamespace;
SpeecilTweaksUI *test;

DEFINE_TYPE(SpeecilTweaks::UI::FlowCoordinators, SpeecilTweaksFlowCoordinator);

void SpeecilTweaksFlowCoordinator::DidActivate(bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling)
{
    SetTitle("Speecil Tweaks", HMUI::ViewController::AnimationType::In);
    showBackButton = true;

    SpeecilTweaksViewController = QuestUI::BeatSaberUI::CreateViewController<ViewControllers::SpeecilTweaksUI *>();

    ProvideInitialViewControllers(SpeecilTweaksViewController, nullptr, nullptr, nullptr, nullptr);
}

void SpeecilTweaksFlowCoordinator::BackButtonWasPressed(HMUI::ViewController *topViewController)
{
    this->parentFlowCoordinator->DismissFlowCoordinator(this, HMUI::ViewController::AnimationDirection::Horizontal, nullptr, false);
    if (test->SoftRestart())
    {
        Resources::FindObjectsOfTypeAll<MenuTransitionsHelper *>()[0]->RestartGame(nullptr);
    }
}