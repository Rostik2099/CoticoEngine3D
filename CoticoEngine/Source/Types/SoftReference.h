#pragma once
#include<memory>
#include<string>

class CObject;
class ImGUILayer;
template<typename T>
class Ref
{
public:
	Ref() {};

	Ref(T* object) 
	{
		std::shared_ptr<T> pointer;
		if(dynamic_cast<CObject*>(object)) pointer = std::dynamic_pointer_cast<T>(World::Get()->GetObjectWithID(object->GetUUID()));
		this->ptr = pointer;
	};
	Ref(std::weak_ptr<T> pointer)
	{
		this->ptr = pointer;
	};
	Ref(std::shared_ptr<T> pointer)
	{
		this->ptr = pointer;
	};

	T* operator->() const
	{
		auto lockedPtr = this->ptr.lock();
		return lockedPtr ? lockedPtr.get() : nullptr;
	};

	operator bool() const
	{
		return !ptr.expired();
	};

	std::weak_ptr<T> Get() { return this->ptr; };

	T* GetRaw() 
	{
		auto lockedPtr = this->ptr.lock();
		return lockedPtr ? lockedPtr.get() : nullptr;
	};

private:
	std::weak_ptr<T> ptr;
};
