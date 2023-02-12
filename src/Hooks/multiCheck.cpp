#include "Hooks.hpp"
#include "MainConfig.hpp"
#include "GlobalNamespace/LobbySetupViewController.hpp"
#include "main.hpp"
using namespace GlobalNamespace;
MAKE_AUTO_HOOK_MATCH(multiCheck, &LobbySetupViewController::DidActivate, void, LobbySetupViewController *self, bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling)
{
    multiCheck(self, firstActivation, addedToHierarchy, screenSystemEnabling);
    getMainConfig().inMulti.SetValue(true);
    getLogger().info("User connected to multiplayer");
}