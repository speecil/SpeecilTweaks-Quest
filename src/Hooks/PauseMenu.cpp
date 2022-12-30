#include "Hooks.hpp"
#include "GlobalNamespace/PauseMenuManager.hpp"
#include "GlobalNamespace/LevelBar.hpp"
#include "MainConfig.hpp"
#include "main.hpp"
using namespace GlobalNamespace;

MAKE_AUTO_HOOK_MATCH(PauseMenu, &PauseMenuManager::ShowMenu, void, PauseMenuManager* self) {
    PauseMenu(self);
    if(getMainConfig().EnablePMenuTweaks.GetValue()){
      self->levelBar->authorNameText->get_gameObject()->SetActive(false);
      self->levelBar->difficultyText->get_gameObject()->SetActive(false);
      self->levelBar->songNameText->set_fontSizeMax(1000);
      self->levelBar->songNameText->set_fontSize(500);
      self->levelBar->songNameText->set_color(getMainConfig().PMenuColour.GetValue());
    }
}