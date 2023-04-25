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
		//if(dynamic_cast<ImGUILayer*>(object)) pointer = std::dynamic_pointer_cast<T>(EditorUIManager::GetUIManager()->GetLayerWithID(object->GetUUID()));
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
