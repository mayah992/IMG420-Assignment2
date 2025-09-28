// include headers
#include "register_types.h"

#include "banana_peel.h"

// core Godot C++ headers needed to interact with the GDExtension API.
#include <gdextension_interface.h>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>

// so you don't have to preface everything w/ godot
using namespace godot;


// called respectively when Godot loads our plugin and when it unloads it
void initialize_example_module(ModuleInitializationLevel p_level) 
{
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) 
    {
		return;
	}

    // registers class with Godot at runtime
	GDREGISTER_RUNTIME_CLASS(BananaPeel);
}

// called when Godot unloads your plugin
void uninitialize_example_module(ModuleInitializationLevel p_level) 
{
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) 
    {
		return;
	}
    // include logic for clean-up if needed
}

// disables C++ name mangling so Godot can find the function
extern "C" 
{
    // Initialization. Godot calls this function when loading the extension.
    GDExtensionBool GDE_EXPORT example_library_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, const GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization) {
        godot::GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);

        init_obj.register_initializer(initialize_example_module);
        init_obj.register_terminator(uninitialize_example_module);
        init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

        return init_obj.init();
}
}