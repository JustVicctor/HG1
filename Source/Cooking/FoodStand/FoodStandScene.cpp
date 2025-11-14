#include "Cooking/FoodStand/FoodStandScene.h"
#include "Cooking/FoodStand/FoodStandResource.h"
#include "Cooking/Ingredient/IngredientResource.h"
#include "Cooking/IngredientContainer/IngredientContainerScene.h"

#include "godot_cpp/classes/area3d.hpp"
#include "godot_cpp/classes/marker3d.hpp"
#include "godot_cpp/classes/property_tweener.hpp"
#include "godot_cpp/classes/scene_tree.hpp"

void FoodStandScene::_ready()
{
	HG_ERR_FAIL_COND_MSG(m_Resource.is_null(), "Resource is null");
	HG_ERR_FAIL_COND_MSG(m_Area == nullptr, "Area is null");
	HG_ERR_FAIL_COND_MSG(m_Marker == nullptr, "Marker is null");

	// m_Area->set_collision_layer(1 << 0);
	// m_Area->set_collision_mask(1 << 2);
}

void FoodStandScene::_process(double delta)
{
	if (m_IngredientContainer != nullptr)
	{
		if (m_IngredientContainer->IsInteracting())
			m_IngredientContainer = nullptr;
		return;
	}

	if (!m_Area->has_overlapping_bodies())
		return;

	const auto& bodies = m_Area->get_overlapping_bodies();
	const auto& alloweds = m_Resource->GetAllowedIngredientContainers();

	for (const auto& body : bodies)
	{
		const auto container = cast_to<IngredientContainerScene>(body);
		if (!container || container->IsInteracting())
			return;

		const auto& containerResource = container->GetResource();
		for (const auto& allowed : alloweds)
		{
			if (allowed != containerResource)
				continue;

			m_IngredientContainer = container;
			m_IngredientContainer->SetIsEnabled(true);
			m_IngredientContainer->reparent(this);
			m_IngredientContainer->set_linear_velocity({ 0.f, 0.f, 0.f });

			// m_IngredientContainer->m_OnObjectGrabbed = [&]()
			// {
			//     m_IngredientContainer->SetIsEnabled(false);
			//     m_IngredientContainer = nullptr;
			//     m_Tween->kill();
			// };

			m_Tween = create_tween();
			m_Tween->tween_property(container, "transform", m_Marker->get_transform(), 1.f);
			// m_Tween->set_ease(Tween::EASE_IN_OUT);
			// m_Tween->set_trans(Tween::TRANS_CUBIC);
			return;
		}
	}
}

void FoodStandScene::_bind_methods()
{
	HG_BIND_PROPERTY_NODE(FoodStandScene, "Area", Area3D, SetArea, GetArea);
	HG_BIND_PROPERTY_NODE(FoodStandScene, "Marker", Marker3D, SetMarker, GetMarker);
	HG_BIND_PROPERTY_RESOURCE(FoodStandScene, "Resource", FoodStandResource, SetResource, GetResource);
}
