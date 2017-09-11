#pragma once

#include "ChoiceGroup.hpp"

namespace morda{
class Tabs :
		virtual public Widget,
		private ChoiceGroup
{
public:
	Tabs(const stob::Node* chain);
	
	Tabs(const Tabs&) = delete;
	Tabs& operator=(const Tabs&) = delete;
	
	
};
}