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
#include "l2mcd_mld_port.h"
#include "l2mcd_mld_utils.h"
#include "l2mcd_dbsync.h"


#define PREFIX_LIST_NAME_LEN 32 //256
extern MCAST_GLOBAL_CLASS    gMulticast, *pgMulticast;
extern L2MCD_AVL_TREE *mld_portdb_tree;
extern L2MCD_AVL_TREE *ve_mld_portdb_tree;

const static char mcgrp_action_label[][8] =
{
    "NONE",
    "IS_INCL",
    "IS_EXCL",
    "TO_INCL",
    "TO_EXCL",
    "ALW_NEW",
    "BLK_OLD"
};


MADDR_ST global_source_ip; // Who sends this packet ??

UINT8 igmp_eval_version(IGMP_MESSAGE *sptr_igmp_message, UINT16 igmp_packet_size)
{
    UINT8   igmpver = 0;

    switch(sptr_igmp_message->type)
    {
        case IGMP_MEMBERSHIP_QUERY_TYPE:
            IGMP_EVAL_QUERY_VERSION(igmpver, sptr_igmp_message->maximum_response_time, igmp_packet_size);
            break;

        case IGMP_V1_MEMBERSHIP_REPORT_TYPE:
            igmpver = IGMP_VERSION_1;
            break;

        case IGMP_V2_MEMBERSHIP_REPORT_TYPE:
        case IGMP_V2_LEAVE_GROUP_TYPE:
            igmpver = IGMP_VERSION_2;
            break;

        case IGMP_V3_MEMBERSHIP_REPORT_TYPE:
            igmpver = IGMP_VERSION_3;
            break;

        default:
            igmpver = 0;
            break;
    }

    return igmpver;
}

enum BOOLEAN igmp_check_valid_range(UINT32  group_address)
{
    // Addresses 224.0.0/24 are reserved for various control protocols
    // and hence are not valid multicast group addresses

    if ((group_address >= 0xe0000100) && (group_address <= 0xefffffff))
        return TRUE;
    else
        return FALSE;
}

enum BOOLEAN igmp_check_if_checksum_is_valid (IGMP_MESSAGE  *sptr_igmp_message, 
        USHORT message_size)
{
    UINT16 calculated_checksum;

    /* calculate checksum for the whole IGMP message */

    if (sptr_igmp_message->checksum != 0x0000)
    {
        calculated_checksum = calculate_ip_checksum (NULL, (BYTE *) sptr_igmp_message, message_size);

        if (calculated_checksum != 0x0000)
        {
            return (FALSE);
        }
    }
    return (TRUE);
}

void igmp_warn_version_mismatch(MCGRP_PORT_ENTRY* igmp_pport, 
        UINT32 rxver, UINT32 src_addr)
{

}

void igmp_warn_ssm_lower_ver_querier(MCGRP_PORT_ENTRY* igmp_pport, 
        UINT32 src_addr, UINT8 rxver)
{

}

/*-------------------------------------------------------------------------------**
 ** This function is called when a query request is received from another router. **
 ** It checks whether it is IGMP V1 query, if it is then it does nothing.         **
 ** Otherwise  it checks if we need to becomes querier, or whether the state of   **
 ** the group address entry in table need to be changed.                          **
 **-------------------------------------------------------------------------------*/
void igmp_process_query(MCGRP_CLASS *igmp,
        UINT16         vir_port_id,
        UINT32        phy_port_id,
        UINT32         group_address,
        IGMP_MESSAGE* igmp_msg,
        UINT16        igmp_msg_sz,
        UINT32         clnt_src_ip)
{


}

void igmp_process_v3_report (MCGRP_CLASS    *igmp, 
        IGMPV3_REPORT  *igmpv3_rep,
        UINT32 len_report,
        UINT16 vir_port_id,
        UINT32 phy_port_id,
        UINT32 clnt_src_ip)
{
   
}

