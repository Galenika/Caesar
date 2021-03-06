#include "../../../Required.h"
#include "../../../Config.h"

extern Config config;
CNoRecoil g_NoRecoil;

void CNoRecoil::V_CalcRefdef(struct ref_params_s *pparams)
{
	g_Local.vNoRecoilAngle[0] = pparams->punchangle[0] * 2;
	g_Local.vNoRecoilAngle[1] = pparams->punchangle[1] * 2;
	g_Local.vNoRecoilAngle[2] = 0;

	if (IsCurWeaponGun() && config.norecoil_visual)
	{
		pparams->punchangle[0] = 0;
		pparams->punchangle[1] = 0;
		pparams->punchangle[2] = 0;
	}

	if (IsCurWeaponGun() && config.debug)
	{
		pparams->punchangle[0] -= g_Local.vNoRecoilAngle[0];
		pparams->punchangle[1] -= g_Local.vNoRecoilAngle[1];
		pparams->punchangle[2] -= g_Local.vNoRecoilAngle[2];
	}
}

void CNoRecoil::CL_CreateMove(struct usercmd_s *cmd)
{
	if (config.aimbot.enabled && config.norecoil && IsCurWeaponGun() && cmd->buttons & IN_ATTACK && CanAttack())
	{
		cmd->viewangles -= g_Local.vNoRecoilAngle;
	}
}

void CNoRecoil::DrawRecoil()
{
	if (config.recoil_overlay && g_Local.bAlive && IsCurWeaponGun() && g_Local.iFOV > 0)
	{
		unsigned int x = g_Screen.iWidth * 0.5f;
		unsigned int y = g_Screen.iHeight * 0.5f;

		x -= g_Local.vPunchangle[1] / g_Local.iFOV * g_Screen.iWidth / 1.25f;
		y += g_Local.vPunchangle[0] / g_Local.iFOV * g_Screen.iWidth / 1.25f;

		g_Drawing.DrawRect(x - 1, y - 1, 3, 3, config.recoil_overlay_r, config.recoil_overlay_g, config.recoil_overlay_b, 200);
	}
}