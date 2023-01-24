#pragma once

#include "bsml/shared/Helpers/creation.hpp"
#include "bsml/shared/BSML.hpp"
#include "HMUI/FlowCoordinator.hpp"
#include "HMUI/ViewController_AnimationDirection.hpp"
#include "HMUI/ViewController_AnimationType.hpp"
#include "FlowCoordinators/SpeecilTweaksFlowCoordinator.hpp"

#include "questui/shared/BeatSaberUI.hpp"
using namespace QuestUI;

namespace SpeecilTweaks::UI
{
    class Manager
    {
        HMUI::FlowCoordinator *parentFlow;
        SafePtrUnity<SpeecilTweaks::UI::FlowCoordinators::SpeecilTweaksFlowCoordinator> flow;
        BSML::MenuButton *menuButton;

        public:
            Manager(Manager const&) = delete;
            Manager() = default;

            void Init();

            void ShowFlow(bool immediately);

    };

    inline static Manager manager;
}   