#pragma once

#include "bsml/shared/Helpers/creation.hpp"
#include "bsml/shared/BSML.hpp"
#include "assets.hpp"
#include "HMUI/FlowCoordinator.hpp"
#include "HMUI/ViewController_AnimationDirection.hpp"
#include "HMUI/ViewController_AnimationType.hpp"
#include "FlowCoordinators/SpeecilTweaksFlowCoordinator.hpp"

#include "questui/shared/BeatSaberUI.hpp"
using namespace QuestUI;
using namespace UnityEngine;
using namespace SpeecilTweaks::UI;
namespace SpeecilTweaks::UI
{
    class UIManager
    {
        HMUI::FlowCoordinator *parentFlow;
        SpeecilTweaks::UI::FlowCoordinators::SpeecilTweaksFlowCoordinator *flow;
        public:
            void Init() 
            {
                BSML::Register::RegisterMenuButton("Speecil Tweaks", "Tweak your game!", [this]()
                {
                    ShowFlow(true);
                });
            }

            void ShowFlow(bool immediately)
            {
                if (flow == nullptr || flow->m_CachedPtr.m_value == nullptr)
                    flow = BSML::Helpers::CreateFlowCoordinator<SpeecilTweaks::UI::FlowCoordinators::SpeecilTweaksFlowCoordinator *>();
                
                parentFlow = QuestUI::BeatSaberUI::GetMainFlowCoordinator()->YoungestChildFlowCoordinatorOrSelf();
                parentFlow->PresentFlowCoordinator(flow, nullptr, HMUI::ViewController::AnimationDirection::Horizontal, HMUI::ViewController::AnimationType::Out, false);
            }
            

            
    };

    inline static UIManager manager;
}