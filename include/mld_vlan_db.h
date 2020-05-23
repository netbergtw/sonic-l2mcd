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

#ifndef __MLD_VLAN_DB_H__
#define __MLD_VLAN_DB_H__

#include "linklist_api.h"
#include "l2mcd_data_struct.h"
#include "l2mcd_mld_utils.h"
#include "mcast_addr.h"
#include "hash_grow_generic.h"
#include "igmp_struct.h"
#include "l2mcd_mcast_co.h"
#include "l2mcd.h"

/* Port and bitmap defines */
#define MLD_PORT_KEYLEN     (sizeof(ifindex_t) * 8)

typedef struct mld_cfg_param_s
{
    uint16_t            start_up_query_interval;
    uint16_t            start_up_query_count;
    uint16_t            cfg_query_interval_time;//query interval from usr cfg, init to dflt 125
    uint16_t            max_response_time;
    uint16_t            group_membership_time;
    uint16_t            older_host_present_time;
    uint16_t            LMQ_interval;          // last_member_query_interval
    uint8_t             LMQ_count;         // last_member_query_count
    uint8_t             cfg_robustness_var;
	uint8_t             cfg_version;
}mld_cfg_param_t;

typedef struct mld_cfg_s
{
	mld_cfg_param_t *param;
	struct list   *l2_static_group_list;
	struct list   *l3_static_group_list;
	struct list *mrtr_list;
}mld_cfg_t;

typedef struct mld_mrtr_s
{
	char ifname[INTERFACE_NAMSIZ + 1];	
}mld_mrtr_t;

typedef  struct mld_vlan_port_s {
    L2MCD_AVL_NODE node;
    uint32_t ifindex;
    uint8_t  lif_state;
}mld_vlan_port_t;

typedef struct mld_vlan_node_s {
    L2MCD_AVL_NODE node;
    ifindex_t ifindex;      /* For interface L2/L3 subsystems */
	ifindex_t ve_ifindex;	/* Binded VE interface */
    uint32_t gvid;           /* VLAN ID as calculated by MLD */
	uint16_t ivid;
    uint32_t flags[2];
	uint32_t vlan_flags;
	uint32_t    multi_access_ntwrk_flag; /* Member set to 1 only if nbr count on vlan is more than 1 else 0*/
	uint8_t	 type;	/* ve or vlan or ve & vlan both */
	uint8_t	 rcvd_nsm_add;
	uint8_t	 cfg_version; // IGMPv1/v2/v3
	char	name[INTERFACE_NAMSIZ + 1];
	uint8_t	bmap_size;	
	/* These fields are maintaned for forward referencing case */
	mld_cfg_t	*mld_cfg[2];
	uint8_t mld_snp_by_usr[2];  /* mld/igmp snoop cfg by CLI */
	uint8_t pim_snp_by_usr[2]; /* PIMv4/v6 snoop cfg by CLI */
	L2MCD_AVL_TREE port_tree; /* Having ports as tree */
} mld_vlan_node_t;


/* Global structure that will act as the VLAN DB */
typedef struct mld_vlan_db_s {
    L2MCD_AVL_TREE  vdb_tree;
} mld_vlan_db_t;


/* Error value defines */
#define MLD_VLAN_DB_ERR_MAX -20

enum MLD_VLAN_DB_ERR_VALS {
    MLD_VLAN_DB_ENULL_PARAM = MLD_VLAN_DB_ERR_MAX,
    MLD_VLAN_DB_EPTREE_INIT,
    MLD_VLAN_DB_EPRTEE_ADD,
    MLD_VLAN_DB_ENOVLAN,
    MLD_VLAN_DB_ENOMEM,
    MLD_VLAN_DB_EMUTEX_INIT,
    MLD_VLAN_DB_SUCCESS = 0
};

#define MLD_VLAN_KEY_SIZE  5
#define MLD_VLAN_KEY_TYPE_OFFSET 0
#define MLD_VLAN_KEY_ID_OFFSET 1

/* APIs to access/set port bitmaps */
#define MLD_NO_MORE_PORTS      0xFFFFFFFF

#define MLD_INVALID_PARAM -2

#define MLD_VLAN_NSM (1 << 0) 
#define MLD_VLAN_DCM (1 << 1)

#endif /* __MLD_VLAN_DB_H__ */

