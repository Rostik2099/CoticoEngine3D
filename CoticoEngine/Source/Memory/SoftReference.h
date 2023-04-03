#pragma once
#include<memory>

template<typename T>
class Ref
{
public:
	Ref() {};
	Ref(std::weak_ptr<T> pointer)
	{
		this->ptr = pointer;
	};
	Ref(std::shared_ptr<T> pointer)
	{
		this->ptr = pointer;
	};

	T* operator->() const { return this->ptr.lock().get(); };
	operator bool() const
	{
		if (ptr.expired()) return true;
		else return false;
	};
private:
	std::weak_ptr<T> ptr;
};