#pragma once
#include <cstdint>
#include <ecs/cmp/component.hpp>
#include <ecs/util/typealias.hpp>
#include <string_view>
#include <string>

struct Entity_t {
	Entity_t (std::string_view n) {
		nombre = n.data();
	};

	template<typename CMP_t>
	void addComponent(CMP_t& cmp){
		auto type = cmp.getComponentTypeID();
		m_components[type] = &cmp;
	}

	template<typename CMP_t>
	CMP_t* getComponent(){
		auto type = CMP_t::getComponentTypeID();
		auto it = m_components.find(type);
		if( it != m_components.end()){
			return static_cast<CMP_t*>(it->second);
		}
		return nullptr; 
	}

	template<typename CMP_t>
	const CMP_t* getComponent() const {
		auto* cmp = const_cast<Entity_t*>(this)->getComponent<CMP_t>();
		return const_cast<const CMP_t*>(cmp);
	}

	//int32_t w 	{1}, h 	{1}, d 	{1}; //dimensiones
	constexpr EntityID_t getEntityID() const noexcept { return entityID;};
private:
	Hash_t<ComponentTypeID_t,Component_t*> m_components;
	EntityID_t entityID { ++nextID };
	inline static EntityID_t nextID {0};
	std::string nombre;

	 
};