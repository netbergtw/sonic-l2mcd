/*
 * Copyright 2019 Broadcom.  The term “Broadcom” refers to Broadcom Inc. and/or
 * its subsidiaries.

 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef __L2MCD_MLD_UTILS__
#define __L2MCD_MLD_UTILS__

#include <netinet/in.h>
#include "l2mcd.h"
#include "l2mcd_data_struct.h"
#include "l2mcd_mcast_co.h"

#define MLD_OK 0
#define MLD_ERROR (-1)
#define MLD_VLAN 0x1
#define MLD_BD 0x3
#define MLD_ROUTE_PORT 0x4
#define MLD_IP_IPV4_AFI 1
#define MLD_IP_IPV6_AFI 2
#define MLD_DEFAULT_VRF_ID    L2MCD_DEFAULT_VRF_IDX
#define MCAST_AFI_MAX L2MCD_AFI_MAX
#define MLD_MAX_VLANS	(8192*2)
#define MLD_CALLOC	calloc
#define MLD_FREE(_param_)  {free(_param_); _param_ = NULL;}
#define MLD_IVID_GVID_MAP_NOT_FOUND -1
#define IGMP_MAX_VLAN_SUPPORT_REACHED 4094
#define MLD_MAX_VLAN_SUPPORT_REACHED 4094
#define MLD_FAIL -1
#define MLD_MAX_VLAN_REACHED -2
#define MLD_VLAN_SNOOP_DISABLED -3
#define MLD_VLAN_FWD_REF -4
#define MLD_SNOOP_DISABLED -5
#define PIMS_ERR_SNOOP_DISABLED -6
#define MLD_PROTO_MROUTER 1
#define MLD_PIM_MROUTER  2

/* Used by PIM Snooping */
#define PIMS_WG_MBR_PORT			(1 << 0)  	//0x01   
#define PIMS_SG_MBR_PORT			(1 << 1)	//0x02   
#define MLD_OR_IGMP_JOIN_PORT       (1 << 2)
#define IGMP_V1_MBR_PORT 			(1 << 3)
#define IGMP_V2_MBR_PORT			(1 << 4)
#define IGMP_V3_MBR_PORT            (1 << 5)
#define IGMP_LEAVE_PENDING_MBR_PORT (1 << 6)

/*MLD Module-wide Error Codes*/
#define	MLD_SUCCESS								(0)
#define	MLD_CLI_ERR_NO_SUCH_IFF					(-6)
#define	MLD_CLI_ERR_QI_LE_QRI					(-17)
#define	MLD_CLI_ERR_QRI_GT_QI					(-18)
#define	MLD_CLI_ERR_ILL_ADD						(-39)
#define	MLD_CLI_ERR_L2_CONFIG_PRESENT			(-43)
#define IGMP_CLI_ERR_MAX_LIMIT_REACHED          (-54)



#define MLD_CONVERT_IPV4MCADDR_TO_MAC(IPV4MCA, MAC)				\
  ((u_int8_t *) (MAC)) [0] = 0x01;                                    \
  ((u_int8_t *) (MAC)) [1] = 0x00;                                    \
  ((u_int8_t *) (MAC)) [2] = 0x5e;							           \
  ((u_int8_t *) (MAC)) [3] = (((u_int8_t *) (IPV4MCA)) [1] & 0x7F);   \
  ((u_int8_t *) (MAC)) [4] = ((u_int8_t *) (IPV4MCA)) [2];            \
  ((u_int8_t *) (MAC)) [5] = ((u_int8_t *) (IPV4MCA)) [3];            \

/* Macro to Convert IPv6 Multicast Addr into MAC Addr */
#define MLD_CONVERT_IPV6MCADDR_TO_MAC(IPV6MCA, MAC)                  \
do {                                                                  \
  ((u_int8_t *) (MAC)) [0] = 0x33;                                    \
  ((u_int8_t *) (MAC)) [1] = 0x33;                                    \
  ((u_int8_t *) (MAC)) [2] = ((u_int8_t *) (IPV6MCA)) [12];           \
  ((u_int8_t *) (MAC)) [3] = ((u_int8_t *) (IPV6MCA)) [13];   		   \
  ((u_int8_t *) (MAC)) [4] = ((u_int8_t *) (IPV6MCA)) [14];            \
  ((u_int8_t *) (MAC)) [5] = ((u_int8_t *) (IPV6MCA)) [15];            \
} while (0)

#define MLD_VLAN_NAME_MAX 16

#define GET_MLD_VLAN_NAME(_comp_if_name, _vid)                  \
        char _vname[MLD_VLAN_NAME_MAX + 1];                     \
        memset(_vname, 0, MLD_VLAN_NAME_MAX + 1);               \
        snprintf(_vname, MLD_VLAN_NAME_MAX, "VLAN%04d", _vid);  \
        strncpy (_comp_if_name, _vname, MLD_VLAN_NAME_MAX);

typedef uint32_t mld_vid_t;

typedef enum mld_if_type_s
{
	MLD_TYPE_NONE,
	MLD_SNOOPING,
	MLD_L3
} mld_if_type_t;

typedef struct mcast_grp_addr_s
{
	union {
		uint32_t ipv4_addr;
		struct in6_addr ipv6_addr;
	}ip;
	uint8_t afi;
} mcast_grp_addr_t;

typedef struct mld_l2_static_group_s
{
    mcast_grp_addr_t  grp_addr;
    char ifname[100];
} mld_l2_static_group_t;
#endif //__L2MCD_MLD_UTILS__
