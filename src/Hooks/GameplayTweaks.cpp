#include "Hooks.hpp"
#include "MainConfig.hpp"
#include "main.hpp"
#include "GlobalNamespace/SaberTrail.hpp"

#include "UnityEngine/Transform.hpp"

#include "GlobalNamespace/FlyingScoreSpawner.hpp"
#include "GlobalNamespace/FlyingScoreSpawner_InitData.hpp"
#include "GlobalNamespace/FlyingScoreSpawner_SpawnPosition.hpp"


using namespace GlobalNamespace;

MAKE_AUTO_HOOK_MATCH(SliceScoreHook, &FlyingScoreSpawner::SpawnFlyingScore, void, FlyingScoreSpawner *self,
                GlobalNamespace::IReadonlyCutScoreBuffer *cutScoreBuffer, UnityEngine::Color color)
{
  if (!getMainConfig().DisableHitScore.GetValue()){
    SliceScoreHook(self, cutScoreBuffer, color);
  }

}