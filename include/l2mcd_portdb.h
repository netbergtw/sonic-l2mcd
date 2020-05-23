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
#ifndef __L2MCD_PORTDB__
#define __L2MCD_PORTDB__

#include "l2mcd_data_struct.h"
#include "hash_grow_generic.h"
#include "l2mcd_mld_port.h"
#include "l2mcd.h"
#include "l2mcd_mcast_co.h"

#define MAC_ADDR_LEN 6
#define PORTDB_DEFAULT_PORT_MTU     1500
#define PORTDB_DEFAULT_PORT_TYPE    1



typedef struct PORTDB_IP6_ADDRESS_ENTRY_S {
    struct PORTDB_IP6_ADDRESS_ENTRY_S   *sptr_forward_link;
    IP6_IPV6_ADDRESS                    address; 
    IP6_IPV6_ADDRESS                    prefix; 
    UINT8                               prefix_length;
    UINT8                               flags;
} PORTDB_IP6_ADDRESS_ENTRY;

typedef struct PORTDB_IP6_S {
    /* ip6_enabled is enabled if address is configured or  ip6_protocol_enabled is set. */
    UINT16             ip6_protocol_enabled:1; /* enable ipv6 interface, even if address is not configured */
    UINT16             spare:15; 
    UINT8              number_of_ip6_addresses;
    PORTDB_IP6_ADDRESS_ENTRY *sptr_ip6_link_local_address; //Link Local Address
    PORTDB_IP6_ADDRESS_ENTRY *sptr_ip6_address_list; //Global Address
} PORTDB_IP6;



typedef struct portdb_entry_s {
    L2MCD_AVL_NODE         node;
    unsigned int        port_index;
    unsigned long       ifindex;
    VRF_INDEX           vrf_id;
    unsigned int        mtu;
    unsigned int        ipv6_mtu;
    unsigned long       ivid;
    unsigned long       gvid;        
    float               bandwidth;
    float               bw_configured; /* Configured bw value; (when not configured) overloaded with full trunk bw irrespective of active portlist */
	UINT8               hwAddr[6];
    UINT16              port_state:1;
    UINT16              ip6_enabled:1; /* Current Enabled/Disabled state for processing IP6 packet */
    UINT16              ip4_enabled:1; /* Current Enabled/Disabled state for processing IP4 packet */
    UINT16              type:3;        /* interface type : NSM_INTF_MODE_UNK/NSM_INTF_MODE_L2/NSM_INTF_MODE_L3 */
                                       /* this follows nsm_intf_type_new_s
                                        * ENUM which will take upto a value of
                                        * '4'; hence 3 bits are needed.*/
    UINT16              netdev_state:1; /* Indicates the interface got netdevice is created or not */
    UINT16              admin_state:1;
    UINT16              unnumbered:1;  /* Indicates if the interface is unnumbered interface*/
    UINT16              neighbor_up:1; /* Indicates if neighbor is discovered on the unnumbered interface */
    UINT16              spare:6; 

    PORTDB_IP6          *ip6;
    struct list			*ip4;
	// Fusion ISIS: Store MAC for easier SYNC to standby
	u_char              mac_addr[MAC_ADDR_LEN];
    void                *opaque_data; 
} portdb_entry_t;

typedef struct PORTDB_IP4_S {
    L2MCD_AVL_NODE     node;
    UINT32          ipaddress;
    VRF_INDEX       vrf_index;
    UINT8           prefix_length;
    UINT32          flags;
    UINT32          port_index;
    UINT8           mac[6];
} PORTDB_IP4;

typedef struct port_link_list_s
{
    struct  port_link_list_s *next;
    PORTDB_IP4 value;
}port_link_list_t;


typedef struct PORTDB_VRF_S {
    char            *vrf_name;
    unsigned char   afi;
} portdb_vrf_t;



#endif //__L2MCD_PORTDB__
