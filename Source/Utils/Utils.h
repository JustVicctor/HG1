#pragma once

#define HG_BIND_PROPERTY(type, variant, name, setter, getter)																		\
	godot::ClassDB::bind_method(godot::D_METHOD(#setter, name), &type::setter);														\
	godot::ClassDB::bind_method(godot::D_METHOD(#getter), &type::getter);															\
	ADD_PROPERTY(godot::PropertyInfo(variant, name), #setter, #getter)

#define HG_BIND_PROPERTY_ARRAY(type, name, hint, setter, getter)																	\
	godot::ClassDB::bind_method(godot::D_METHOD(#setter, name), &type::setter);														\
	godot::ClassDB::bind_method(godot::D_METHOD(#getter), &type::getter);															\
	ADD_PROPERTY(godot::PropertyInfo(godot::Variant::ARRAY, name, godot::PROPERTY_HINT_TYPE_STRING, #hint), #setter, #getter)

#define HG_BIND_PROPERTY_NODE(type, name, hint, setter, getter)																		\
	godot::ClassDB::bind_method(godot::D_METHOD(#setter, name), &type::setter);														\
	godot::ClassDB::bind_method(godot::D_METHOD(#getter), &type::getter);															\
	ADD_PROPERTY(godot::PropertyInfo(godot::Variant::OBJECT, name, godot::PROPERTY_HINT_NODE_TYPE, #hint), #setter, #getter)

#define HG_BIND_PROPERTY_FLOAT(type, name, setter, getter)																			\
	godot::ClassDB::bind_method(godot::D_METHOD(#setter, name), &type::setter);														\
	godot::ClassDB::bind_method(godot::D_METHOD(#getter), &type::getter);															\
	ADD_PROPERTY(godot::PropertyInfo(godot::Variant::FLOAT, name), #setter, #getter)

#define HG_BIND_PROPERTY_PACKED(type, name, setter, getter)																			\
	godot::ClassDB::bind_method(godot::D_METHOD(#setter, name), &type::setter);														\
	godot::ClassDB::bind_method(godot::D_METHOD(#getter), &type::getter);															\
	ADD_PROPERTY(godot::PropertyInfo(godot::Variant::OBJECT, name, godot::PROPERTY_HINT_RESOURCE_TYPE, "PackedScene"), #setter, #getter)

#define HG_BIND_PROPERTY_RESOURCE(type, name, hint, setter, getter)																	\
	godot::ClassDB::bind_method(godot::D_METHOD(#setter, name), &type::setter);														\
	godot::ClassDB::bind_method(godot::D_METHOD(#getter), &type::getter);															\
	ADD_PROPERTY(godot::PropertyInfo(godot::Variant::OBJECT, name, godot::PROPERTY_HINT_RESOURCE_TYPE, #hint), #setter, #getter)

#define HG_ADD_PROPERTY(Type, Name, Default, GetType, SetType)			\
public:																	\
GetType Get##Name##() const { return m_##Name; }						\
void Set##Name##(SetType newValue) { m_##Name = newValue; }				\
protected:																\
Type m_##Name = Default

#ifdef DEBUG_ENABLED
#define HG_ERR_FAIL_COND_V_MSG(cond, ret, msg) ERR_FAIL_COND_V_MSG(cond, ret, msg)
#define HG_ERR_FAIL_COND_MSG(cond, msg) ERR_FAIL_COND_MSG(cond, msg)
#define HG_WARN_COND_MSG(cond, msg)																				\
	if (unlikely(cond)) {																						\
		::godot::_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "Condition \"" _STR(cond) "\" is true.");	\
	}
#else
#define HG_ERR_FAIL_COND_V_MSG(cond, msg)
#define HG_ERR_FAIL_COND_MSG(cond, msg)
#define HG_WARN_COND_MSG(cond, msg)
#endif
