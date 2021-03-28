#pragma once

#include <CryEntitySystem/IEntityComponent.h>

class C$safeitemname$ final : public IEntityComponent
{
public:
	C$safeitemname$() = default;
	~C$safeitemname$() = default;

	static void ReflectType(Schematyc::CTypeDesc<C$safeitemname$>& desc)
	{
		desc.SetGUID("{$guid1$}"_cry_guid);
	}

	virtual void Initialize() override;
	virtual void ProcessEvent(const SEntityEvent& event) override;
	virtual Cry::Entity::EventFlags GetEventMask() const override;
};