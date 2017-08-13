/**
 * vim: set ts=4 :
 * =============================================================================
 * Left 4 Downtown SourceMod Extension
 * Copyright (C) 2009 Igor "Downtown1" Smirnov.
 * =============================================================================
 *
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License, version 3.0, as published by the
 * Free Software Foundation.
 * 
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * As a special exception, AlliedModders LLC gives you permission to link the
 * code of this program (as well as its derivative works) to "Half-Life 2," the
 * "Source Engine," the "SourcePawn JIT," and any Game MODs that run on software
 * by the Valve Corporation.  You must obey the GNU General Public License in
 * all respects for all other code used.  Additionally, AlliedModders LLC grants
 * this exception to all derivative works.  AlliedModders LLC defines further
 * exceptions, found in LICENSE.txt (as of this writing, version JULY-31-2007),
 * or <http://www.sourcemod.net/license.php>.
 *
 * Version: $Id$
 */

#include "vglobals.h"
#include "extension.h"
#include "util.h"

void **g_pGameRules = NULL;
void **g_pEngine = NULL;
CDirector **g_pDirector = NULL;
void *g_pZombieManager = NULL;
WeaponDatabase *g_pWeaponInfoDatabase = NULL;
CMeleeWeaponInfoStore *g_pMeleeWeaponInfoStore = NULL;

void InitializeValveGlobals()
{
	char *addr = NULL;

	if(!g_pGameConf->GetAddress("GameRules", (void **)&addr))
	{
		g_pSM->LogError(myself, "Couldn't look up 'GameRules' address");
	}
	else
	{
		g_pGameRules = reinterpret_cast<void **>(addr);
	}


	if(!g_pGameConf->GetAddress("CDirector", (void **)&addr))
	{
		g_pSM->LogError(myself, "Couldn't look up 'CDirector' address");
	}
	else
	{
		g_pDirector = reinterpret_cast<CDirector **>(addr);
	}


	if(!g_pGameConf->GetAddress("WeaponInfoDatabase", (void **)&addr))
	{
		g_pSM->LogError(myself, "Couldn't look up 'WeaponInfoDatabase' address");
	}
	else
	{
		g_pWeaponInfoDatabase = reinterpret_cast<WeaponDatabase *>(addr);
	}


	if(!g_pGameConf->GetAddress("MeleeWeaponInfoStore", (void **)&addr))
	{
		g_pSM->LogError(myself, "Couldn't look up 'MeleeWeaponInfoStore' address");
	}
	else
	{
		g_pMeleeWeaponInfoStore = reinterpret_cast<CMeleeWeaponInfoStore *>(addr);
	}


	if(!g_pGameConf->GetAddress("ZombieManager", (void **)&addr))
	{
		g_pSM->LogError(myself, "Couldn't look up 'ZombieManager' signature");
	}
	else
	{
		g_pZombieManager = addr;
	}
}
