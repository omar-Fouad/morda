/* The MIT License:

Copyright (c) 2012-2014 Ivan Gagis

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE. */

// Home page: http://morda.googlecode.com

/**
 * @author Ivan Gagis <igagis@gmail.com>
 */


#pragma once


#include "../widgets/Widget.hpp"
#include "../resources/ResFont.hpp"
#include "GravitatingWidget.hpp"
#include "PaddedWidget.hpp"



namespace morda{



class Label : public GravitatingWidget, public PaddedWidget{
	std::string text;
	
	ting::Ref<morda::ResFont> font;
	
	morda::Rect2f bb;//text bounding box
	
	morda::Vec2f pivot;
	
protected:
	Label(const stob::Node& description);
	
	Label();
	
public:
	
	~Label()throw(){}
	
	void SetText(const std::string& text);
	
	const std::string& GetText()const throw(){
		return this->text;
	}
	
	void Render(const morda::Matr4f& matrix)const OVERRIDE;
	
	Vec2f ComputeMinDim()const throw() OVERRIDE;
	
	void OnResize() OVERRIDE;
	
	static ting::Ref<Label> New(const stob::Node& description){
		return ting::Ref<Label>(new Label(description));
	}
	
	static ting::Ref<Label> New(){
		return ting::Ref<Label>(new Label());
	}
};



}//~namespace
