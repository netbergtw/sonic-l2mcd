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

#include "l2mcd_mld_port.h"


extern MCGRP_CLASS *g_igmp_destroy;
extern MCGRP_CLASS *g_mld_destroy;

/*	When we receive (*,G) join/prune on a port then here
 *  we according send add/del this port for all (S,G)s in this grp to l2mcsync
 */
void  l2mcd_sync_pims_upd_inherit_ports_to_sg(MCGRP_ENTRY *mcgrp_entry, 
										MCGRP_MBRSHP *rcvd_mbrshp,
										uint32_t vid, uint32_t phy_ifindex, 
										UINT8 afi, UINT8 add,UINT32 ivid)
{

}

BOOLEAN pim_snoop_is_source_present_on_mbr_port(MCGRP_MBRSHP *grp_mbrshp, 
						uint32_t src_addr, uint8_t afi)
{
}

/* This function will include/exclude the current physical port and exclude any other port where S,G RptPrune is received
   for this source. The function adds all ports where IGMP/PIMS *,G joins are received. These are sent 
   as (S,G) add/delete to l2mcsync. The last parameter indicates add/delete option. */
void l2mcd_sync_inherit_and_send_rte(MCGRP_CLASS  *mcgrp, MCGRP_L3IF *mcgrp_vport, 
									   MCGRP_ENTRY *mcgrp_entry, UINT32 phy_port_id, MADDR_ST *src_addr, int add_flag)
{

}

BOOLEAN pims_is_pim_snoop_mbrship(MCGRP_MBRSHP *mcgrp_mbrshp)
{

}

void mcgrp_pims_age_src_mbrshp(MCGRP_CLASS  *mcgrp,
						MCGRP_L3IF *mcgrp_vport,
						MCGRP_ENTRY *mcgrp_entry,
						MCGRP_MBRSHP *mcgrp_mbrshp,
						MCGRP_SOURCE *pims_src_entry)
{

}

MCGRP_SOURCE* mcgrp_pims_find_src_node_by_addr (MCGRP_CLASS  *mcgrp,
											MCGRP_MBRSHP *mcgrp_mbrshp,
											MADDR_ST *src_addr)
{

}

void mcgrp_pims_sorted_linklist_del_element(MCGRP_GLOBAL_CLASS *mcgrp_glb,
								MCGRP_CLASS  *mcgrp, MCGRP_MBRSHP *mcgrp_mbrshp,
								MADDR_ST *src_addr)
{
}


