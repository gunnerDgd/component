#pragma once
#include <string>
#include <type_traits>

#include <typeinfo>
#include <component/exception.hpp>

namespace synapse::component {
	class attribute
	{
		friend class meta_object;
	public:
		using name_type
					= const char*;
		using type_code
					= std::uint64_t;
	public:
		template <typename AttributeType>
		attribute
			(name_type pName, AttributeType pAttr)
				: __M_attr_name
						(pName),
				  __M_attr_ptr
						(&pAttr),
				 __M_attr_typecode
						(typeid(pAttr).hash_code()) {}
	
		template <typename CastType>
		static CastType
			cast_to(attribute& pAttribute)
		{
			if(typeid(pAttribute).hash_code()
					!= __M_attr_typecode)
						throw exception::attribute_type_mismatch {};
			else
				return
					reinterpret_cast<CastType>(__M_attr_ptr);
		}

	private:
		name_type
			__M_attr_name;
		type_code
			__M_attr_typecode;
		void*
			__M_attr_ptr;
	};
}