#include "Hooks.hpp"
#include "MainConfig.hpp"
#include "main.hpp"
#include "ViewControllers/SpeecilTweaksViewController.hpp"

#include "GlobalNamespace/NoteCutParticlesEffect.hpp"
#include "GlobalNamespace/BombExplosionEffect.hpp"
#include "GlobalNamespace/SaberClashEffect.hpp"

#include "UnityEngine/SceneManagement/SceneManager.hpp"
#include "UnityEngine/ParticleSystem.hpp"
#include "UnityEngine/Resources.hpp"
#include "GlobalNamespace/NoteDebris.hpp"
#include <unordered_set>
#include "modloader/shared/modloader.hpp"
#include "beatsaber-hook/shared/utils/utils.h"
#include "beatsaber-hook/shared/utils/logging.hpp"
#include "beatsaber-hook/shared/utils/hooking.hpp"
#include "beatsaber-hook/shared/utils/il2cpp-utils.hpp"
#include "beatsaber-hook/shared/utils/il2cpp-functions.hpp"
#include "beatsaber-hook/shared/config/config-utils.hpp"

#include "questui/shared/QuestUI.hpp"
#include "custom-types/shared/register.hpp"

#include "UnityEngine/Quaternion.hpp"
#include "UnityEngine/Vector3.hpp"
#include "UnityEngine/Rigidbody.hpp"
#include "UnityEngine/Renderer.hpp"
#include "UnityEngine/Material.hpp"
#include "UnityEngine/MaterialPropertyBlock.hpp"
#include "UnityEngine/MeshRenderer.hpp"
#include "UnityEngine/Color.hpp"

#include "GlobalNamespace/ColorType.hpp"
#include "GlobalNamespace/NoteDebris.hpp"
#include "GlobalNamespace/ConditionalMaterialSwitcher.hpp"
#include "GlobalNamespace/MaterialPropertyBlockController.hpp"
#include "GlobalNamespace/PlayerData.hpp"
#include "GlobalNamespace/PlayerDataModel.hpp"
#include "GlobalNamespace/PlayerDataModelHelper.hpp"
#include "GlobalNamespace/PlayerSpecificSettings.hpp"
#include "GlobalNamespace/NoteDebrisSpawner.hpp"
#include "GlobalNamespace/ObstacleSaberSparkleEffectManager.hpp"

using namespace GlobalNamespace;
using namespace UnityEngine;
using namespace SpeecilTweaks::UI::ViewControllers;

MAKE_AUTO_HOOK_MATCH(NoteDebrisHook, &NoteDebrisSpawner::SpawnDebris, void, NoteDebrisSpawner *self,
                     GlobalNamespace::NoteData::GameplayType noteGameplayType, UnityEngine::Vector3 cutPoint,
                     UnityEngine::Vector3 cutNormal, float saberSpeed, UnityEngine::Vector3 saberDir,
                     UnityEngine::Vector3 notePos, UnityEngine::Quaternion noteRotation, UnityEngine::Vector3 noteScale,
                     GlobalNamespace::ColorType colorType, float timeToNextColorNote, UnityEngine::Vector3 moveVec)
{
    if (getMainConfig().DisableAllDebris.GetValue())
        return;
    NoteDebrisHook(self, noteGameplayType, cutPoint, cutNormal, saberSpeed, saberDir, notePos, noteRotation, noteScale,
                   colorType, timeToNextColorNote, moveVec);
}

MAKE_AUTO_HOOK_MATCH(SceneManager_SetActiveScene, &UnityEngine::SceneManagement::SceneManager::SetActiveScene, bool, UnityEngine::SceneManagement::Scene newActiveScene)
{
    bool result = SceneManager_SetActiveScene(newActiveScene);

    std::string sceneName = newActiveScene.get_name();

    if (sceneName == "MainMenu" && getMainConfig().DisableAllDebris.GetValue() || (sceneName == "GameCore" && getMainConfig().DisableAllDebris.GetValue()))
    {
        for (auto particle : UnityEngine::Resources::FindObjectsOfTypeAll<UnityEngine::ParticleSystem *>())
        {
            if (particle->get_name() == "DustPS")
            {
                particle->get_gameObject()->SetActive(false);
            }
        }
    }
    return result;
}

MAKE_AUTO_HOOK_MATCH(SaberClashEffect_Start, &SaberClashEffect::Start, void, SaberClashEffect *self)
{
    if (getMainConfig().DisableAllDebris.GetValue())
    {
        self->sparkleParticleSystem->get_gameObject()->SetActive(false);
        self->glowParticleSystem->get_gameObject()->SetActive(false);
    }
    SaberClashEffect_Start(self);
}

MAKE_AUTO_HOOK_MATCH(NoteCutParticlesEffect_SpawnParticles, &NoteCutParticlesEffect::SpawnParticles, void, NoteCutParticlesEffect *self, UnityEngine::Vector3 cutPoint, UnityEngine::Vector3 cutNormal, UnityEngine::Vector3 saberDir, float saberSpeed, UnityEngine::Vector3 noteMovementVec, UnityEngine::Color32 color, int sparkleParticlesCount, int explosionParticlesCount, float lifetimeMultiplier)
{
    if (getMainConfig().DisableAllDebris.GetValue())
    {
        sparkleParticlesCount = 0;
        explosionParticlesCount = 0;
    }
    NoteCutParticlesEffect_SpawnParticles(self, cutPoint, cutNormal, saberDir, saberSpeed, noteMovementVec, color, sparkleParticlesCount, explosionParticlesCount, lifetimeMultiplier);
}

MAKE_AUTO_HOOK_MATCH(BombExplosionEffect_SpawnExplosion, &BombExplosionEffect::SpawnExplosion, void, BombExplosionEffect *self, UnityEngine::Vector3 pos)
{
    if (getMainConfig().DisableAllDebris.GetValue())
    {
        self->debrisCount = 0;
        self->explosionParticlesCount = 0;
    }
    BombExplosionEffect_SpawnExplosion(self, pos);
}