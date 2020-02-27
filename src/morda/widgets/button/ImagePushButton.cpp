#include "ImagePushButton.hpp"

using namespace morda;

void ImagePushButton::on_pressed_changed(){
	this->image_button::on_pressed_changed();
	this->PushButton::on_pressed_changed();
}


ImagePushButton::ImagePushButton(std::shared_ptr<morda::context> c, const puu::forest& desc) :
		widget(std::move(c), desc),
		button(this->context, desc),
		PushButton(this->context, desc),
		image_button(this->context, desc)
{}

