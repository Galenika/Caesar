#pragma once

#include "World\World.h"
#include "World\Weapons\Weapons.h"
#include "World\Textures\Textures.h"
#include "Utils\Utils.h"
#include "Visuals\Visuals.h"
#include "Visuals\Sounds\Sounds.h"
#include "Visuals\Menu\Menu.h"
#include "Cvars\Cvars.h"
#include "Drawing\Drawing.h"
#include "Misc\Misc.h"
#include "Removals\NoSpread\NoSpread.h"
#include "Removals\NoRecoil\NoRecoil.h"
#include "Removals\NoFlash\NoFlash.h"
#include "Aimbot\Aimbot.h"
#include "Systems\Systems.h"

#define HACK_FILE "Caesar.ini"

class CGlobalsVars
{
public:
    std::string BaseDir;
    char IniPath[MAX_PATH];
    char GamePath[MAX_PATH];

    WNDPROC WndProcBackup;
    HWND hWindow;

    DWORD dwLoadingFinished;

    unsigned int ScreenTimer;
    bool bSnapshot, bScreenshot;

    bool chams;//Render chams
    float chams_render_r;
    float chams_render_g;
    float chams_render_b;
};
extern CGlobalsVars g_pGlobals;
