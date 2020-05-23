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
#include "l2mcd_mld_port.h"
#include "l2mcd_portdb.h"
#include "mld_vlan_db.h"

#define ALL_PIM_ROUTERS_SSM_PRECEDENCE 2 

extern L2MCD_AVL_TREE *mld_portdb_tree;

int linklist_delete_pointer(LINKLIST_TYPE **head, LINKLIST_TYPE *item)
{
    LINKLIST_TYPE *prev, *p;

    if(*head == NULL)
        return 0;
    p = *head;
    if(p == item) // It is the first one, must change head
    {
        *head = p->next;
        return 1;
    }
    prev = p;
    p = p->next;
    while(p)
    {
        if(p == item)
        {   // match
            prev->next = p->next;
            return 1;
        }
        prev = p;
        p = p->next;
    }
    return 0; // not found
}

int32_t mld_get_port_num(uint16_t port)
{
	return -1;
}

uint16_t mld_l3_get_port_from_ifindex(uint32_t ifindex, uint8_t type)
{


}

uint32_t mld_get_port_ifindex(uint16_t port_id)
{

}

uint32_t mld_get_vlan_id(uint16_t vir_port_id)
{

}

uint32_t mld_get_ivid_vport(uint16_t vir_port_id, uint8_t afi) 
{

}

uint8_t  mld_get_vlan_type(uint16_t ivid)
{

}

char * mld_get_if_name_from_ifindex(uint32_t ifindex)
{

}

int l3_get_max_ports(void)
{
    return MAX_L3_PORTS;
}

void mld_get_ifname(char *if_name, int if_type, char *comp_if_name)
{
     memcpy(comp_if_name, if_name,INTERFACE_NAMSIZ);
    return;
}

uint32_t mld_get_lif_ifindex_from_ifname(char *ifname, uint32_t gvid, uint8_t vlan_type) 
{

}

int mld_get_port_bitmap_size()
{
    return 0;
}

PORT_ID mcast_tnnl_get_output_port (PORT_ID tnnl_ifid)
{
    return 0;
}

int ip_get_number_of_phy_ports(void)
{
    return 0;
}

uint32_t  mld_mcast_tnnl_get_output_ifindex(uint16_t vir_port_id)
{

}

uint32_t  mld_mcast_tnnl_get_output_port(uint32_t ifindex) 
{

}
