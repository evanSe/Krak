#pragma once

class Noncopyable
{
protected:

	Noncopyable() = default;
	~Noncopyable() = default;
	Noncopyable(const Noncopyable& other) = delete;
	Noncopyable& operator=(const Noncopyable& other) = delete;
};