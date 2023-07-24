#include "main.hpp"
#include "modloader/shared/modloader.hpp"
#include "beatsaber-hook/shared/utils/hooking.hpp"
#include "beatsaber-hook/shared/utils/il2cpp-utils.hpp"

static ModInfo modInfo; 

Configuration& getConfig() {
    static Configuration config(modInfo);
    config.Load();
    return config;
}


Logger& getLogger() {
    static Logger* logger = new Logger(modInfo);
    return *logger;
}


extern "C" void setup(ModInfo& info) {
    info.id = info.id;
    info.version = VERSION;
    modInfo = info;
	
    getConfig().Load();
    getLogger().info("Completed setup!");
}

extern "C" void load() {
    il2cpp_functions::Init();
    getLogger().info("Installing hooks...");

    getLogger().info("Installing The Main Hook...");
    getLogger().info("Installed all hooks!");
}


