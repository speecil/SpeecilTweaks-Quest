#include "Hooks.hpp"
#include "GlobalNamespace/PracticeViewController.hpp"
#include "GlobalNamespace/StandardLevelDetailView.hpp"
#include "GlobalNamespace/StandardLevelDetailViewController.hpp"
#include "MainConfig.hpp"
#include "main.hpp"

#include "custom-types/shared/register.hpp"

#include "questui/shared/CustomTypes/Components/MainThreadScheduler.hpp"

#include "UnityEngine/GameObject.hpp"
#include "UnityEngine/Transform.hpp"
#include "UnityEngine/RectTransform.hpp"
#include "UnityEngine/Vector2.hpp"
#include "UnityEngine/Vector3.hpp"
#include "UnityEngine/Color.hpp"
using namespace UnityEngine;

#include "UnityEngine/UI/Button.hpp"
using namespace UnityEngine::UI;

#include "HMUI/ImageView.hpp"
using namespace HMUI;

using namespace GlobalNamespace;
// allows for the play button text to be changed
static void setActionButton(UnityEngine::UI::Button *actionButton)
{

  actionButton->get_transform()->GetComponentInChildren<TMPro::TextMeshProUGUI *>()->SetText(il2cpp_utils::newcsstr(getMainConfig().aText.GetValue()));
}
static void setPracticeButton(UnityEngine::UI::Button *practiceButton)
{

  practiceButton->get_transform()->GetComponentInChildren<TMPro::TextMeshProUGUI *>()->SetText(il2cpp_utils::newcsstr(getMainConfig().pText.GetValue()));
}

static void setPracticePlayButton(UnityEngine::UI::Button *practicePlayButton)
{

  practicePlayButton->get_transform()->GetComponentInChildren<TMPro::TextMeshProUGUI *>()->SetText(il2cpp_utils::newcsstr(getMainConfig().aText.GetValue()));
}

// grabs the play button and if the mod is enabled, it then checks if the user wants the play button to exist, then changes the text of the play button to what the user wants
MAKE_AUTO_HOOK_MATCH(LevelUIHook, &StandardLevelDetailView::RefreshContent, void, GlobalNamespace::StandardLevelDetailView *self)
{

  LevelUIHook(self);
  UnityEngine::UI::Button *playMenuButton = self->actionButton;
  UnityEngine::GameObject *play = playMenuButton->get_gameObject();
  UnityEngine::UI::Button *practiceMenuButton = self->practiceButton;
  UnityEngine::GameObject *practice = practiceMenuButton->get_gameObject();
  std::thread([=]()
                {
            std::this_thread::sleep_for(std::chrono::milliseconds(5));
            QuestUI::MainThreadScheduler::Schedule([=](){
              // ensures that the practice text gets set first try
              if (getMainConfig().inMulti.GetValue())
              {
              }
              else if (!getMainConfig().EnablePlayButton.GetValue())
              {
                play->SetActive(false);
                getLogger().info("Disabled the play button");
              }
              else
              {
                play->SetActive(true);
                setActionButton(self->actionButton);
                getLogger().info("Kept the play button enabled");
                getLogger().info("Set Play button text!");
              }
              if (getMainConfig().inMulti.GetValue())
              {
              }
              else if (!getMainConfig().EnablePracticeButton.GetValue())
              {
                practice->SetActive(false);
                getLogger().info("Disabled the practice button");
              }
              else
              {
                practice->SetActive(true);
                setPracticeButton(self->practiceButton);
                getLogger().info("Kept the practice button on");
                
              }
                }); })
        .detach();
  
}

MAKE_AUTO_HOOK_MATCH(PracLevelUIHook, &PracticeViewController::RefreshUI, void, GlobalNamespace::PracticeViewController *self)
{

  PracLevelUIHook(self);
  setPracticePlayButton(self->playButton);
}