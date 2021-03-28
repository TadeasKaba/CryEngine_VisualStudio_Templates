#include "StdAfx.h"
#include "$safeitemname$.h"

// Registration file headers
#include <CrySchematyc/Env/IEnvRegistrar.h>
#include <CrySchematyc/Env/Elements/EnvComponent.h>
#include <CryCore/StaticInstanceList.h>
// 

namespace
{
	static void Register$safeitemname$Component(Schematyc::IEnvRegistrar& registrar)
	{
		Schematyc::CEnvRegistrationScope scope = registrar.Scope(IEntity::GetEntityScopeGUID());
		{
			Schematyc::CEnvRegistrationScope componentScope = scope.Register(SCHEMATYC_MAKE_ENV_COMPONENT(C$safeitemname$));
		}
	}

	CRY_STATIC_AUTO_REGISTER_FUNCTION(&Register$safeitemname$Component);
}

void C$safeitemname$::Initialize()
{

}

void C$safeitemname$::ProcessEvent(const SEntityEvent& event)
{
	switch (event.event)
	{

	}
}

Cry::Entity::EventFlags C$safeitemname$::GetEventMask() const
{

}
