/* The MIT License:

Copyright (c) 2008-2012 Ivan Gagis <igagis@gmail.com>

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

//This macro definition is part of a workaround to prevent IDE complain about recursive includes.
#define M_VECTOR2_HPP_INCLUDED

#ifdef DEBUG
#	include <iostream>
#endif

#include <ting/debug.hpp>
#include <ting/types.hpp>
#include <ting/math.hpp>



namespace morda{



//forward declarations
template <class T> class Vector3;



/**
 * @brief Two-dimensional vector class.
 */
template <class T> class Vector2{
	STATIC_ASSERT(sizeof(Vector2) == sizeof(T) * 2)
public:
	/**
	 * @brief 0th vector component.
	 */
	T x;

	/**
	 * @brief 1th vector component.
	 */
	T y;

	/**
	 * @brief default constructor.
	 * It does not initialize vector components.
	 * Their values are undefined right after construction.
	 */
	inline Vector2()throw(){}

	/**
	 * @brief Create vector with given values.
	 * Creates a vector with all components initialized to a given value.
	 * @param xy - value to assign to all components of the vector.
	 */
	inline Vector2(T xy)throw() :
			x(xy), y(xy)
	{}
	
	/**
	 * @brief Create vector with given values.
	 * @param x - x component of the vector.
	 * @param y - y component of the vector.
	 */
	inline Vector2(T x, T y)throw() :
			x(x), y(y)
	{}

	//NOTE: copy constructor will be generated by compiler

	/**
	 * @brief Create Vector2 from Vector3
	 * Creates a 2 dimensional vector and initializes its x and y components
	 * from x and y of given 3 dimensional vector.
	 * @param vec - 3 dimensional vector to copy x and y from.
	 */
	inline Vector2(const Vector3<T>& vec)throw();

	/**
	 * @brief Access vector components.
	 * @param i - index of the component, can be 0 or 1.
	 */
	inline T& operator[](unsigned i)throw(){
		ASSERT(i < 2)
		ASSERT( &((&this->x)[0]) == &this->x)
		ASSERT( &((&this->x)[1]) == &this->y)
		return (&this->x)[i];
	}

	/**
	 * @brief Access vector components.
	 * @param i - index of the component, can be 0 or 1.
	 */
	inline const T& operator[](unsigned i)const throw(){
		ASSERT(i < 2)
		ASSERT( &((&this->x)[0]) == &this->x)
		ASSERT( &((&this->x)[1]) == &this->y)
		return (&this->x)[i];
	}

	//NOTE: operator=() will be generated by compiler.

	/**
	 * @brief Assign value of given Vector3 object.
	 * Note, the z component of given Vector3 is ignored.
	 * @param vec - reference to the Vector3 object to assign value from.
	 * @return reference to this Vector2 object.
	 */
	inline Vector2& operator=(const Vector3<T>& vec)throw();

	/**
	 * @brief Add Vector2 and Vector3.
	 * Note, the z component of given Vector3 is ignored.
	 * @param vec - reference to the Vector3 object to add.
	 * @return instance of the resulting Vector2.
	 */
	inline Vector2 operator+(const Vector3<T>& vec)const throw();

	/**
	 * @brief Add and assign.
	 * Adds given Vector2 and this Vector2 and assigns the result to this Vector2.
	 * @param vec - reference to the Vector2 object to add.
	 * @return reference to this Vector2 object.
	 */
	inline Vector2& operator+=(const Vector2& vec)throw(){
		this->x += vec.x;
		this->y += vec.y;
		return (*this);
	}

	/**
	 * @brief Add two Vector2 vectors.
	 * @param vec - reference to the Vector2 object to add.
	 * @return instance of the resulting Vector2.
	 */
	inline Vector2 operator+(const Vector2& vec)const throw(){
		return (Vector2(*this) += vec);
	}


	/**
	 * @brief Subtract vector and assign.
	 * Subtracts given vector from this one and assigns result back to this vector.
     * @param vec - vector to subtract from this one.
     * @return Reference to this vector object.
     */
	inline Vector2& operator-=(const Vector2& vec)throw(){
		this->x -= vec.x;
		this->y -= vec.y;
		return (*this);
	}

	/**
	 * @brief Subtract vector.
     * @param vec - vector to subtract from this one.
     * @return Vector resulting from subtraction of given vector from this vector.
     */
	inline Vector2 operator-(const Vector2& vec)const throw(){
		return (Vector2(*this) -= vec);
	}

	/**
	 * @brief Subtract vector.
	 * Subtracts 3d vector from this 2d vector. 3rd component of subtracted vector is ignored, i.e.
	 * (this.x, this.y) - (x, y, z) = (this.x - x, this.y -y).
     * @param vec - vector to subtract from this one.
     * @return Resulting two-dimensional vector.
     */
	inline Vector2 operator-(const Vector3<T>& vec)const throw();
	
	/**
	 * @brief Unary minus.
	 * @return Vector resulting from negating this vector.
	 */
	inline Vector2 operator-()const throw(){
		return Vector2(-this->x, -this->y);
	}

	/**
	 * @brief Multiply by scalar and assign.
	 * Multiplies this vector by scalar and assigns the result back to this vector.
     * @param num - scalar to multiply by.
     * @return Reference to this vector object.
     */
	inline Vector2& operator*=(T num)throw(){
		this->x *= num;
		this->y *= num;
		return (*this);
	}

	/**
	 * @brief Multiply by scalar.
	 * @param num - scalar to multiply by.
	 * @return Vector resulting from multiplication of this vector by given scalar.
	 */
	inline Vector2 operator*(T num)const throw(){
		return (Vector2(*this) *= num);
	}

	/**
	 * @brief Multiply scalar by vector.
     * @param num - scalar to multiply.
     * @param vec - vector to multiply by.
     * @return Vector resulting from multiplication of given scalar by given vector.
     */
	inline friend Vector2 operator*(T num, const Vector2& vec)throw(){
		return vec * num;
	}

	/**
	 * @brief Divide by scalar and assign.
	 * Divides this vector by scalar and assigns the result back to this vector.
     * @param num - scalar to divide by.
     * @return Reference to this vector object.
     */
	inline Vector2& operator/=(T num)throw(){
		ASSERT(num != 0)
		this->x /= num;
		this->y /= num;
		return (*this);
	}

	/**
	 * @brief Divide by scalar.
	 * @param num - scalar to divide this vector by.
	 * @return Vector resulting from dividing this vector by given scalar.
	 */
	inline Vector2 operator/(T num)const throw(){
		ASSERT(num != 0)
		return (Vector2(*this) /= num);
	}

	/**
	 * @brief Dot product.
	 * Dot product of this vector and a given vector.
	 * @return Dot product of two vectors (x1 * x2 + y1 * y2).
	 */
	inline T operator*(const Vector2& vec)const throw(){
		return (this->x * vec.x + this->y * vec.y);
	}

	/**
	 * @brief Check if this vector equals to the given vector.
	 * @param vec - vector to compare to.
	 * @return true if corresponding components of both vectors are equal.
	 * @return false otherwise.
	 */
	inline bool operator==(const Vector2& vec)const throw(){
		return this->x == vec.x && this->y == vec.y;
	}

	/**
	 * @brief Check if this vector is not equal to the given vector.
	 * This is a logical NOT of result from operator==().
	 * @param vec - vector to compare to.
	 * @return true if any of corresponding components of two vectors are not equal.
	 * @return false otherwise.
	 */
	inline bool operator!=(const Vector2& vec)const throw(){
		return !this->operator==(vec);
	}

	/**
	 * @brief Component-wise multiplication.
	 * Performs component-wise multiplication of two vectors.
	 * The result of such operation is also vector.
     * @param vec - vector to multiply by.
     * @return Vector resulting from component-wise multiplication.
     */
	inline Vector2 CompMul(const Vector2& vec)const throw(){
		return Vector2(
				this->x * vec.x,
				this->y * vec.y
			);
	}

	/**
	 * @brief Check if both vector components are zero.
	 * @return true if both vector components are zero.
	 * @return false otherwise.
	 */
	inline bool IsZero()const throw(){
		return this->x == 0 && this->y == 0;
	}

	/**
	 * @brief Check if both vector components are positive or zero.
	 * @return true if both vector components are positive or zero.
	 * @return false otherwise.
	 */
	inline bool IsPositiveOrZero()const throw(){
		return this->x >= 0 && this->y >= 0;
	}

	/**
	 * @brief Negate this vector.
     * @return Reference to this vector object.
     */
	inline Vector2& Negate()throw(){
		//NOTE: this should be faster than (*this) = -(*this);
		this->x = -this->x;
		this->y = -this->y;
		return (*this);
	}

	/**
	 * @brief Calculate power 2 of vector magnitude.
	 * @return Power 2 of this vector magnitude.
	 */
	inline T MagPow2()throw(){
		return ting::math::Pow2(this->x) + ting::math::Pow2(this->y);
	}

	/**
	 * @brief Calculate magnitude of the vector.
	 * @return magnitude of this vector.
	 */
	inline T Magnitude()throw(){
		return T(ting::math::Sqrt(this->MagPow2()));
	}

	/**
	 * @brief Normalize this vector.
	 * If the magnitude of vector is 0 then the result is undefined.
	 * @return Reference to this vector object.
	 */
	inline Vector2& Normalize()throw(){
		ASSERT(this->Magnitude() != 0)
		return (*this) /= this->Magnitude();
	}

	/**
	 * @brief Set both vector components to 0 values.
	 */
	inline Vector2& SetToZero()throw(){
		this->x = 0;
		this->y = 0;
		return (*this);
	}

	/**
	 * @brief Rotate vector.
	 * Rotate this vector around (0, 0, 1) axis. Direction of the rotation is
	 * determined by right-hand rule.
     * @param angle - angle of rotation in radians.
     * @return Reference to this vector object.
     */
	Vector2& Rotate(T angle)throw(){
		T cosa = ting::math::Cos(angle);
		T sina = ting::math::Sin(angle);
		T tmp = this->x * cosa - this->y * sina;
		this->y = this->y * cosa + this->x * sina;
		this->x = tmp;
		return (*this);
	}

	/**
	 * @brief Rotation of vector.
	 * Calculate vector resulting from rotation this vector around (0, 0, 1) axis.
	 * Direction of the rotation is determined by right-hand rule.
	 * @param angle - angle of rotation in radians.
	 * @return Vector resulting from rotation of this vector.
	 */
	inline Vector2 Rotation(T angle)const throw(){
		return Vector2(*this).Rotate(angle);
	}


	
#ifdef DEBUG  
	friend std::ostream& operator<<(std::ostream& s, const Vector2<T>& vec){
		s << "(" << vec.x << ", " << vec.y << ")";
		return s;
	}
#endif
};//~class Vector2



}//~namespace



