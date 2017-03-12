#pragma once
#include <vector>
class engine
{

public:
	void initWindow();
	void initVulkan();
	void engineLoop();
	void createInstance();
	bool checkValidationLayerSupport();
	std::vector<const char*> getRequiredExtensions();

private:
	VkInstance* instance;
	GLFWwindow* window;
};