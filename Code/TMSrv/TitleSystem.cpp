#include "TitleSystem.h"

int loadTitle(int conn, std::string tab)
{
	//title level
	for (size_t i = 0; i < tMaxTitle; i++)
	{
		if (!strcmp(TitleLevel[i].Name.c_str(), tab.c_str()))
		{
			unsigned int level = pMob[conn].MOB.CurrentScore.Level + 1;
			unsigned int classMaster = pMob[conn].Extra.ClassMaster;

			if (TitleLevel[i].ClassMaster == CELESTIAL && classMaster == MORTAL)
				return FALSE;

			if (TitleLevel[i].ClassMaster == CELESTIAL && classMaster == ARCH)
				return FALSE;

			if (TitleLevel[i].ClassMaster == ARCH && classMaster == MORTAL)
				return FALSE;

			if (level < TitleLevel[i].Level && classMaster == TitleLevel[i].ClassMaster)
				return FALSE;

			return TRUE;
		}
	}

	return TRUE;
	
}