#include "tablet/sys_init.h"

#include <XPLMUtilities.h>
#include <XPLMPlugin.h>

#include <cstring>
#include <memory>

#include <logging.h>
#include <Path.h>
#include <Livery_Path.h>

INITIALIZE_EASYLOGGINGPP

std::unique_ptr<SysInit> tab_init_main;

PLUGIN_API int XPluginStart(char * outName, char * outSig, char * outDesc)
{
	strcpy(outName, "LevelUpUI");
	strcpy(outSig, "levelup.tablet_interface");
	strcpy(outDesc, "LevelUp Tablet Interface");

	XPLMEnableFeature("XPLM_USE_NATIVE_PATHS", 1);

	getPath::loadPlanePath();
	getPath::loadSystemPath();
	getLiveryPath::loadLiveryPath();

	el::Loggers::reconfigureAllLoggers(el::ConfigurationType::Filename,
		getPath::UTF8ToNative(getPath::getPlanePath() + "LU-Tablet-Log.txt"));
	el::Loggers::reconfigureAllLoggers(el::ConfigurationType::Format,
		"[LevelUp] %datetime %level [%fbase:%line]: %msg");
	el::Loggers::reconfigureAllLoggers(el::ConfigurationType::MaxLogFileSize, "50000000");

	XPLMDebugString("[LevelUp] Initializing Tablet UI.\n");
	LOG(INFO) << "Initializing tablet...";

	tab_init_main = std::make_unique<SysInit> ();
	tab_init_main->init();

	return 1;
}

PLUGIN_API void XPluginStop(void)
{
	if (tab_init_main) {
		tab_init_main->shutdown();
		tab_init_main.reset();
	}
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
