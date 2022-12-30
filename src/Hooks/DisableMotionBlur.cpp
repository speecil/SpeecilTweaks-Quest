#include "Hooks.hpp"
#include "MainConfig.hpp"
#include "main.hpp"
#include "GlobalNamespace/SaberTrail.hpp"

#include "UnityEngine/Transform.hpp"

using namespace GlobalNamespace;


MAKE_AUTO_HOOK_MATCH(saber_trail, &SaberTrail::LateUpdate, void, SaberTrail* self) {
  if(getMainConfig().DisableBlur.GetValue()){
    self->whiteSectionMaxDuration = 0.0f;
    saber_trail(self);
  }
}