#include "sai_meta.h"

// METADATA for SAI_OBJECT_TYPE_VLAN

DEFINE_ENUM_VALUES(sai_vlan_tagging_mode_t)
{
    SAI_VLAN_PORT_UNTAGGED,
    SAI_VLAN_PORT_TAGGED,
    SAI_VLAN_PORT_PRIORITY_TAGGED
};

const sai_attr_metadata_t sai_vlan_attr_metadata[] = {

    {
        .objecttype             = SAI_OBJECT_TYPE_VLAN,
        .attrid                 = SAI_VLAN_ATTR_MEMBER_LIST,
        .serializationtype      = SAI_SERIALIZATION_TYPE_OBJECT_LIST,
        .flags                  = SAI_ATTR_FLAGS_READ_ONLY,
        .allowedobjecttypes     = { SAI_OBJECT_TYPE_VLAN_MEMBER },
        .allownullobjectid      = false,
        .defaultvaluetype       = SAI_DEFAULT_VALUE_TYPE_NONE,
        .defaultvalue           = { },
        .enumtypestr            = NULL,
        .enumallowedvalues      = { },
        .conditions             = { },
    },

    {
        .objecttype             = SAI_OBJECT_TYPE_VLAN,
        .attrid                 = SAI_VLAN_ATTR_MAX_LEARNED_ADDRESSES,
        .serializationtype      = SAI_SERIALIZATION_TYPE_UINT32,
        .flags                  = SAI_ATTR_FLAGS_CREATE_AND_SET,
        .allowedobjecttypes     = { },
        .allownullobjectid      = false,
        .defaultvaluetype       = SAI_DEFAULT_VALUE_TYPE_CONST,
        .defaultvalue           = { .u32 = 0 },
        .enumtypestr            = NULL,
        .enumallowedvalues      = { },
        .conditions             = { },
    },

    {
        .objecttype             = SAI_OBJECT_TYPE_VLAN,
        .attrid                 = SAI_VLAN_ATTR_STP_INSTANCE,
        .serializationtype      = SAI_SERIALIZATION_TYPE_OBJECT_ID,
        .flags                  = SAI_ATTR_FLAGS_CREATE_AND_SET,
        .allowedobjecttypes     = { SAI_OBJECT_TYPE_STP_INSTANCE },
        .allownullobjectid      = false,
        .defaultvaluetype       = SAI_DEFAULT_VALUE_TYPE_CONST,
        .defaultvalue           = { .oid = SAI_NULL_OBJECT_ID },
        .enumtypestr            = NULL,
        .enumallowedvalues      = { },
        .conditions             = { },

        // TODO default to default STP
    },

    {
        .objecttype             = SAI_OBJECT_TYPE_VLAN,
        .attrid                 = SAI_VLAN_ATTR_LEARN_DISABLE,
        .serializationtype      = SAI_SERIALIZATION_TYPE_BOOL,
        .flags                  = SAI_ATTR_FLAGS_CREATE_AND_SET,
        .allowedobjecttypes     = { },
        .allownullobjectid      = false,
        .defaultvaluetype       = SAI_DEFAULT_VALUE_TYPE_CONST,
        .defaultvalue           = { .booldata = false },
        .enumtypestr            = NULL,
        .enumallowedvalues      = { },
        .conditions             = { },
    },

    {
        .objecttype             = SAI_OBJECT_TYPE_VLAN,
        .attrid                 = SAI_VLAN_ATTR_META_DATA,
        .serializationtype      = SAI_SERIALIZATION_TYPE_UINT32,
        .flags                  = SAI_ATTR_FLAGS_CREATE_AND_SET,
        .allowedobjecttypes     = { },
        .allownullobjectid      = false,
        .defaultvaluetype       = SAI_DEFAULT_VALUE_TYPE_ATTR_RANGE,
        .defaultvalue           = { },
        .enumtypestr            = NULL,
        .enumallowedvalues      = { },
        .conditions             = { },

        // TODO default value inside SAI_SWITCH_ATTR_VLAN_USER_META_DATA_RANGE
    },
};

const size_t sai_vlan_attr_metadata_count = sizeof(sai_vlan_attr_metadata)/sizeof(sai_attr_metadata_t);

// METADATA for SAI_OBJECT_TYPE_VLAN_MEMBER

const sai_attr_metadata_t sai_vlan_member_attr_metadata[] = {

    {
        .objecttype             = SAI_OBJECT_TYPE_VLAN_MEMBER,
        .attrid                 = SAI_VLAN_MEMBER_ATTR_VLAN_ID,
        .serializationtype      = SAI_SERIALIZATION_TYPE_UINT16,
        .flags                  = SAI_ATTR_FLAGS_MANDATORY_ON_CREATE | SAI_ATTR_FLAGS_CREATE_ONLY,
        .allowedobjecttypes     = { },
        .allownullobjectid      = false,
        .defaultvaluetype       = SAI_DEFAULT_VALUE_TYPE_NONE,
        .defaultvalue           = { },
        .enumtypestr            = NULL,
        .enumallowedvalues      = { },
        .conditions             = { },
    },

    {
        .objecttype             = SAI_OBJECT_TYPE_VLAN_MEMBER,
        .attrid                 = SAI_VLAN_MEMBER_ATTR_PORT_ID,
        .serializationtype      = SAI_SERIALIZATION_TYPE_OBJECT_ID,
        .flags                  = SAI_ATTR_FLAGS_MANDATORY_ON_CREATE | SAI_ATTR_FLAGS_CREATE_ONLY,
        .allowedobjecttypes     = { SAI_OBJECT_TYPE_PORT },
        .allownullobjectid      = false,
        .defaultvaluetype       = SAI_DEFAULT_VALUE_TYPE_NONE,
        .defaultvalue           = { },
        .enumtypestr            = NULL,
        .enumallowedvalues      = { },
        .conditions             = { },
    },

    {
        .objecttype             = SAI_OBJECT_TYPE_VLAN_MEMBER,
        .attrid                 = SAI_VLAN_MEMBER_ATTR_TAGGING_MODE,
        .serializationtype      = SAI_SERIALIZATION_TYPE_INT32,
        .flags                  = SAI_ATTR_FLAGS_CREATE_AND_SET,
        .allowedobjecttypes     = { },
        .allownullobjectid      = false,
        .defaultvaluetype       = SAI_DEFAULT_VALUE_TYPE_CONST,
        .defaultvalue           = { .s32 = SAI_VLAN_PORT_UNTAGGED },
        .enumtypestr            = StringifyEnum ( sai_vlan_tagging_mode_t ),
        .enumallowedvalues      = ENUM_VALUES ( sai_vlan_tagging_mode_t ),
        .conditions             = { },
    },
};

const size_t sai_vlan_member_attr_metadata_count = sizeof(sai_vlan_member_attr_metadata)/sizeof(sai_attr_metadata_t);
