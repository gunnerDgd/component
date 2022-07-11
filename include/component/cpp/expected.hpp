#pragma once
#include <string>
#include <component/cpp/meta_object.hpp>

namespace synapse::component {
	template
		<typename ExpectedType>
	class expected
	{
		template
			<typename... Expected>
				friend class contract;
		std::string
			__M_expected_attr;
	public:
		using value_type
					= ExpectedType;
		using name_type
					= std::string;

	public:
		expected(name_type pName)
			: __M_expected_attr
					(std::move(pName)) {}
	};

	template
		<std::size_t Idx, 
				typename... ExpectedType>
	bool
		__check_expected
			(meta_object& pMetaObject, std::tuple<ExpectedType...>& pExpected)
	{
		if constexpr
			(Idx == sizeof...(ExpectedType))
				return true;

		typename
			std::tuple_element_t
				<Idx, std::tuple<ExpectedType...>>::value_type
					var_test;

		try
		{
			var_test
				= pMetaObject
					[std::get<Idx>(pExpected)
							.__M_expected_attr];
		}
		catch
			(exception::attribute_not_found) 
				{ return false; }
		catch
			(exception::attribute_type_mismatch) 
				{ return false; }
		
		return
			__check_expected
				<Idx + 1>(pMetaObject, pExpected);
	}

	template
		<typename... Expected>
	class contract
	{
		std::tuple
			<Expected...> __M_contract_expected;
	public:
		template
			<typename... InExpected>
		contract
			(InExpected&&... pExpect)
				: __M_contract_expected
						(std::forward_as_tuple(pExpect...))
							{ }

	public:
		bool operator()
				(meta_object& pMetaObject)
		{
			return
				__check_expected
					<0>(pMetaObject, __M_contract_expected);
		}
	};

	template
		<typename... Expected>
			contract(Expected&&...)
				-> contract<std::remove_reference_t<Expected>...>; 
}