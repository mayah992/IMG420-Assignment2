// include guard
#ifndef GDEXAMPLE_REGISTER_TYPES_H
#define GDEXAMPLE_REGISTER_TYPES_H

// includes the Godot C++ binding header
// used to register classes, methods, properties, and signals with the engine.
#include <godot_cpp/core/class_db.hpp>

// don't need to preface everything with godot
using namespace godot;

// function declarations
void initialize_example_module(ModuleInitializationLevel p_level);
void uninitialize_example_module(ModuleInitializationLevel p_level);

#endif // GDEXAMPLE_REGISTER_TYPES_H