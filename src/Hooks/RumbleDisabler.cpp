// moved to debris disable since hook is more efficient


// #include "Hooks.hpp"
// #include "GlobalNamespace/SliderHapticFeedbackInteractionEffect.hpp"
// #include "GlobalNamespace/NoteCutHapticEffect.hpp"
// #include "GlobalNamespace/NoteCutHapticEffect_Type.hpp"
// #include "GlobalNamespace/SaberTypeExtensions.hpp"
// #include "GlobalNamespace/SaberType.hpp"
// #include "Hooks.hpp"
// #include "MainConfig.hpp"
// #include "GlobalNamespace/HapticFeedbackController.hpp"
// #include "GlobalNamespace/ObstacleSaberSparkleEffectManager.hpp"
// using namespace GlobalNamespace;
// using namespace UnityEngine;
// MAKE_AUTO_HOOK_MATCH(NoteVibration, &NoteCutHapticEffect::HitNote, void, NoteCutHapticEffect *self, SaberType saberType, NoteCutHapticEffect::Type type)
// {
//     if (!getMainConfig().DisableRumble.GetValue())
//     {
//         NoteVibration(self, saberType, type);
//         return;
//     }
// }

// MAKE_AUTO_HOOK_MATCH(ArcsVibration, &SliderHapticFeedbackInteractionEffect::Vibrate, void, SliderHapticFeedbackInteractionEffect *self)
// {
//     if (!getMainConfig().DisableRumble.GetValue())
//     {
//         ArcsVibration(self);
//         return;
//     }
// }

// MAKE_AUTO_HOOK_MATCH(ObstacleVibration, &ObstacleSaberSparkleEffectManager::Update, void,
//                      ObstacleSaberSparkleEffectManager *self)
// {
//     if (getMainConfig().DisableRumble.GetValue())
//     {
//         self->rumblePreset->strength = 0.0f;
//     }

//     ObstacleVibration(self);
// }