/*--------------------------------------------------------------------------------**
 ** This function is called from receive_igmp_packet_callback() when we receive an IGMP packet **
 ** Or from mcast_mct_process_message_from_peer() when we receive an IGMP message from **
 ** a remote MCT peer. The function validates the received packet and then calls the correct function **
 ** to process the information extracted from the packet further.                  **
 ** Returns a pointer to the packet if it is to be freed, NULL otherwise.
 **--------------------------------------------------------------------------------*/
int receive_igmp_packet (IP_PARAMETERS  *sptr_ip_parameters)
{

} /* receive_igmp_packet() */


UINT32 ip_get_lowest_ip_address_on_port(UINT16 port_number, uint8_t type)
{

}




BOOLEAN igmp_staticGroup_exists_on_port (IP_ADDRESS  group_addr, 
        PORT_ID     port_id, 
        //PORT_ID phy_port)
        UINT32 phy_port)
{
 
}

BOOLEAN igmp_update_ssm_parameters(MCGRP_CLASS         *mcgrp,
        MADDR_ST             *group_addr,
        UINT8                *version,
        PORT_ID               vir_port_id,
        UINT32                phy_port_id,
        UINT8                *igmp_action,
        UINT16               *num_srcs,
        UINT32               **src_list)
{
   
}

/*---------------------------------------------------------------------------------------**
 ** This function constructs and send  a given IGMP message on a given port. Both IGMP V1 **
 ** and IGMP V2 messages are supported. The type of message constructed depends on the    **
 ** parameters passed.                                                                    **
 **---------------------------------------------------------------------------------------*/
// klin, BUG 8574, the last query use the default 5 seconds response time,
// but we remove the group in 3 second. Thus, we need a non-default response
// time. If response_time=0, we use default.
BOOLEAN igmp_send_igmp_message (MCGRP_CLASS *igmp,
        UINT16          tx_port_number,
        UINT32          physical_port,     // if valid send to this port only, else send to tx_port_number
        UINT8           type,
        UINT8           version,
        UINT32          group_address,     // 0 => general query
        UINT32          source_address,
        UINT16          response_time,     // 0 means use default
        MCGRP_SOURCE*   src_list,
        BOOLEAN         all_srcs,
        BOOLEAN         is_retx
        )
{

}

void igmp_send_general_query( MCGRP_CLASS *igmp, 
        UINT16       tx_port_number,
        //    UINT16       physical_port,
        UINT32       physical_port,
        UINT8        version,
        UINT32       use_src,
        UINT16       response_time)
{

}


typedef struct s_IGMP_CLNT_LV_PARAM
{
    MCGRP_L3IF*        igmp_vport;
    MCGRP_MBRSHP*      igmp_mbrshp;
    UINT32             group_addr;
    SORTED_LINKLIST**  src_list;
    BOOLEAN            was_excl;
    UINT32             clnt_ip_addr;

} IGMP_CLNT_LV_PARAM;


static UINT32 igmp_track_v2_clnt_leave (MCGRP_CLASS         *igmp, 
        IGMP_CLNT_LV_PARAM  *p_param)
{
}

BOOLEAN igmp_send_group_query(MCGRP_CLASS     *igmp, 
        MCGRP_MBRSHP*    igmp_mbrshp,
        UINT16           tx_port_number,
        UINT32           physical_port,
        UINT8            version,
        UINT32           group_address,
        UINT32           src_ip,
        UINT32           clnt_ip_addr,
        BOOLEAN          is_retx)
{
 

    
}

static UINT32 igmp_track_v3_clnt_leave(MCGRP_CLASS *igmp, 
        IGMP_CLNT_LV_PARAM* p_param)
{

}



BOOLEAN igmpv3_send_group_source_query(MCGRP_CLASS        *igmp, 
        MCGRP_MBRSHP       *igmp_mbrshp,
        UINT16              vir_port_id,
        UINT32              phy_port_id,
        UINT32              group_address,
        SORTED_LINKLIST**   p_src_list,
        BOOLEAN             was_excl,
        UINT32              clnt_ip_addr,
        BOOLEAN             is_retx)
{

}
