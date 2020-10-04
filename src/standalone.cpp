#include "tablet/sys_init.h"

#include <logging.h>

#include <string>
#include <iostream>

INITIALIZE_EASYLOGGINGPP

std::unique_ptr<SysInit> tab_init_main;

int main()
{
		el::Loggers::reconfigureAllLoggers(el::ConfigurationType::Filename,
				"LU-Tablet-Log.txt");
		el::Loggers::reconfigureAllLoggers(el::ConfigurationType::Format,
				"[LevelUp] %datetime %level [%fbase:%line]: %msg");
		el::Loggers::reconfigureAllLoggers(el::ConfigurationType::MaxLogFileSize, "50000000");

		LOG(INFO) << "Initializing tablet...";

		tab_init_main = std::make_unique<SysInit> ();
		tab_init_main->init();

		if (tab_init_main) {
				tab_init_main->shutdown();
				tab_init_main.reset();
		}

		return 0;
}
