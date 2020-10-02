#include "tablet/sys_init.h"

#include <XPLMUtilities.h>
#include <XPLMPlugin.h>

#include <cstring>
#include <memory>

std::unique_ptr<SysInit> tab_init_main;

PLUGIN_API int XPluginStart(char * outName, char * outSig, char * outDesc)
{
	strcpy(outName, "LevelUpUI");
	strcpy(outSig, "levelup.tablet_interface");
	strcpy(outDesc, "LevelUp Tablet Interface");

	XPLMEnableFeature("XPLM_USE_NATIVE_PATHS", 1);

	tab_init_main = std::make_unique<SysInit> ();
	tab_init_main->init();

	return 1;
}

PLUGIN_API void XPluginStop(void)
{
	tab_init_main->shutdown();
}

PLUGIN_API void XPluginDisable(void)
{

}

PLUGIN_API int XPluginEnable(void)
{
	return 1; 
}

PLUGIN_API void XPluginReceiveMessage(XPLMPluginID inFrom, int inMsg, void * inParam)
{

}
