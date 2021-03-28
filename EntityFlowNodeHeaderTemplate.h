#pragma once

#include <CryEntitySystem/IEntityComponent.h>
#include <CryFlowGraph/IFlowSystem.h>

class C$safeitemname$ final : public IEntityComponent
{
	// Entity Component
public:
	C$safeitemname$() = default;
	~C$safeitemname$() = default;

	static void ReflectType(Schematyc::CTypeDesc<C$safeitemname$>& desc)
	{
		desc.SetGUID("{39e55049-bf65-4f47-9ea9-012f0a27d20e}"_cry_guid);
	}

	virtual void Initialize() override;
	virtual void ProcessEvent(const SEntityEvent& event) override;
	virtual Cry::Entity::EventFlags GetEventMask() const override;

	// Entity flowNode
public:
	enum EFlowGraphInputPorts
	{

	};

	enum EFlowGraphOutputPorts
	{

	};

	static void OnFlowGraphActivation(EntityId entityId, IFlowNode::SActivationInfo* pActInfo, const class CEntityFlowNode* pNode);
	void ActivateFlowNodeOutput(const int portIndex, const TFlowInputData& inputData);
};