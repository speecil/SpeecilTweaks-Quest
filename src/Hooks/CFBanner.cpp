#include "Hooks.hpp"
#include "main.hpp"
#include "GlobalNamespace/ResultsViewController.hpp"
#include "MainConfig.hpp"

using namespace TMPro;
using namespace GlobalNamespace;
// allows for the results banner and text to be changed
static void setGoodResultUI(UnityEngine::GameObject *clearedBannerGo)
{

  clearedBannerGo->GetComponentsInChildren<TextMeshProUGUI *>()[0]->set_text(il2cpp_utils::newcsstr(getMainConfig().rText.GetValue()));
  clearedBannerGo->GetComponentsInChildren<HMUI::ImageView *>()[0]->set_color(getMainConfig().rBackColour.GetValue());
}
static void setBadResultUI(UnityEngine::GameObject *failedBannerGo)
{

  failedBannerGo->GetComponentsInChildren<TextMeshProUGUI *>()[0]->set_text(il2cpp_utils::newcsstr(getMainConfig().rfText.GetValue()));
  failedBannerGo->GetComponentsInChildren<HMUI::ImageView *>()[0]->set_color(getMainConfig().rfBackColour.GetValue());
}

MAKE_AUTO_HOOK_MATCH(ResultsView, &ResultsViewController::SetDataToUI, void, ResultsViewController *self)
{
  ResultsView(self);

  setGoodResultUI(self->clearedBannerGo);
  setBadResultUI(self->failedBannerGo);
  getLogger().info("Set the result screen colour");
  getLogger().info("Set the result screen text");
}