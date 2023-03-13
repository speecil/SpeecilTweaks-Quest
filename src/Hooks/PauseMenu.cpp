#include "Hooks.hpp"
#include "GlobalNamespace/PauseMenuManager.hpp"
#include "GlobalNamespace/LevelBar.hpp"
#include "MainConfig.hpp"
#include "main.hpp"
#include "GlobalNamespace/PlayerData.hpp"
#include "HMUI/ImageView.hpp"
#include "UnityEngine/GameObject.hpp"
#include "UnityEngine/Resources.hpp"
#include "UnityEngine/Object.hpp"
#include "UnityEngine/Component.hpp"
using namespace GlobalNamespace;
using namespace UnityEngine;
using namespace HMUI;
MAKE_AUTO_HOOK_MATCH(PauseMenu, &PauseMenuManager::ShowMenu, void, PauseMenuManager *self)
{
  PauseMenu(self);
  if (getMainConfig().EnablePMenuTweaks.GetValue())
  {
    self->levelBar->authorNameText->get_gameObject()->SetActive(false);
    self->levelBar->difficultyText->get_gameObject()->SetActive(false);
    self->levelBar->songNameText->set_fontSizeMax(1000);
    self->levelBar->songNameText->set_fontSize(500);
    self->levelBar->songNameText->set_color(getMainConfig().PMenuColour.GetValue());
    GameObject *icon = GameObject().Find("Wrapper/StandardGameplay/PauseMenu/Wrapper/MenuWrapper/Canvas/MainBar/LevelBarSimple/BeatmapDataContainer/Icon");
    icon->SetActive(false);
    GameObject *bg = GameObject().Find("Wrapper/StandardGameplay/PauseMenu/Wrapper/MenuWrapper/Canvas/MainBar/LevelBarSimple/BG");
    bg->get_gameObject()->GetComponentInChildren<HMUI::ImageView*>()->set_color(getMainConfig().PMenuTextColour.GetValue());
  }
}