#ifndef M_VECTOR3_HPP_INCLUDED
#	include "Vector3.hpp"
#endif



namespace morda{

//=================================
// inline functions implementation
//=================================

template <class T> inline Vector2<T>::Vector2(const Vector3<T>& vec)throw(){
	this->operator=(vec);
}



template <class T> inline Vector2<T>& Vector2<T>::operator=(const Vector3<T>& vec)throw(){
	this->x = vec.x;
	this->y = vec.y;
	return (*this);
}



template <class T> inline Vector2<T> Vector2<T>::operator+(const Vector3<T>& vec)const throw(){
	return Vector2<T>(
				this->x + vec.x,
				this->y + vec.y
			);
}



template <class T> inline Vector2<T> Vector2<T>::operator-(const Vector3<T>& vec)const throw(){
	return Vector2<T>(
				this->x - vec.x,
				this->y - vec.y
			);
}



//=====================
// Convenient typedefs
//=====================

typedef Vector2<int> Vec2i;
STATIC_ASSERT(sizeof(Vec2i) == sizeof(int) * 2)
typedef Vector2<unsigned> Vec2ui;
STATIC_ASSERT(sizeof(Vec2ui) == sizeof(unsigned) * 2)
typedef Vector2<float> Vec2f;
STATIC_ASSERT(sizeof(Vec2f) == sizeof(float) * 2)
typedef Vector2<double> Vec2d;
STATIC_ASSERT(sizeof(Vec2d) == sizeof(double) * 2)



}//~namespace
