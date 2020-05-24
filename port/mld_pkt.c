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
#include "l2mcd_portdb.h"
#include "mld_vlan_db.h"
#include "l2mcd.h"
#include <linux/if_packet.h>
#include <linux/if_ether.h>
#include <sys/socket.h>
#include <errno.h>


extern int l3_get_port_from_ifindex(int ifindex);
extern L2MCD_AVL_TREE *ve_mld_portdb_tree;
extern uint32_t hsl_sock_fd[MCAST_AFI_MAX];
#define HSL_ETHER_TYPE_IP                  0x0800
#define HSL_ETHER_TYPE_IPV6                0x86DD
#define AF_IGMP_SNOOP 51
#define AF_MLD_SNOOP 59

#define VLAN_HDR_LEN 4
#define ETH_ADDR_LEN 6

extern MCGRP_ROUTER_ENTRY* mcgrp_find_rtr_port_entry (MCGRP_CLASS  *mcgrp,
                                             MCGRP_L3IF   *mcgrp_vport,
                                             UINT32        phy_port_id);

extern L2MCD_AVL_TREE *mld_portdb_tree;

int mld_ok_to_send_over_edge_port(ifindex_t source, ifindex_t destination)
{
	if(source == destination)
		return FALSE;
    else 
		return TRUE;
}

/* 	This function will prepare a IGMP report and send it over mrouter port. This is needed because
	we want to send the static IGMP report over mrouter ports.
	Parameters:
		grp_addr 	: Static group Ip address
		mld 		: instance class
		mld_vport	: Vlan Instance in IGMP
		rx_phy_port	: Port-Id of the port where static group is configured
		joinflag	: Boolean flag, TRUE: Join, FALSE: Leave
	Note: Currently, this function supports only IPV4.
*/
void mld_tx_static_report_leave_on_mrtr_port(MCGRP_CLASS  *mld, MADDR_ST *grp_addr, MCGRP_L3IF *mld_vport, 
											 uint32_t rx_phy_port, uint8_t joinflag)
{

}

void mld_tx_reports_leave_rcvd_on_edge_port(void *req, MADDR_ST *grp_addr, MCGRP_CLASS  *mld, MCGRP_L3IF *mld_vport)
{

}

int l2mcd_send_pkt(void *msg, ifindex_t phy_port_id, uint16_t ivid, 
					MADDR_ST *grp_addr, 
					MCGRP_CLASS *mld, 
					MCGRP_GLOBAL_CLASS  *mcgrp_glb, 
					bool_t is_forwarded, bool_t is_bcast)
{
  
}


