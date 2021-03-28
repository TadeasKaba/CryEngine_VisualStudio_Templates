#include "StdAfx.h"
#include "EntityFlowNode.h"
#include "$safeitemname$.h"

// Registration file headers
#include <CrySchematyc/Env/IEnvRegistrar.h>
#include <CrySchematyc/Env/Elements/EnvComponent.h>
#include <CryCore/StaticInstanceList.h>
// 

class CNodeRegistration
{
public:
	~CNodeRegistration()
	{
		if (pFlowNodeFactory)
			pFlowNodeFactory->UnregisterFactory();
		pFlowNodeFactory = nullptr;
	}

	void Register()
	{
		pFlowNodeFactory = new CEntityFlowNodeFactory("Your Node Name Here");

		// Add inputs/outputs here; pFlowNodeFactory->m_inputs.push_back(InputPortConfig<bool>("Show"));
		
		pFlowNodeFactory->m_activateCallback = C$safeitemname$::OnFlowGraphActivation;
		pFlowNodeFactory->Close();
	}

protected:
	_smart_ptr<CEntityFlowNodeFactory> pFlowNodeFactory = nullptr;
};

CNodeRegistration nodeRegistrator;

namespace
{
	static void Register$safeitemname$Component(Schematyc::IEnvRegistrar& registrar)
	{
		nodeRegistrator.Register();

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

// FlowNode interface
void C$safeitemname$::OnFlowGraphActivation(EntityId entityId, IFlowNode::SActivationInfo* pActInfo, const CEntityFlowNode* pNode)
{
	//if (IsPortActive(pActInfo, 0))
}

void C$safeitemname$::ActivateFlowNodeOutput(const int portIndex, const TFlowInputData& inputData)
{
	SEntityEvent evnt;
	evnt.event = ENTITY_EVENT_ACTIVATE_FLOW_NODE_OUTPUT;
	evnt.nParam[0] = portIndex;
	evnt.nParam[1] = (INT_PTR)&inputData;
	C$safeitemname$::GetEntity()->SendEvent(evnt);
}
