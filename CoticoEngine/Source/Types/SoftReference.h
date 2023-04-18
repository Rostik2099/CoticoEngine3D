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
		if (!ptr.expired()) return true;
		else return false;
	};

	std::weak_ptr<T> Get() { return this->ptr; };
	T* GetRaw() { return this->ptr.lock().get(); };
private:
	std::weak_ptr<T> ptr;
};