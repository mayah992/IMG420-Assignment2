// include guard
#ifndef BANANA_PEEL_H
#define BANANA_PEEL_H

// include bindings to the Sprite2D class from Godot
#include <godot_cpp/classes/sprite2d.hpp>
#include <godot_cpp/classes/area2d.hpp>
#include <godot_cpp/classes/collision_shape2d.hpp>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/core/class_db.hpp>

// everything in GDExtension is defined with this namespace
namespace godot 
{
	// defines new C++ class that inherits from Sprite2D
	// new class is a Sprite2D but with additional behaviors
	class BananaPeel : public Sprite2D 
	{
		// MACRO that binds class with Godot engine
		// tells engine new class is derived from Sprite2D
		GDCLASS(BananaPeel, Sprite2D)

		// keeps track of time
		private:
			double time_penalty = 2.0;
			bool is_reusable = false;
			bool used = false;

		// finds out which methods can be called and which properties it exposes
		protected:
			static void _bind_methods();

		public:
			// called when an instance of the class is created
			BananaPeel();
			// called when the instance is destroyed.
			~BananaPeel();

			void _ready();
			void on_player_collide(Object* player);
			void _on_area_body_entered(Object* body);
			
			void _on_reset_obstacles(); // Respond to signal
			double get_time_penalty() const;
			void set_time_penalty(double p_penalty);

			bool get_is_reusable() const;
			void set_is_reusable(bool p_reusable);
	};

}

#endif