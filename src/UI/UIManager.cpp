#include "UI/UIManager.hpp"

void SpeecilTweaks::UI::Manager::Init()
{
    BSML::Register::RegisterMenuButton("SpeecilTweaks", "Tweak your game!", [this]() {
        ShowFlow(false);
    });
}

void SpeecilTweaks::UI::Manager::ShowFlow(bool immediately)
{
    if (!flow)
        flow = BSML::Helpers::CreateFlowCoordinator<SpeecilTweaks::UI::FlowCoordinators::SpeecilTweaksFlowCoordinator *>();
    parentFlow = QuestUI::BeatSaberUI::GetMainFlowCoordinator()->YoungestChildFlowCoordinatorOrSelf();
    parentFlow->PresentFlowCoordinator(flow.ptr(), nullptr, HMUI::ViewController::AnimationDirection::Horizontal, false, false);
}