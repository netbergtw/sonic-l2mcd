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

#include "l2mcd_mld_utils.h"
#include "mld_vlan_db.h"

extern void 
l2mcd_sync_pims_upd_inherit_ports_to_sg(MCGRP_ENTRY *mcgrp_entry, 
										MCGRP_MBRSHP *rcvd_mbrshp,
										uint32_t vid, uint32_t phy_ifindex, 
										UINT8 afi, UINT8 add,UINT32 ivid);
bool_t received_clear_grp_notify = FALSE;

void mld_send_l2mcd_sync_group_upd (MADDR_ST *group_address,  UINT16 vir_port_id, 
	int num_add_port, UINT32 add_phy_port_id, int num_del_port, UINT32 del_phy_port_id,
	MADDR_ST  *src_addr, uint8_t is_remote_report)
{

}

void mld_send_l2mcd_sync_group_clr (UINT16 ivid, BOOLEAN isGlobalClear, uint8_t afi)
{	

}

void mld_send_l2mcd_sync_group_add (MADDR_ST *group_address, UINT16 vir_port_id,
        UINT32 phy_port_id, MADDR_ST  *src_addr, UINT8  filter_mode) 
{
 
}

void igmpv3_send_l2mcd_sync_group_upd (MADDR_ST *group_address, UINT16 vir_port_id, 
	int num_add_port, UINT32 add_phy_port_id, int num_del_port, UINT32 del_phy_port_id,
	MADDR_ST  *src_addr, uint8_t is_remote_report, UINT8  filter_mode)
{

}

void igmpv3_send_l2mcd_sync_group_add (MADDR_ST *group_address, UINT16 vir_port_id,
	UINT32 phy_port_id, MADDR_ST  *src_addr, UINT8  filter_mode)
{

}

void l2mcd_sync_inherit_xg_port_to_all_sg (MCGRP_ENTRY *mcgrp_entry, uint32_t phy_ifindex, uint32_t vid, int add)
{

}

void l2mcd_sync_inherit_xg_ports_to_this_sg (MCGRP_ENTRY *mcgrp_entry, MADDR_ST *src_addr, UINT8 filter_mode, uint32_t vid, int add)
{

}
