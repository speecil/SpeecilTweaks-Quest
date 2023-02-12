#pragma once
#include "UnityEngine/Color.hpp"
#include "config-utils/shared/config-utils.hpp"
using namespace UnityEngine;
DECLARE_CONFIG(MainConfig,
    CONFIG_VALUE(rText, std::string, "Pass Results Text", "Well Done!");
    CONFIG_VALUE(rfText, std::string, "Fail Results Text", "You Suck.");
    CONFIG_VALUE(rBackColour, Color, "Pass Colour", Color(0.15, 0.15, 0.7, 1.0));
    CONFIG_VALUE(rfBackColour, Color, "Fail Colour", Color(1.0, 0.0, 0.0, 1.0));
    CONFIG_VALUE(EnablePlayButton, bool, "Enable the Play Button", true);
    CONFIG_VALUE(aText, std::string, "Play Button Text", "Speecil!");
    CONFIG_VALUE(EnablePracticeButton, bool, "Enable the Practice Button", true);
    CONFIG_VALUE(pText, std::string, "Practice Button Text", "Git Gud");
    CONFIG_VALUE(MenuButtonColour, Color, "Menu Button Colour", Color(0, 1.0, 1.0, 1.0));
    CONFIG_VALUE(DisableAllDebris, bool, "Disable All Debris", true);
    CONFIG_VALUE(EnablePMenuTweaks, bool, "Enable Pause Menu Tweaks?", true);
    CONFIG_VALUE(PMenuColour, Color, "Pause Song Name Colour", Color(0.1, 0.3, 1.0, 1.0));
    CONFIG_VALUE(inMulti, bool, "inMulti", false);
    CONFIG_VALUE(DisableBlur, bool, "Disable Motion Blur", false);
    CONFIG_VALUE(safetySkip, bool, "Disable Health and Safety warning", false);
    CONFIG_VALUE(DisableRumble, bool, "Disable All In Game Rumble", false);
    CONFIG_VALUE(DisableHitScore, bool, "Disable Hit Score", false);
    CONFIG_VALUE(DontResetSettings, bool, "Doesnt reset the base game settings on cancel", false);


)