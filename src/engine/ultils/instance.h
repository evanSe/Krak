#pragma once
#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <functional>
#include <memory>
#include "vulkan\vulkan.hpp"
#include "noncpy.h"

#ifdef NDEBUG
const bool enableValidationLayers = false;
#else
const bool enableValidationLayers = true;
#endif

const std::vector<const char*> validationLayers = {
	"VK_LAYER_LUNARG_standard_validation"
};


namespace krakVkGraphics
{

	class Instance;
	using InstanceRef = std::shared_ptr<Instance>;

	class Instance : public Noncopyable
	{
	public: 

		VkInstance instance;

		Instance();
		//~Instance();

		void CreateInstance();
		std::vector<const char*> getRequiredExtensions();

		bool checkValidationLayerSupport();
	};

} 
