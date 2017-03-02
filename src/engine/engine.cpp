#include "pch.h"
#include "engine.h"
#include <chrono>

using namespace std::chrono_literals;

// we use a fixed timestep of 1 / (60 fps) = 16 milliseconds
constexpr std::chrono::nanoseconds timestep(16ms);

struct game_state {
	// this contains the state of your game, such as positions and velocities
};

bool handle_events() {
	// poll for events
	glfwPollEvents();

	return false; // true if the user wants to quit the game
}

void update(game_state *) {
	// update game logic here
}

void render(game_state const &) {
	// render stuff here
}

game_state interpolate(game_state const & current, game_state const & previous, float alpha) {
	game_state interpolated_state;

	// interpolate between previous and current by alpha here

	return interpolated_state;
}

int main() {
	GLFWwindow* window;
	glfwInit();
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	window = glfwCreateWindow(800, 600, "Krakow", nullptr, nullptr);

	using clock = std::chrono::high_resolution_clock;

	std::chrono::nanoseconds lag(0ns);
	auto time_start = clock::now();
	bool quit_game = false;

	game_state current_state;
	game_state previous_state;

	while (!quit_game)
	{
		auto delta_time = clock::now() - time_start;
		time_start = clock::now();
		lag += std::chrono::duration_cast<std::chrono::nanoseconds>(delta_time);

		quit_game = handle_events();

		// update game logic as lag permits
		while (lag >= timestep) {
			lag -= timestep;

			previous_state = current_state;
			update(&current_state); // update at a fixed rate each time
		}

		// calculate how close or far we are from the next timestep
		auto alpha = (float)lag.count() / timestep.count();
		auto interpolated_state = interpolate(current_state, previous_state, alpha);

		render(interpolated_state);

		// if window wants to close, exit game
		if (glfwWindowShouldClose(window))
		{
			quit_game = true;
		}
	}
	glfwDestroyWindow(window);

	glfwTerminate();
}