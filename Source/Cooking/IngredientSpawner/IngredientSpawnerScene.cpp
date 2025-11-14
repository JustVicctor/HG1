#include "IngredientSpawnerScene.h"
#include "IngredientSpawnerResource.h"

#include "Character/Player/PlayerScene.h"
#include "Cooking/Ingredient/IngredientScene.h"

void IngredientSpawnerScene::_ready()
{
	HG_ERR_FAIL_COND_MSG(m_Resource.is_null(), "Resource is null");
	HG_ERR_FAIL_COND_MSG(m_Resource->GetIngredientScene().is_null(), "IngredientScene is null");
	HG_ERR_FAIL_COND_MSG(m_Marker == nullptr, "Marker is null");
}

Interactable* IngredientSpawnerScene::StartInteraction(Node3D* instigator, Marker3D* marker, const Vector3 position)
{
	InteractableStaticBody3D::StartInteraction(instigator, marker, position);
	const PlayerScene* player = cast_to<PlayerScene>(instigator);
	if (!player)
		return nullptr;

	const Ref<PackedScene> ingredientPackedScene = m_Resource->GetIngredientScene();
	IngredientScene* ingredientScene = cast_to<IngredientScene>(ingredientPackedScene->instantiate());
	HG_ERR_FAIL_COND_V_MSG(!ingredientScene, nullptr, "IngredientScene is null");

	add_child(ingredientScene);
	ingredientScene->set_global_position(position);
	return ingredientScene->StartInteraction(instigator, marker, position);
}

void IngredientSpawnerScene::ProcessInteraction(float delta)
{
	InteractableStaticBody3D::ProcessInteraction(delta);
}

void IngredientSpawnerScene::StopInteraction()
{
	InteractableStaticBody3D::StopInteraction();
}

void IngredientSpawnerScene::_bind_methods()
{
	HG_BIND_PROPERTY_RESOURCE(IngredientSpawnerScene, "Resource", IngredientSpawnerResource, SetResource, GetResource);
	HG_BIND_PROPERTY_NODE(IngredientSpawnerScene, "Marker", Marker3D, SetMarker, GetMarker);
}
