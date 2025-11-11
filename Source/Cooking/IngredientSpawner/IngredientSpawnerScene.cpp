#include "IngredientSpawnerScene.h"
#include "IngredientSpawnerResource.h"

#include "Character/Player/PlayerScene.h"
#include "Cooking/Ingredient/IngredientScene.h"

void IngredientSpawnerScene::StartInteraction(Node3D* instigator, Marker3D* marker)
{
	InteractableStaticBody3D::StartInteraction(instigator, marker);
	PlayerScene* player = cast_to<PlayerScene>(instigator);
	if (!player)
		return;

	const Ref<PackedScene> ingredientPackedScene = m_Resource->GetIngredientScene();
	IngredientScene* ingredientScene = cast_to<IngredientScene>(ingredientPackedScene->instantiate());
	if (!ingredientScene)
		return;

	add_child(ingredientScene);
	ingredientScene->set_transform(m_Marker->get_transform());
}

void IngredientSpawnerScene::ProcessInteraction(float delta)
{
	InteractableStaticBody3D::ProcessInteraction(delta);
}

void IngredientSpawnerScene::StopInteraction()
{
	InteractableStaticBody3D::StopInteraction();
}

void IngredientSpawnerScene::_ready()
{
	HG_ERR_FAIL_COND_MSG(m_Resource.is_null(), "Resource is null");
	HG_ERR_FAIL_COND_MSG(m_Resource->GetIngredientScene().is_null(), "IngredientScene is null");
	HG_ERR_FAIL_COND_MSG(m_Marker == nullptr, "Marker is null");
}

void IngredientSpawnerScene::_bind_methods()
{
	HG_BIND_PROPERTY_RESOURCE(IngredientSpawnerScene, "Resource", IngredientSpawnerResource, SetResource, GetResource);
	HG_BIND_PROPERTY_NODE(IngredientSpawnerScene, "Marker", Marker3D, SetMarker, GetMarker);
}
