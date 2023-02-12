#include "Hooks.hpp"
#include "MainConfig.hpp"
#include "main.hpp"
#include "GlobalNamespace/SaberTrail.hpp"

#include "UnityEngine/Transform.hpp"

#include "GlobalNamespace/FlyingScoreSpawner.hpp"
#include "GlobalNamespace/FlyingScoreSpawner_InitData.hpp"
#include "GlobalNamespace/FlyingScoreSpawner_SpawnPosition.hpp"


using namespace GlobalNamespace;

MAKE_AUTO_HOOK_MATCH(saber_trail, &SaberTrail::LateUpdate, void, SaberTrail *self)
{
  if (getMainConfig().DisableBlur.GetValue())
  {
    self->whiteSectionMaxDuration = 0.0f;
  }
  saber_trail(self);
}

MAKE_AUTO_HOOK_MATCH(SliceScoreHook, &FlyingScoreSpawner::SpawnFlyingScore, void, FlyingScoreSpawner *self,
                GlobalNamespace::IReadonlyCutScoreBuffer *cutScoreBuffer, UnityEngine::Color color)
{
  if (!getMainConfig().DisableHitScore.GetValue()){
    SliceScoreHook(self, cutScoreBuffer, color);
  }

}