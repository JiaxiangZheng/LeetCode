/**
 * @file Vec.h
 * @Vector classes.
 *
 * @ jiaxiang.zheng135@gmail.com
 * @ 2011.9.29
 */

#ifndef __JXZ_VEC_H_
#define __JXZ_VEC_H_
#include <cmath>
#include <cassert>
#include <iostream>
#include <algorithm>

template <typename T = double, int DIM = 3>
class Vec
{
	typedef T real_t;
	real_t data[DIM];
public:
	Vec(real_t _arr[DIM]) {memcpy(data, _arr, sizeof(real_t)*DIM);}
	Vec(real_t _x = 0.0, real_t _y = 0.0, real_t _z = 0.0, real_t _w = 0.0)
	{
		if (DIM == 2) {data[0] = _x; data[1] = _y;}
		else if (DIM == 3) {data[0] = _x; data[1] = _y; data[2] = _z;}
		else if (DIM == 4) {data[0] = _x; data[1] = _y; data[2] = _z; data[3] = _w;}
		else {
			std::cerr << "Error DIM: 2 <= DIM <= 4" << std::endl;
			exit(-1);
		}
	}
	Vec(const Vec<T, DIM>& ref) {memcpy(data, ref.data, sizeof(real_t)*DIM);}

	const real_t& operator[] (size_t _index) const
	{
		assert(_index >=0 && _index < DIM);
		return data[_index];
	}
	real_t& operator[] (size_t _index)
	{
		assert(_index >=0 && _index < DIM);
		return data[_index];
	}

	Vec operator+( const Vec<T, DIM>& rhs ) const
	{
		real_t v[4];
		for (int i=0; i<DIM; ++i)
		{
			v[i] = this->data[i] + rhs.data[i];
		}
		return Vec(v);
	}
	Vec& operator += (const Vec<T, DIM>& rhs)
	{
		for (int i=0; i<DIM; ++i)
			this->data[i] += rhs[i];
		return *this;
	}
	Vec operator-( const Vec<T, DIM>& rhs ) const
	{
		real_t v[4];
		for (int i=0; i<DIM; ++i)
		{
			v[i] = this->data[i] - rhs.data[i];
		}
		return Vec(v);
	}
	Vec& operator -= (const Vec<T, DIM>& rhs)
	{
		for (int i=0; i<DIM; ++i)
			this->data[i] -= rhs[i];
		return *this;
	}
	Vec operator*( real_t s ) const
	{
		real_t v[4];
		for (int i=0; i<DIM; ++i)
		{
			v[i] = this->data[i]*s;
		}
		return Vec(v);
	}
	Vec& operator*=( real_t s )
	{
		for (int i=0; i<DIM; ++i)
		{
			this->data[i] *= s;
		}
		return *this;
	}
	Vec operator/( real_t s ) const
	{
		real_t v[4];
		for (int i=0; i<DIM; ++i)
		{
			v[i] = this->data[i]/s;
		}
		return Vec(v);
	}
	Vec& operator/=( real_t s )
	{
		for (int i=0; i<DIM; ++i)
		{
			this->data[i] /= s;
		}
		return *this;
	}
	Vec operator-() const
	{
		real_t v[4];
		for (int i=0; i<DIM; ++i)
		{
			v[i] = -this->data[i];
		}
		return Vec(v);
	}

	real_t square_length() const
	{
		real_t len = 0;
		for (int i=0; i<DIM; ++i)
		{
			len += data[i]*data[i];
		}
		return len;
	}
	real_t length() const
	{
		return sqrt(square_length());
	}
	Vec& normalize()
	{
		real_t len = length();
		*this /= len;
		return *this;
	}
	Vec norm() const
	{
		return (*this)/length();
	}
	Vec cross(const Vec<real_t, DIM>& rhs) const
	{
		if (DIM == 3)
		{
			return Vec(data[1]*rhs[2] -data[2]*rhs[1],
				data[2]*rhs[0]-data[0]*rhs[2], data[0]*rhs[1]-data[1]*rhs[0]);
		}
		else if (DIM == 4)
		{
			return Vec(data[1]*rhs[2] -data[2]*rhs[1], data[2]*rhs[3] -data[3]*rhs[2],
				data[3]*rhs[0]-data[0]*rhs[3], data[0]*rhs[1]-data[1]*rhs[0]);
		}
		else {
			std::cerr << "just implement the low dimension: 3, 4." << std::endl;
			return Vec<T, DIM>();//...
		}
	}
	real_t dot(const Vec<real_t, DIM>& rhs) const
	{
		real_t dot_result = 0.0;
		for (int i=0; i<DIM; ++i)
			dot_result += data[i]*rhs[i];
		return dot_result;
	}
	real_t distance(const Vec<real_t, DIM>& rhs) const
	{
		return (*this - rhs).length();
	}

	friend std::ostream& operator << (std::ostream& os, const Vec<T, DIM>& v)
	{
		os << "(" << v[0] << "," << v[1];
		if (DIM == 2) return os << ")" << std::endl;
		os << "," << v[2];
		if (DIM == 3) return  os << ")" << std::endl;
		os << "," << v[3];
		if (DIM == 4) return  os << ")" << std::endl;
	}
};

typedef Vec<float, 2> Vec2f;
typedef Vec<float, 3> Vec3f;
typedef Vec<float, 4> Vec4f;
typedef Vec<double, 2> Vec2d;
typedef Vec<double, 3> Vec3d;
typedef Vec<double, 4> Vec4d;
#endif
