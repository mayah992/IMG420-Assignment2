
// include headers
#include "banana_peel.h"

#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/core/class_db.hpp>

// so you don't have to preface everything w/ godot
using namespace godot;

//methods, properties, or signals of your class to expose them to Godot
void BananaPeel::_bind_methods() 
{
	// Bind signal
    ADD_SIGNAL(MethodInfo("player_slipped", PropertyInfo(Variant::FLOAT, "penalty")));

	 // Bind properties
    ClassDB::bind_method(D_METHOD("set_time_penalty", "penalty"), &BananaPeel::set_time_penalty);
    ClassDB::bind_method(D_METHOD("get_time_penalty"), &BananaPeel::get_time_penalty);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "time_penalty"), "set_time_penalty", "get_time_penalty");

    ClassDB::bind_method(D_METHOD("set_is_reusable", "reusable"), &BananaPeel::set_is_reusable);
    ClassDB::bind_method(D_METHOD("get_is_reusable"), &BananaPeel::get_is_reusable);
    ADD_PROPERTY(PropertyInfo(Variant::BOOL, "is_reusable"), "set_is_reusable", "get_is_reusable");

    // Methods
    ClassDB::bind_method(D_METHOD("on_player_collide", "player"), &BananaPeel::on_player_collide);
    ClassDB::bind_method(D_METHOD("_on_area_body_entered", "body"), &BananaPeel::_on_area_body_entered);
    ClassDB::bind_method(D_METHOD("_on_reset_obstacles"), &BananaPeel::_on_reset_obstacles);
}

// runs when a new BananaPeel node is created
BananaPeel::BananaPeel() 
{
	// Initialize any variables here
}

// Called when the object is destroyed.
BananaPeel::~BananaPeel() 
{
	// Add your cleanup here.
}

void BananaPeel::_ready() 
{
    // Connect collision signal from child Area2D node
    Area2D* area = get_node<Area2D>(NodePath("Area2D"));
    if (area) 
    {
        area->connect("body_entered", Callable(this, "on_player_collide"));
    }
}

void BananaPeel::_on_area_body_entered(Object* body) 
{
    Node2D* player = Object::cast_to<Node2D>(body);
    if (player) {
        on_player_collide(player);
    }
}

void BananaPeel::on_player_collide(Node2D* player) 
{
    if (used && !is_reusable) return;

    emit_signal("player_slipped", time_penalty);
    UtilityFunctions::print("Player slipped on banana!");

    used = true;
    if (!is_reusable) 
    {
        hide();
    }
}

void BananaPeel::_on_reset_obstacles() 
{
    used = false;
    show();
}

double BananaPeel::get_time_penalty() const 
{
    return time_penalty;
}

void BananaPeel::set_time_penalty(double p_penalty) 
{
    time_penalty = p_penalty;
}

bool BananaPeel::get_is_reusable() const 
{
    return is_reusable;
}

void BananaPeel::set_is_reusable(bool p_reusable) 
{
    is_reusable = p_reusable;
}